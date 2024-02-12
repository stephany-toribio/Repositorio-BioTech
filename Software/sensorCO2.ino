#include <Wire.h>
#include <SoftwareSerial.h>
#include <MHZ19.h>

// Definicion pines y parametros
#define RX2_PIN 16 // Pin Rx, al que se conecta el pin Tx de MHZ19
#define TX2_PIN 17 // Pin Tx, al que se conecta el pin Rx de MHZ19
#define BAUDRATE 9600 // Velocidad de la comunicacion serie del MHZ19

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

unsigned long tm_ms = 5000; // Tiempo de muestreo del sensor (ms)
unsigned long getDataTimer = 0; // Almacenar el último dato leido (ms)

void setup() {
 // Velocidad de transmision del puerto serie con el ordenador
  Serial.begin(115200);
  iniciarSensor();
  calibrarSensor(true);
  esperarFinCalentamiento();
}

void loop() {
  // Obtener datos cada tm_ms
  if (millis() - getDataTimer >= tm_ms)
  // millis() = tiempo desde que se inicio el microcontrolador
  {
    CO2 = myMHZ19.getCO2(false); // Pedir CO2 (ppm)
    Serial.print("CO2 (ppm): ");
    Serial.println(CO2);
    Temp = myMHZ19.getTemperature(); // Pedir Temperature (Celsius)
    Serial.print("Temperatura (C): ");
    Serial.println(Temp);
    getDataTimer = millis();
  }
}

void iniciarSensor() {
  mySerial.begin(BAUDRATE); // Iniciar el puerto serie del micro
  myMHZ19.begin(mySerial); // Pasar referencia del puerto serie a la libreria del sensor
  myMHZ19.autoCalibration(true); // Activar calibracion automatica
  t_ini_cal = millis();
}

void realizarMedicion() {
  CO2 = myMHZ19.getCO2(false); // Pedir CO2 (ppm)
  Serial.print("CO2 (ppm): ");
  Serial.println(CO2);
  Temp = myMHZ19.getTemperature(); // Pedir Temperature (Celsius)
  Serial.print("Temperatura (C): ");
  Serial.println(Temp);
}

void calibrarSensor(bool calibrar) {
  // Se inicia la calibracion cuando entre un valor true
  if (calibrar == true) {
    myMHZ19.autoCalibration(false); // Apagar calibración automática
    Serial.println("Esperando 20 minutos para calibrarse...");
    timeCalib = millis(); // Tiempo inicio calibracion (ms)
    co2_calib = myMHZ19.getCO2(); // Primera medida de calibración

    while ((millis() - timeCalib) < timeElapse) {
      if ((millis() - timeCalib) < 3e5) {
        Serial.println("Esperar 20 minutos");
      }
      else if ((millis() - timeCalib) < 6e5) {
          Serial.println("Esperar 15min");
      }
      else if ((millis() - timeCalib) < 9e5) {
          Serial.println("Esperar 10min");
      }
      else if ((millis() - timeCalib) < 12e5) {
          Serial.println("Esperar 5min");
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
  delay(t_fin_cal); // Espera los 3 minutos de calentamiento
  Serial.println("Fin del calentamiento. Iniciando mediciones.");
}
