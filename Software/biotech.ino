#include <UbidotsEsp32Mqtt.h>
#include <WiFi.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MHZ19.h>
#include <DHT.h>
#include <PubSubClient.h>

#define WIFI_SSID "OPPO A58" //wifi usado para la toma de datos en la Av. Habich
#define WIFI_PASSWORD "f3gxaywa" 

const char *UBIDOTS_TOKEN = "BBUS-bSORwixPyOEbC5zoyzafMtbAf9NCuS"; // Plataforma Ubidots
const char *DEVICE_LABEL = "esp32tempco2";

const char *VARIABLE_LABEL_1 = "tempubidots";
const char *VARIABLE_LABEL_2 = "co2ubidots";

const int PUBLISH_FREQUENCY = 5000;

Ubidots ubidots(UBIDOTS_TOKEN);

// Definicion pines y parametros
#define RX2_PIN 16 // Pin Rx, al que se conecta el pin Tx de MHZ19
#define TX2_PIN 17 // Pin Tx, al que se conecta el pin Rx de MHZ19
#define BAUDRATE 9600 // Velocidad de la comunicacion serie del MHZ19

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Instancia
MHZ19 myMHZ19;

// Crear comunicacion serie MH-Z19 - esp32
SoftwareSerial mySerial(RX2_PIN, TX2_PIN);

// Variables
int CO2; // Nivel de CO2 medido por el sensor
int8_t Temp; // Temperatura medida por del sensor

int co2_calib; // Punto cero de calibracion
unsigned long timeCalib; // Tiempo de inicio de la calibración (ms)
unsigned long timeElapse = 12e5; // 20mins para la calibracion (ms)
bool calibrado; // Comprobar el envio de valor co2_calib a IoT

int t_fin_cal = 18e4; // 3min calentamiento sensor (ms)
int t_ini_cal; // Tiempo de inicio del sensor (ms)

unsigned long timer;

String formattedDate;
String dayStamp;
String timeStamp;

//#definir SD_CS 5

//WiFiUDP ntpUDP; 
//NTPClient timeClient(ntpUDP);

void setup(){
  // Velocidad de transmision del puerto serie con el ordenador
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Conectando a la red WiFi");
  dht.begin();

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Conectando a la red WiFi");
  }

  Serial.println("Conexión WiFi establecida. Dirección IP: ");
  Serial.println(WiFi.localIP());

  ubidots.connectToWifi(WIFI_SSID, WIFI_PASSWORD);
  ubidots.setup();
  ubidots.reconnect();
  timer=millis();
  iniciarSensor();
  calibrarSensor(false);
  esperarFinCalentamiento();
}

void loop() {
  // Obtener datos cada cierto tiempo
  if (abs(static_cast<long int>(millis() - timer)) > PUBLISH_FREQUENCY) // triggers the routine every 5 seconds
  {
    // Realizar mediciones
    CO2 = myMHZ19.getCO2(false); // Pedir CO2 (ppm)
    Serial.print("CO2 (ppm): ");
    Serial.println(CO2);
    Temp = dht.readTemperature(); // Pedir Temperatura (Celsius)
    Serial.print("Temperatura (°C): ");
    Serial.println(Temp);

    // Publicar mediciones en Ubidots
    if (!ubidots.connected()) {
      ubidots.reconnect();
    }

    ubidots.add(VARIABLE_LABEL_1, Temp);
    ubidots.add(VARIABLE_LABEL_2, CO2);
    ubidots.publish(DEVICE_LABEL);

    // Reiniciar el temporizador
    timer = millis();
  }

  // Mantener la conexión con Ubidots
  ubidots.loop();
}

void iniciarSensor() {
  mySerial.begin(BAUDRATE); // Iniciar el puerto serie del micro
  myMHZ19.begin(mySerial); // Pasar referencia del puerto serie a la libreria del sensor
  myMHZ19.autoCalibration(true); // Activar calibracion automatica
  t_ini_cal = millis();
}

void calibrarSensor(bool calibrar) {
  // Se inicia la calibracion cuando entre un valor true
  if (calibrar == true) {
    myMHZ19.autoCalibration(false); // Apagar calibración automática
    Serial.println("Esperando 20 minutos para calibrarse...");
    timeCalib = millis(); // Tiempo inicio calibracion (ms)
    co2_calib = myMHZ19.getCO2(); // Primera medida de calibración

    bool mj20 = false;
    bool mj15 = false;
    bool mj10 = false;
    bool mj05 = false;

    while ((millis() - timeCalib) < timeElapse) {
      if ((millis() - timeCalib) < 3e5) {
        if (!mj20) {
        Serial.println("Esperar 20 minutos");
        mj20 = true;
        }
      }
      else if ((millis() - timeCalib) < 6e5) {
        if (!mj15) {
          Serial.println("Esperar 15 minutos");
          mj15 = true;
        }
      }
      else if ((millis() - timeCalib) < 9e5) {
        if (!mj10) {
          Serial.println("Esperar 10 minutos");
          mj10 = true;
          }
      }
      else if ((millis() - timeCalib) < 12e5) {
        if (!mj05) {
          Serial.println("Esperar 5 minutos");
          mj05 = true;
          }
      }

      int nuevo_co2 = myMHZ19.getCO2();
        if (nuevo_co2 < co2_calib && nuevo_co2 != 0) {
          co2_calib = nuevo_co2;
          delay(5000); // Maxima tasa de toma de datos
          }
    }

    Serial.println("Calibrando..");
    myMHZ19.calibrate(); // Obtener una lectura para valor cero
    delay(2000);
    Serial.println("CO2 de punto cero (ppm): ");
    Serial.println(co2_calib);
    calibrado = true;
    myMHZ19.autoCalibration(true); // Reiniciar calibración automática
    }
}

void esperarFinCalentamiento() {
  Serial.println("Iniciando calentamiento...");
  Serial.println("Tiempo estimado de 3 minutos");
  delay(t_fin_cal); // Espera los 3 minutos de calentamiento
  Serial.println("Fin del calentamiento. Iniciando mediciones.");
}