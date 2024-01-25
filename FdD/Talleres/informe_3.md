<p align="left">
  <img src="https://seeklogo.com/images/U/u-cayetano-heredia-logo-CA435ADF8C-seeklogo.com.png" width="300">
  <h1 align="center">Explore IoT</h1>
</p>

<strong>Docentes:</strong>
- Mg Umbert Lewis De La Cruz
- Mg. Paulo Camilo Vela Antón 
- Dr. Harry Anderson Rivera Tito  
- Ing. Renzo José Chan Ríos
- Ing. Juan Manuel Zuñiga Mamani 
- Mg. Moises Stevend Meza Rodriguez

<strong>Integrantes:</strong>
- Mishell Camila Maravi Melgar
- John Jairo Rodriguez Aguirre
- Stephany Marilyn Toribio Alvarado
- Stefano Jesús Ortega Herencia

## Introducción

El internet de las cosas, en la era digital actual, ha consolidado su posición como una revolución tecnológica que redefine la interconexión de dispositivos en nuestra vida cotidiana. Este concepto implica la interconexión de objetos físicos a través de la red, permitiéndoles compartir información y llevar a cabo tareas de manera autónoma; desde la integración de electrodomésticos inteligentes hasta la implementación de sensores avanzados, el IoT ha impregnado varios aspectos de nuestra realidad, forjando un panorama digital en constante evolución.

<p align="center"><strong>Figura 1: Internet de las cosas (IoT)</strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/IoT-2.jpg" width="700" height="300"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 1. Dynamo IOT (2021) La tecnología IoT reemplazará el sistema de rastreo GPS? https://dynamoiot.com/la-tecnologia-iot-reemplazara-el-sistema-de-rastreo-gps/</p>

## Importancia del  IoT

La importancia del Internet de las Cosas (IoT) radica en su capacidad para transformar nuestra interacción con el entorno y la comunicación entre máquinas, las cuales la recopilan, análizan y actúann en base a la información que generan. 
Esto se refleja en la mejora de la eficiencia y optimización de procesos industriales, la creación de hogares inteligentes que simplifican la vida diaria, la promoción de la sostenibilidad mediante la reducción de costos operativos, y el avance hacia una atención médica más personalizada. El IoT no solo impacta la industria y el hogar, sino que también transforma sectores completos, desde la fabricación hasta la agricultura, y contribuye a la evolución de ciudades inteligentes mediante la monitorización en tiempo real.

## Materiales

Explore IoT Kit 
  - Arduino MKR WiFi 1010
  - MKR IoT Carrier
  - Micro USB cable
  - Sensor de movimiento PIR + cable

## Ensamblado

Inicialmente, llevamos a cabo el proceso de ensamblaje de los componentes siguiendo las instrucciones proporcionadas en los videos de la lección sobre Internet de las Cosas. El resultado obtenido se muestra a continuación *(Figura 2)*. Este paso es fundamental para asegurar que todas las funcionalidades de la MKR IoT Carrier puedan ser aprovechadas. 

<p align="center"><strong>Figura 2: Ensamblado de componentes</strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/armado_arduino.jpeg" width="450" height="430"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 2. Ensamblado de componentes - Explore IoT (Fundamentos de Diseño 2024-0). Elaboración propia.</p>

## Actividades 

### Actividad 1: Ejecutar el código para la lectura de temperatura y humedad de la sección "Conoce el Kit"

Para la actividad 1, en un principio, abrimos el Editor Online de Arduino, donde creamos un sketch para construir gradualmente el código que nos proporcionaría los datos de temperatura y humedad del sensor HTS221. Sin embargo, durante la ejecución del código, nos enfrentamos a inconvenientes técnicos al intentar incorporar la biblioteca necesaria, debido a esto, decidimos trabajar en el Software: Arduino IDE para poder cumplir con lo asignado.

```cpp 
#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;
 
float temperature = 0;
float humidity = 0;
 
void setup() {
  Serial.begin(9600);
  //Wait to open the Serial monitor to start the program and see details on errors
  
 
  //Set if it has the Enclosure mounted
  CARRIER_CASE = true;
  //Initialize the IoTSK carrier and output any errors in the serial monitor
  carrier.begin();
}

void loop() {
  // read the sensor values
  temperature = carrier.Env.readTemperature();
  humidity = carrier.Env.readHumidity();
 
  //Update touch buttons
  carrier.Buttons.update();
 
  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" Â°C");
 
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");
 
  //function to print out values
  if (carrier.Buttons.onTouchDown(TOUCH0)) {
    printTemperature();
  }
 
  if (carrier.Buttons.onTouchDown(TOUCH1)) {
    printHumidity();
  }
}

void printTemperature() {
  //configuring display, setting background color, text size and text color
  carrier.display.fillScreen(ST77XX_RED); //red background
  carrier.display.setTextColor(ST77XX_WHITE); //white text
  carrier.display.setTextSize(6); //large sized text
 
  carrier.display.setCursor(30, 50); //sets position for printing (x and y)
  carrier.display.print("Temp: ");
  carrier.display.setTextSize(4); //decreasing text size
  carrier.display.setCursor(40, 120); //sets new position for printing (x and y)
  carrier.display.print(temperature);
  carrier.display.print(" C");
}
 
void printHumidity() {
  //configuring display, setting background color, text size and text color
  carrier.display.fillScreen(ST77XX_BLUE); //red background
  carrier.display.setTextColor(ST77XX_WHITE); //white text
  carrier.display.setTextSize(2); //medium sized text
 
  carrier.display.setCursor(20, 110); //sets position for printing (x and y)
  carrier.display.print("Humi: ");
  carrier.display.print(humidity);
  carrier.display.println(" %");
}
```
Realizamos una modificación en la variable `CARRIER_CASE` = false a `CARRIER_CASE` = true, debido a que estábamos utilizando la MKR IoT Carrier dentro de la caja de plástico.

```cpp 
void setup() {
  Serial.begin(9600);
  
  CARRIER_CASE = true;
  carrier.begin();
}
```
Para una mejor visualizacion en el DISPLAY se hicieron como modificaciones el tamaño de la letra y la ubicación del cursor para el texto en las funciones printTemperature() y printHumidity().

```cpp
void printTemperature() {
  //configuring display, setting background color, text size and text color
  carrier.display.fillScreen(ST77XX_RED); //red background
  carrier.display.setTextColor(ST77XX_WHITE); //white text
  carrier.display.setTextSize(6); //large sized text
 
  carrier.display.setCursor(30, 55); //sets position for printing (x and y)
  carrier.display.print("Temp: ");
  carrier.display.setTextSize(4); //decreasing text size
  carrier.display.setCursor(40, 120); //sets new position for printing (x and y)
  carrier.display.print(temperature);
  carrier.display.print(" C");
}
 
void printHumidity() {
  //configuring display, setting background color, text size and text color
  carrier.display.fillScreen(ST77XX_BLUE); //red background
  carrier.display.setTextColor(ST77XX_WHITE); //white text
  carrier.display.setTextSize(4); //medium sized text
 
  carrier.display.setCursor(20, 110); //sets position for printing (x and y)
  carrier.display.print("Humi: ");
  carrier.display.print(humidity);
  carrier.display.println(" %");
}
```
El código modificado se ejecutó de manera satisfactoria. A continuación, se presenta el desempeño idóneo de la presente actividad, mostrando los valores de temperatura y humedad.

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 3: Visualización de la temperatura del laboratorio.</strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/temp.jpeg" width="360" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: Figura 3. Visualización de la temperatura del laboratorio - Explore IoT (Fundamentos de Diseño 2024-0). Elaboración propia.</p>
        </td>  
        <td style="border: 0px">
        <p align="center"><strong>Figura 4: Visualización de la humedad del laboratorio.</strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/humed.png" width="360" height="300">
        <p align="center" class="note text-center note-white">FUENTE: Figura 3. Visualización de la humedad del laboratorio - Explore IoT (Fundamentos de Diseño 2024-0). Elaboración propia.</p>
        </td>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 5: </strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/desemp1.jpeg" width="360" height="300">
        <p align="center" class="note text-center note-white">FUENTE: Figura 3. Desempeño de la Act1 - Explore IoT (Fundamentos de Diseño 2024-0). Elaboración propia.</p>
        </td>      
</table>

### Actividad 2: Desafio - Conversión de la temperatura registrada por el sensor al sistema de unidades Kelvin y Fahrenheit.

El desafío asignado consistió en la implementación de la temperatura registrada por el sensor a otro sistema de unidades (Kelvin y Fahrenheit). Este desafío se abordó mediante la extensión del código ya existente, incluyendo funciones específicas para realizar las conversiones necesarias, a continuación detallamos cada una de ellas:

En este fragmento de código, registra la temperatura actual en grados Celsius en la variable `temperature`, y se almacenan las conversiones a grados Fahrenheit y Kelvin en las variables `temperatureFh` y `temperatureKv`, respectivamente. Además, se actualiza el estado de los botones táctiles para detectar interacciones del usuario y verifica si el botón táctil `TOUCH0`, `TOUCH2` o `TOUCH3` ha sido presionado para mostrar información detallada sobre la temperatura en diversas unidades.

```cpp
void loop() {
  temperature = carrier.Env.readTemperature();
  temperatureFh = carrier.Env.readTemperatureFh();
  temperatureKv = carrier.Env.readTemperatureKv();

  carrier.Buttons.update();
 
  if (carrier.Buttons.onTouchDown(TOUCH0)) {
    printTemperature();
    }
  if (carrier.Buttons.onTouchDown(TOUCH2)) {
    printTemperatureFh();;
    }
  if (carrier.Buttons.onTouchDown(TOUCH3)) {
    printTemperatureKv();
    }
}
```

En estas funciones, se realiza la conversión de la temperatura en grados Celsius almacenada en la variable `temperature` a grados Fahrenheit (`temperatureFh`) y Kelvin (`temperatureKv`). Luego, se actualiza la pantalla para mostrar las temperaturas convertidas en grados Fahrenheit y Kelvin, respectivamente. Se destaca la interacción con el botón táctil `TOUCH0`.

```cpp
void printTemperatureFh() {
  temperatureFh = (9/5) * temperature + 32;
  carrier.display.fillScreen(ST77XX_RED); 
  carrier.display.setTextColor(ST77XX_WHITE); 
  carrier.display.setTextSize(6); 
 
  carrier.display.setCursor(30, 50); 
  carrier.display.print("Temp: ");
  carrier.display.setTextSize(4); 
  carrier.display.setCursor(40, 120); 
  carrier.display.print(temperatureFh);
  carrier.display.print(" °F");
}

void printTemperatureKv() {
  temperatureKv = temperature + 273.15;
  carrier.display.fillScreen(ST77XX_RED); 
  carrier.display.setTextColor(ST77XX_WHITE); 
  carrier.display.setTextSize(6); 
 
  carrier.display.setCursor(30, 50); 
  carrier.display.print("Temp: ");
  carrier.display.setTextSize(4); 
  carrier.display.setCursor(40, 120);
  carrier.display.print(temperatureKv);
  carrier.display.print(" °K");
}
```

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 6: Temperatura en grados Fahrenheit del laboratorio</strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/fh.png" width="370" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: Figura 6. Temperatura en grados Fahrenheit del laboratorio - Explore IoT (Fundamentos de Diseño 2024-0). Elaboración propia.</p>
        </td>  
        <td style="border: 0px">
        <p align="center"><strong>Figura 7: Temperatura en grados Kelvin del laboratorio</strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/kelvin.jpg" width="350" height="320">
        <p align="center" class="note text-center note-white">FUENTE: Figura 7. Temperatura en grados Kelvin del laboratorio - Explore IoT (Fundamentos de Diseño 2024-0). Elaboración propia.</p>
        </td>      
</table>

### Actividad 3: Sensor PIR

Para esta tarea, se realizó la conexión del Sensor de Movimiento PIR a la placa de desarrollo. 
El objetivo principal fue desarrollar un código que permitiera al sensor detectar la presencia de un cuerpo a una distancia específica. Cuando el sensor identificara la proximidad, se activaría un zumbador (buzzer). Finalmente, incorporamos una extensión al código que posibilita el cambio de color de los LEDs RGB en función de la temperatura ambiente. En situaciones de frío, los LEDs se iluminarán en tonalidades azules; mientras que en entornos cálidos, adoptarán tonos rojos.

El fragmento de código permite detectar la presencia de movimiento mediante el sensor PIR. La variable `motionDetected` se inicializa en `false` que se utilizará para almacenar el estado de detección de movimiento y `pirPin` como entrada para conectarse a un sensor de movimiento PIR. 

```cpp
const int pirPin = A5; 
bool motionDetected = false;
 
void setup() {
  Serial.begin(9600);

  CARRIER_CASE = true;
  carrier.begin();
  pinMode(pirPin, INPUT);
}
```

Si se detecta movimiento (`motionDetected` es `true`), se activa un zumbador mediante la función `activateAlarm()`. Posteriormente, se verifica si la temperatura (`temperature`) supera los 30 grados Celsius, en cuyo caso, se iluminan los LEDs con un color rojo. Caso contrario, se iluminan de un color azul. 

```cpp
void loop() {if (motionDetected) {
    activateAlarm();
  }

  if (temperature > 30) {
    carrier.leds.setPixelColor(0, 255, 0, 0);
    carrier.leds.setPixelColor(1, 255, 0, 0);
    carrier.leds.setPixelColor(2, 255, 0, 0);
    carrier.leds.setPixelColor(3, 255, 0, 0);
    carrier.leds.setPixelColor(4, 255, 0, 0);
  } else {
    carrier.leds.setPixelColor(0, 0, 0, 255);
    carrier.leds.setPixelColor(1, 0, 0, 255);
    carrier.leds.setPixelColor(2, 0, 0, 255);
    carrier.leds.setPixelColor(3, 0, 0, 255);
    carrier.leds.setPixelColor(4, 0, 0, 255);
  }
    carrier.leds.show(); 
}
```

La función `activateAlarm()` se encarga de activar el zumbador (buzzer). Para lograr esto, emite un sonido mediante `carrier.Buzzer.sound(500)`, espera 500 milisegundos con `delay(500)`, luego desactiva el sonido con `carrier.Buzzer.noSound()` y espera nuevamente 500 milisegundos antes de retornar. 

```cpp
void activateAlarm() {
  carrier.Buzzer.sound(500);  
  delay(500);
  carrier.Buzzer.noSound();  
  delay(500);
}
```

**Video de desempeño disponible en:** https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/Videos/Buzzer.mp4

## Código completo de las Actividades

```cpp
#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

float temperature = 0;
float humidity = 0;

const int pirPin = A5;
bool motionDetected = false;
void setup()
{
    Serial.begin(9600);

    CARRIER_CASE = true;
    carrier.begin();
    pinMode(pirPin, INPUT);
}

void loop()
{
    temperature = carrier.Env.readTemperature();
    temperatureFh = carrier.Env.readTemperatureFh();
    temperatureKv = carrier.Env.readTemperatureKv();
    humidity = carrier.Env.readHumidity();

    motionDetected = digitalRead(pirPin) == HIGH;
    carrier.Buttons.update();

    if (carrier.Buttons.onTouchDown(TOUCH0))
    {
        printTemperature();
    }
    if (carrier.Buttons.onTouchDown(TOUCH1))
    {
        printHumidity();
    }
    if (carrier.Buttons.onTouchDown(TOUCH2))
    {
        printTemperatureFh();
        ;
    }
    if (carrier.Buttons.onTouchDown(TOUCH3))
    {
        printTemperatureKv();
    }

    if (motionDetected)
    {
        activateAlarm();
    }

    if (temperature > 30)
    {
        carrier.leds.setPixelColor(0, 255, 0, 0);
        carrier.leds.setPixelColor(1, 255, 0, 0);
        carrier.leds.setPixelColor(2, 255, 0, 0);
        carrier.leds.setPixelColor(3, 255, 0, 0);
        carrier.leds.setPixelColor(4, 255, 0, 0);
    }
    else
    {
        carrier.leds.setPixelColor(0, 0, 0, 255);
        carrier.leds.setPixelColor(1, 0, 0, 255);
        carrier.leds.setPixelColor(2, 0, 0, 255);
        carrier.leds.setPixelColor(3, 0, 0, 255);
        carrier.leds.setPixelColor(4, 0, 0, 255);
    }
    carrier.leds.show();
}

void printTemperature()
{

    carrier.display.fillScreen(ST77XX_RED);
    carrier.display.setTextColor(ST77XX_WHITE);
    carrier.display.setTextSize(6);

    carrier.display.setCursor(30, 55);
    carrier.display.print("Temp: ");
    carrier.display.setTextSize(4);
    carrier.display.setCursor(40, 120);
    carrier.display.print(temperature);
    carrier.display.print(" C");
}

void printTemperatureFh()
{
    temperatureFh = (9 / 5) * temperature + 32;
    carrier.display.fillScreen(ST77XX_RED);
    carrier.display.setTextColor(ST77XX_WHITE);
    carrier.display.setTextSize(6);

    carrier.display.setCursor(30, 50);
    carrier.display.print("Temp: ");
    carrier.display.setTextSize(4);
    carrier.display.setCursor(40, 120);
    carrier.display.print(temperatureFh);
    carrier.display.print(" °F");
}

void printTemperatureKv()
{
    temperatureKv = temperature + 273.15;
    carrier.display.fillScreen(ST77XX_RED);
    carrier.display.setTextColor(ST77XX_WHITE);
    carrier.display.setTextSize(6);

    carrier.display.setCursor(30, 50);
    carrier.display.print("Temp: ");
    carrier.display.setTextSize(4);
    carrier.display.setCursor(40, 120);
    carrier.display.print(temperatureKv);
    carrier.display.print(" °K");
}
void printHumidity()
{

    carrier.display.fillScreen(ST77XX_BLUE);
    carrier.display.setTextColor(ST77XX_WHITE);
    carrier.display.setTextSize(4);

    carrier.display.setCursor(20, 110);
    carrier.display.print("Humi: ");
    carrier.display.print(humidity);
    carrier.display.println(" %");
}

void activateAlarm()
{
    carrier.Buzzer.sound(500);
    delay(500);
    carrier.Buzzer.noSound();
    delay(500);
}

```

## Conclusiones

En conclusión, los experimentos realizados con el kit Explore IoT demostraron como estas tecnologías se encuentran realmente en nuestra vida diaria.

Los problemas técnicos que enfrentamos al escribir el código subrayan lo importante que es ser flexible y resolver problemas cuando trabajamos en proyectos de Internet de las Cosas, además, es crucial tener habilidades prácticas y técnicas para superar este tipo de obstáculos.

La conexión entre el sensor de movimiento PIR y los LEDs que cambian de color resalta lo interesante y atractivo que puede ser el Internet de las Cosasy como estos pueden ayudarnos a crear soluciones más complejas y personalizadas que mejoren nuestra experiencia diaria.


## Bibliografía

- Dynamo IOT (2021) La tecnología IoT reemplazará el sistema de rastreo GPS?. Dynamo IoT https://dynamoiot.com/la-tecnologia-iot-reemplazara-el-sistema-de-rastreo-gps/

- Explore IoT kit (2024). Lección. Internet de las cosas. Explore IoT Kit. https://explore-iot.arduino.cc/iotsk/module/iot-starter-kit/lesson/internet-of-things
