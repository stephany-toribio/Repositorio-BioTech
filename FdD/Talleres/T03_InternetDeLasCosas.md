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
<p align="center" class="note text-center note-white">FUENTE: Figura 1. Dynamo IOT (2021) La tecnología IoT reemplazará el sistema de rastreo GPS? https://dynamoiot.com/la-tecnologia-iot-reemplazara-el-sistema-de-rastreo-gps/ </p>

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
        <p align="center" class="note text-center note-white">FUENTE: Figura 3. propia.</p>
        </td>  
        <td style="border: 0px">
        <p align="center"><strong>Figura 4: Visualización de la humedad del laboratorio.</strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/tink2.jpg" width="360" height="300">
        <p align="center" class="note text-center note-white">FUENTE: Figura 4. propia</p>
        </td>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 5: Evidencias del desempeño de la Actividad 1.</strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/desemp1.jpeg" width="360" height="300">
        <p align="center" class="note text-center note-white">FUENTE: Figura 5. propia.</p>
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
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/ejer2.png" width="370" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: Figura 6. Elaboración propia</p>
        </td>  
        <td style="border: 0px">
        <p align="center"><strong>Figura 7: Temperatura en grados Kelvin del laboratorio</strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/multimetro_2.jpg" width="350" height="320">
        <p align="center" class="note text-center note-white">FUENTE: Figura 7. Elaboración propia.</p>
        </td>      
</table>

### Actividad 3: Sensor PIR

Para esta tarea, se realizó la conexión del Sensor de Movimiento PIR a la placa de desarrollo. 
El objetivo principal fue desarrollar un código que permitiera al sensor detectar la presencia de un cuerpo a una distancia específica. Cuando el sensor identificara la proximidad, se activaría un zumbador (buzzer) y se encenderían los LEDs de color rojo.

Sin embargo, no pudimos cumplir con todos los requisitos de esta actividad debido a las restricciones de tiempo que enfrentamos. A continuación se presenta el código desarrollado y sus funcionalidades:

**Video de desempeño disponible en:** https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/Videos/Buzzer.mp4

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 9: Gráfico proporcionado de la guía</strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/ejer3.png" width="380" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: Figura 9. Ejercicio del curso de Fundamentos de Diseño 2024-0, "Ejercicio nivel dragón".</p>
        </td>  
        <td style="border: 0px">
        <p align="center"><strong>Figura 10: Resultado experimental del multimetro</strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/multimetro_3.jpg" width="400" height="380">
        <p align="center" class="note text-center note-white">FUENTE: Figura 10. Ejercicio del curso de Fundamentos de Diseño 2024-0, "Ejercicio nivel dragón". Elaboración propia.</p>
        </td>      

<p align="center"><strong>Figura 13: Diagrama y resolución del ejercicio</strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/diag4.jpg" width="600" height="500"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 13. Ejercicio del curso de Fundamentos de Diseño 2024-0, "Circuito Divisor de Tensión". Elaboración propia.</p>

### Actividad 4 

Finalmente, incorporamos una extensión al código que posibilita el cambio de color de los LEDs RGB en función de la temperatura ambiente. En situaciones de frío, los LEDs se iluminarán en tonalidades azules; mientras que en entornos cálidos, adoptarán tonos rojos.

<p align="center"><strong>Figura 13: Diagrama y resolución del ejercicio</strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/Videos/Buzzer.mp4" width="600" height="500"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 13. Ejercicio del curso de Fundamentos de Diseño 2024-0, "Circuito Divisor de Tensión". Elaboración propia.</p>

Se despejo de la relación entre las resistencias para el estimado correspondiente y se asigno el valor de 100kΩ a la resistencia 1 (R2) para determinar la resistencia 2 (R2). El resultado de la resistencia 2 (R2) fue 28.2kΩ. Este resultado se validó experimentalmente montando el circuito (Figura 14) en el protoboard para verificar nuestros cálculos con un multímetro (Figura 15), confirmando la precisión del cálculo y la validez del diseño del circuito.

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 14: Circuito en el protoboard</strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/resis4.jpg" width="360" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: Figura 14. Ejercicio del curso de Fundamentos de Diseño 2024-0, "Circuito Divisor de Tensión". Elaboración propia.</p>
        </td>
        <td style="border: 0px"> 
        <p align="center"><strong>Figura 15: Resultado experimental del multimetro</strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/multimetro_4.jpg" width="360" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: Figura 15. Ejercicio del curso de Fundamentos de Diseño 2024-0, "Circuito Divisor de Tensión". Elaboración propia.</p>
        </td>
</table>

El "Circuito Divisor de Tensión" se define como un arreglo de resistencias que divide un voltaje de entrada en una proporción específica. La relación con la Ley de Ohm se establece mediante la proporcionalidad del voltaje en un circuito divisor con la resistencia utilizada.

### Actividad 5

En el ejercicio de reducción de señal, al operar con una fuente de 5V y aplicar la ley de Ohm para calcular la resistencia óptima para el LED, se obtiene un resultado de 300 Ω. Este cálculo se basa en la relación entre la tensión de la fuente, la caída de tensión a través del LED y la corriente que se desea pasar a través del LED.

Al momento de incorporar las resistencias, nos encontramos con la limitación de no disponer de una resistencia con el valor exacto necesario para nuestro circuito. En consecuencia, optamos por utilizar tres resistencias de 220 Ω cada una. La estrategia consistió en conectar dos resistencias en serie y una en paralelo, como se ilustra en la imagen adjunta.

<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/multimetro_4.jpg" width="360" height="300"></p>




Sin embargo, al realizar los cálculos, se obtuvo un valor total de 330 Ω, superando ligeramente el requisito de 300 Ω necesario para el funcionamiento adecuado del LED. Este resultado nos lleva a replantear la configuración de resistencias o a considerar la adquisición de resistencias con valores más precisos para cumplir con las especificaciones del circuito.





### Ejercicios desarrollados en Tinkercad

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 18: Divisor de tensión con potenciómetro en el ejercicio 1</strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/tink1.jpg" width="360" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: Figura 18. Ejercicio de diseño titulado "Ejercicios Nivel Pollito - Gato" elaborado en Tinkercad. Captura de pantalla propia.</p>
        </td>  
        <td style="border: 0px">
        <p align="center"><strong>Figura 19: Divisor de tensión con potenciómetro en el ejercicio 2</strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/tink2.jpg" width="360" height="300">
        <p align="center" class="note text-center note-white">FUENTE: Figura 19. Ejercicio de diseño titulado "Ejercicios Nivel Pollito - Gato" elaborado en Tinkercad. Captura de pantalla propia.</p>
        </td>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 20: Divisor de tensión con potenciómetro en el ejercicio 3</strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/tink3.jpg" width="360" height="300">
        <p align="center" class="note text-center note-white">FUENTE: Figura 20. Ejercicio de diseño titulado "Ejercicios Nivel Dragón" elaborado en Tinkercad. Captura de pantalla propia.</p>
        </td>      
</table>

## Resultados

## Conclusiones

## Bibliografía

Dynamo IOT (2021) La tecnología IoT reemplazará el sistema de rastreo GPS?. Dynamo IoT https://dynamoiot.com/la-tecnologia-iot-reemplazara-el-sistema-de-rastreo-gps/

Explore IoT kit (2024). Lección. Internet de las cosas. Explore IoT Kit. https://explore-iot.arduino.cc/iotsk/module/iot-starter-kit/lesson/internet-of-things

