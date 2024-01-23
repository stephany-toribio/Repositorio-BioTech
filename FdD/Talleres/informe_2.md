<p align="left">
  <img src="https://seeklogo.com/images/U/u-cayetano-heredia-logo-CA435ADF8C-seeklogo.com.png" width="200">
  <h1 align="center">Práctica 1: Manejo de Protoboard</h1>
</p>

## Introducción

El protoboard es una herramienta esencial en electrónica con características clave que lo hacen valioso para la creación y prueba de circuitos. Permite una interconexión eficiente de componentes electrónicos de manera rápida y sin requerir conexiones permanentes, brindando una plataforma versátil para el desarrollo de circuitos.

Su importancia radica en su capacidad para agilizar el proceso de diseño y prueba de circuitos electrónicos y un prototipado rapido. 

## Materiales

Kit de electrónica básica (Arduino UNO, luz led, cables, resistencias, protoboard) y un multimetro

## Implementación y desarrollo de los ejercicios: 

### Ejercicio 1

En base al gráfico proporcionado (Figura 1), se eligieron resistencias equivalentes a 100kΩ cada una. Se observa que las resistencias R1 y R2 están dispuestas en serie, mientras que la resistencia R3 se encuentra en paralelo con ambas. En primer lugar, calculamos la resistencia total sumando R1 (100kΩ) y R2 (100kΩ), obteniendo 200kΩ. Luego, sumamos este resultado con la inversa de R3, dando como resultado final 66,67kΩ. Posteriormente, montamos el circuito en el protoboard para verificar nuestros cálculos con un multímetro (Figura 3). El dispositivo arrojó un resultado aproximado a 66,7kΩ (Figura 2), corroborando así nuestras estimaciones.

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 1: </strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/ejer1.png" width="360" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 2: </strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/multimetro_1.jpg" width="340" height="300">
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>
</table>

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 3: </strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/resis1.jpg" width="340" height="400"></p>
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 4: </strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/resis1.jpg" width="360" height="400">
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>
</table>

### Ejercicio 2

En este ejercicio, contamos con un circuito que posee 5 resistencias como referencia (Figura 5). Se optó por utilizar 5 resistencias equivalentes de 100kΩ cada una. Primero, sumamos R1 y R2 en serie, y luego sumamos la inversa de este resultado con la inversa de las resistencias R3 y R4. La inversa de esta suma, junto con la inversa de R5, nos da una resistencia total de 40kΩ. Como observación, R5 se considera como un cable, ya que se conecta en los mismos nodos que las resistencias en paralelo R4 y R3, sin afectar la resistencia total. Este resultado fue corroborado mediante un multímetro, que marcó aproximadamente 40,01kΩ.  Posteriormente, montamos el circuito en el protoboard para verificar nuestros cálculos con un multímetro (Figura 7). El dispositivo arrojó un resultado  a 40,01kΩ (Figura 6), corroborando así nuestras estimaciones.

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 5: </strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/ejer2.png" width="360" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>  
        <td style="border: 0px">
        <p align="center"><strong>Figura 6: </strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/multimetro_2.jpg" width="360" height="300">
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>      
</table>

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 7: </strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/resis2.jpg" width="360" height="350"></p>
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 8: </strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/diag2.jpg" width="360" height="400">
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>
</table>

### Ejercicio 3

En base al gráfico proporcionado (Figura 9). Se optó por utilizar resistencias equivalentes a 100kΩ cada una. En primer lugar, determinamos la resistencia total mediante la suma de las resistencias en serie, considerando las combinaciones de (R1 con R3), (R5 con R6) y (R2 con R4). Luego, sumamos las inversas de cada resultado en serie, obteniendo una resistencia total de 66,67kΩ. Posteriormente, montamos el circuito en el protoboard para verificar nuestros cálculos con un multímetro (Figura 11), que arrojó un resultado de 66,67kΩ (Figura 10).

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 9: </strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/ejer3.png" width="360" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>  
        <td style="border: 0px">
        <p align="center"><strong>Figura 10: </strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/multimetro_3.jpg" width="400" height="400">
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>      
</table>

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 11: </strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/circuito_corazon.jpeg" width="400" height="350"></p>
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 12: </strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/diag3.jpg" width="400" height="350"></p>
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>
</table>

### Ejercicio 4

En el siguiente ejercicio de reducción de señal trabajamos con 5V, así mismo aplicando de la ley de Ohm para calcular la resistencia que se de adecue al led, finalizando las operaciones se puede apreciar que el resultado de dicha operación es de 300 Ω. pasamos a la parte experimental como se puede observar en la siguiente imagen:

En este ejercicio, se llevó a cabo la implementación de resistencias con el objetivo de obtener una salida de 1.1V a partir de una entrada de 5V. Se empleó el "Circuito Divisor de Tensión", basado en la Ley de Ohm, para calcular el voltaje de salida reducido. El procedimiento teórico se desarrolló de la siguiente manera (Figura 13):

<p align="center"><strong>Figura 13: </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/diag4.jpg" width="400" height="350"></p>
<p align="center" class="note text-center note-white">FUENTE: </p>

Se despejo de la relación entre las resistencias para el estimado correspondiente y se asigno el valor de 100kΩ a la resistencia 1 (R2) para determinar la resistencia 2 (R2). El resultado de la resistencia 2 (R2) fue 28.2kΩ. Este resultado se validó experimentalmente montando el circuito en el protoboard para verificar nuestros cálculos con un multímetro (Figura 14), confirmando la precisión del cálculo y la validez del diseño del circuito (Figura 15).

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 14: </strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/resis4.jpg" width="360" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>
        <td style="border: 0px"> 
        <p align="center"><strong>Figura 15: </strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/multimetro_4.jpg" width="360" height="300"></p>
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>
</table>

El "Circuito Divisor de Tensión" se define como un arreglo de resistencias que divide un voltaje de entrada en una proporción específica. La relación con la Ley de Ohm se establece mediante la proporcionalidad del voltaje en un circuito divisor con la resistencia utilizada.

### Ejercicio 5

etc

<table>
    <tr>   
        <td style="border: 0px solid #ddd; padding: 8px;">
        <p align="center"><strong>Figura 16: </strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/temp.png" width="600" style="margin: auto;"></p>
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>  
        <td style="border: 0px solid #ddd; padding: 8px;">
        <p align="center"><strong>Figura 17: </strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/cambioclimatico.png" width="600" style="margin: auto;">
        <p align="center" class="note text-center note-white">FUENTE: </p>
        </td>      
</table>