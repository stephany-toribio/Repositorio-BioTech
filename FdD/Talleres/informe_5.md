<p align="left">
  <img src="https://seeklogo.com/images/U/u-cayetano-heredia-logo-CA435ADF8C-seeklogo.com.png" width="200">
  <h1 align="center">Esquemático del circuito electrónico</h1>
</p>

<strong>Docentes:</strong>
- Mg Umbert Lewis De La Cruz
- Mg. Paulo Camilo Vela Antón 
- Dr. Harry Anderson Rivera Tito  
- Ing. Renzo José Chan Ríos
- Ing. Juan Manuel Zuñiga Mamani 
- Mg. Moises Stevend Meza Rodriguez

<strong>Integrantes:</strong>
- Stephany Marilyn Toribio Alvarado
- Mishell Camila Maravi Melgar
- John Jairo Rodriguez Aguirre
- Stefano Jesús Ortega Herencia

## Introducción a Flux.ai

<p align="justify">

Flux.ai es una plataforma de diseño de hardware que ayuda a crear circuitos electrónicos. Es una herramienta basada en navegador que permite diseñar circuitos desde cero. Esta plataforma aprovecha la inteligencia artificial para ayudar a optimizar los diseños y acelerar el proceso de desarrollo de los circuitos.

<p align="center"><strong>Figura 2:  </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/flux.ai.jpeg" width="400" height="230"></p>
<p align="center" class="note text-center note-white">FUENTE: Flux.ai. (s.f) A Better Way to Build PCBs. https://www.flux.ai/p/ </p>


## Materiales
- Laptop
- Plataforma Flux.ai

## Desarrollo de actividades

### Actividad 01
Comenzamos nuestra primera actividad siguiendo las instrucciones del profesor, quien nos guió a través de la plataforma Flux.ai para configurar un circuito *(figura 2)*. Para esto utilizamos un microprocesador, en nuestro caso, optamos por el ESP32-DEVKIT-V1 *(1)*. Asimismo, agregamos un botón tipo Dip switch *(2)*, una resistencia de 220Ω *(4)*, un LED *(5)* y dos conexiones a tierra (GND) al diseño *(3)*. Luego, procedimos a realizar las conexiones siguiendo las indicaciones brindadas. Esta primera parte fue elaborada en la sección "Schematic" de la plataforma.

<p align="center"><strong>Figura 2:  </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/circuito_f2.png" width="700" height="430"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 2. Flux.ai. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>


Posteriormente, nos centramos en la sección de PCB, la cual nos permitiría comprender cómo se desarrolla una Placa de Circuito Impreso (PCB) *(ver figura 3)*.

<p align="center"><strong>Figura 3: PCB </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/PCB_t5.jpeg" width="600" height="50"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 3. Flux.ai. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>

Para esto, primero acomodamos cada uno de los componentes para lograr una disposición más ordenada y funcional. Luego, ajustamos la forma y el tamaño de la placa, de manera que, sea adecuada para el circuito. Después de eso, nos dedicamos a conectar cuidadosamente cada uno de los componentes en la parte inferior de la placa, conocida como la capa "Bottom" *(figura x)*.

<p align="center"><strong>Figura 4: </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/conexiones%202d.jpeg" width="700" height="430"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 4. Flux.ai. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>

Una vez completado este proceso, añadimos la capa "Bottom Copper", que se caracterizaba por ser de color azul. Es importante destacar que, generalmente, la parte superior (Top) de la PCB suele ser de color rojo, mientras que la parte inferior (Bottom) es azul.

<p align="center"><strong>Figura 4: </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/bottom%20copper.jpeg" width="600" height="430"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 4. Flux.ai. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>

<p align="center"><strong>Figura 4: </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/circulo3.jpg" width="600" height="430"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 4. Flux.ai. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>

<table>
    <tr>   
        <td style="border: 0px">
        <p align="center"><strong>Figura 3: Vista 3D superior del circuito (TOP) </strong></p>
        <p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/bottom_act1.jpeg" width="350" height="350"></p>
        <p align="center" class="note text-center note-white">FUENTE: Figura 3. Flux.ai. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>
        </td>   
        <td style="border: 0px"> 
        <p align="center"><strong>Figura 4: Vista 3D inferior del circuito (BOTTOM) </strong></p>
        <img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/WhatsApp%20Image%202024-02-10%20at%201.58.24%20AM.jpeg" width="350" height="350">
        <p align="center" class="note text-center note-white">FUENTE: Figura 4. Flux.ai. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>
        </td>
</table>


### Actividad 02

En esta segunda actividad, aplicando los conocimientos adquiridos previamente en el uso de Flux.ai,  llevamos a cabo un proyecto asignado por el profesor que implicaba el uso de 7 materiales, optamos por incorporar 3 resistencias estándar de 220 ohmios, junto con 3 LEDs de colores (rojo, amarillo y verde), y un Arduino Nano.
Enfrentamos el desafío de no encontrar LEDS de diferentes colores, lo que nos llevó a tomar la decisión de utilizar LEDS del mismo color. Las conexiones se realizaron de la siguiente manera: el LED rojo se conectó al terminal más largo y al pin 13 del Arduino a través de una resistencia de 220 ohmios, mientras que el terminal más corto se conectó a tierra (GND). Del mismo modo, el LED amarillo se conectó de manera similar al pin 12 del Arduino, y el LED verde al pin 11, cada uno a través de una resistencia de 220 ohmios.

<p align="center"><strong>Figura 7: Dimensiones </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/Esquema.png" width="600" height="430"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 8. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>

<p align="center"><strong>Figura 8: Herramienta "revolve" </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/conexiones_en_la_placa.png" width="600" height="430"></p>
<p align="center" class="note text-center note-white">FUENTE: Herramienta "Shell" Figura 8. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>



<p align="center"><strong>Figura 9: Herramienta "Shell" </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/vaso3.jpg" width="600" height="430"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 9. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>

<p align="center"><strong>Figura 10: Herramienta "Fillet" </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/vaso4.jpg" width="600" height="430"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 10. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>

**Simulación en Tinkercad:**
En esta etapa, nos propusimos realizar una simulación en Tinkercat utilizando un código. Logramos superar las limitaciones previas y conseguimos incorporar los LEDs de diferentes colores, asi mismo trabajamos con el Arduino Uno ya que no encontramos un Arduino Nano. Como resultado, obtuvimos una representación visual de un semáforo.
<p align="center"><strong>Figura 11: Simulación de circuito en Tinkercad </strong></p>
<p align="center"><img src="https://github.com/stephany-toribio/Repositorio-BioTech/blob/main/Imagenes/simulaci%C3%B3n_smfro.jpeg" width="600" height="330"></p>
<p align="center" class="note text-center note-white">FUENTE: Figura 11. Tinkercad. (Fundamentos de Diseño 2024-0). Elaboración propia.</p>https://www.tinkercad.com/things/bI90QQHJcij-shiny-migelo/editel?tenant=circuits
                   

### Conclusión

 En conclusión pudimos completar nuestro trabajo según lo propuesto, y durante el proceso, adquirimos un profundo entendimiento de la importancia de utilizar Flux IA en nuestros proyectos. Aprendimos a utilizar de manera efectiva las diversas herramientas proporcionadas, lo que nos permitió crear un trabajo que cumplía con nuestras expectativas. Además, exploramos la funcionalidad de visualización esquemático y las conexiones en la placa, así como una vista en 3D, lo que nos permitió comprender y nos brindó una perspectiva más amplia de nuestro proyecto. Con la ayuda de Tinkercad, hemos logrado visualizar las conexiones y el código para simular nuestro proyecto, lo que ha sido fundamental para comprender cómo funciona en la práctica. Esta herramienta nos ha proporcionado una valiosa prueba de concepto, permitiéndonos validar la viabilidad y eficacia de nuestro trabajo antes de su implementación física.
