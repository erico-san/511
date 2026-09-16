# 611 [Minisumo Autónomo Master]

Se recopila toda la información del desarrollo de un minisumo autónomo con potencial de atacar hasta 1.7m/s sin levantar la cuchilla del suelo. 

Esto se logra bajando el centro de masa con una base de acero inoxidable y un sistema de rodamientos que mantiene siempre la base estable con 3 puntos de apoyo, logrando que la rampa siempre tenga contacto con el suelo hasta en las aceleraciones.

<img width="1375" height="1375" alt="1" src="https://github.com/user-attachments/assets/960364f6-5c72-4a73-ac1e-87ff56ff4aed" />

## Archivos CAD y Guías

* **Ensamble general:** [Ver en Onshape](https://cad.onshape.com/documents/41288bb1b649f1cc4c519aff/w/f8fe4551e4bde9e0308eaa97/e/09e1865bc77f3aaf016bfd1d)
* **Parte trasera:** [Ver en Onshape](https://cad.onshape.com/documents/aa54527f96e029797166dfbc/w/8263a348cfddac355c8084ae/e/5252993940488901abcc4b98)
* **Parte delantera:** [Ver en Onshape](https://cad.onshape.com/documents/30f2fe6714e3628f9fcf3131/w/3cf9c9f8e3532016b5838cb8/e/816fd499ac567c18d15aaf2d)

También dejo adjunta una guía de ensamble para una versión anterior, que es muy similar a la actual:
* [Guía de ensamble Mini sumo 508.pdf](Guia%20de%20ensamble%20Mini%20sumo%20508.pdf)

## El chasis

Mide 100mm ancho x 99mm largo. 

Se trata de un prototipo de ensamble simple con los siguientes componentes:
* 2 rodamientos f693zz.
* 1 Tornillo DIN 7991 M3x35.
* 1 Tuerca M3x2.4mm.
* [4 Tornillos de cabeza de oblea plana ultrafina M3x10](https://es.aliexpress.com/item/1005008281456967.html?spm=a2g0o.order_list.order_list_main.29.10ed194dlNUb0n&gatewayAdapt=glo2esp).
* 4 prisioneros allen M4x6 (2 para los aros y 2 para fijar los motores).
* [2 motores GM13-050SH chihai 6V 1672 35:1](https://es.aliexpress.com/item/32824803243.html?spm=a2g0o.order_list.order_list_main.5.289e194d4YaFcy&gatewayAdapt=glo2esp).
* [2 sensores fotoeléctricos láser con supresión de fondo E3ZC-BN06-R](https://es.aliexpress.com/item/1005007740151156.html?spm=a2g0o.order_list.order_list_main.69.10ed194dlNUb0n&gatewayAdapt=glo2esp).
* [1 cuchilla genérica](https://es.aliexpress.com/item/1005004445186967.html?spm=a2g0o.order_list.order_list_main.114.10ed194dlNUb0n&gatewayAdapt=glo2esp).
* Base de acero inoxidable 6mm con bisel 25 grados.
* [1 batería gaoneng 3S 300mah](https://es.aliexpress.com/item/1005006010618131.html?spm=a2g0o.order_list.order_list_main.5.3006194d3xrOsT&gatewayAdapt=glo2esp).
* [1 servo sg90 (opcional)](https://es.aliexpress.com/item/1005006283358420.html?spm=a2g0o.productlist.main.4.20f77beaMJXBqM&aem_p4p_detail=202609151459451842771660195410000016344&algo_pvid=e05f99db-dd20-40cc-9ecb-cb87975e3b88&algo_exp_id=e05f99db-dd20-40cc-9ecb-cb87975e3b88-3&pdp_ext_f=%7B%22order%22%3A%225990%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21PEN%217.23%216.65%21%21%212.07%211.90%21%402101ca9517895095850443121e0e27%2112000036603734124%21sea%21PE%212052306243%21X%211%210%21n_tag%3A-29919%3Bd%3Ab20312be%3Bm03_new_user%3A-29895%3BpisId%3A5000000217704499&curPageLogUid=m1U1VX5mBmA7&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006283358420%7C_p_origin_prod%3A&search_p4p_id=202609151459451842771660195410000016344_1).
* [1 varilla cuadrada de carbón hueca 3x3x2 (opcional)](https://es.aliexpress.com/item/1005009266127261.html?spm=a2g0o.order_list.order_list_main.5.52e0194dw7i9B1&gatewayAdapt=glo2esp).
* Cartulina blanca para la bandera (opcional).
* [Cinta de espuma 12mm para pegar la cuchilla](https://es.aliexpress.com/item/1005006191684584.html?spm=a2g0o.order_list.order_list_main.27.289e194d4YaFcy&gatewayAdapt=glo2esp).

<img width="452" height="258" alt="2" src="https://github.com/user-attachments/assets/1ba55de8-aeb7-4447-83dc-00570bef2113" />

Si han tenido un robot de dos ruedas antes y "se levantaba" al avanzar, esto es porque el centro de masa estaba arriba del eje y como la fuerza de inercia apunta hacia atrás, se genera un momento angular en sentido horario, viéndolo desde la llanta izquierda. En cambio, si el CM se encuentra por debajo del eje de las llantas, el torque generado por la inercia tiene sentido horario y más bien se necesita una fuerza normal (hacia arriba) en la rampa para contrarrestar este efecto. 

Esto se traduce en que incluso al acelerar la rampa se pega más fuerte al piso porque hay una reacción mayor. El efecto contrario también ocurre; si en este último caso frenas, la rampa sí tenderá a levantarse por un instante, pero solo basta con no frenar antes de impactar, ¿verdad?

<img width="451" height="204" alt="3" src="https://github.com/user-attachments/assets/b24b6be3-e7d8-4455-9f76-09687be332ec" />

La base metálica de 6mm se compró y se mandó a cortar en una metalmecánica y debe costar aproximadamente 20USD.

El minisumo está muy por debajo de los 500gr reglamentarios, lo que da la posibilidad de agregar un servo simple SG90 (3usd) con bandera encima para generar más problemas en el oponente. Junto con la rampa de acero 0.7mm (5USD) cortada en CNC todo suma 494 gr.

<img width="452" height="319" alt="4" src="https://github.com/user-attachments/assets/d3015102-0676-4343-945e-399d6c49edca" />

## Estabilización de rampa

<img width="497" height="198" alt="5" src="https://github.com/user-attachments/assets/a1b17a66-ca5a-48c9-8b9f-3fefbfcea54d" />

Ángulo máximo de torsión.

¿Por qué este sistema de amortiguamiento debería funcionar?

Las llantas solo podrían transmitir toda la potencia por un solo punto, no se podría efectuar momentos al chasis en el eje Y. Por esto, cualquier deformación relativa entre llantas no se transmitiría a la rampa, manteniendo siempre todos sus puntos pegados al piso. 

<img width="452" height="263" alt="6" src="https://github.com/user-attachments/assets/108e55b9-5b51-4089-ab9c-91113b948e94" />

## Sobre los motores

Se usan los chihai 6v 35:1 1672. A 12v tienen 1140RPM en vacío y 3.0kg-cm de torque en stall. También manejan hasta 6.8A pero como el torque del motor está limitado por el coeficiente de fricción de las llantas, asumiendo el peor escenario donde cada llanta se reparte 250 gramos de peso y sus coeficientes de fricción son de 2.0 a lo mucho consume 0.82.kg-cm y 1.9A máximos teóricos, por eso con unos drv8871 configurados a un pico de 3.6A están bien. Son los motores en aliexpress que más se acercan a los parámetros de jsumo (16USD) pero por la mitad de su precio (8USD).

<img width="452" height="147" alt="7" src="https://github.com/user-attachments/assets/704b2b48-a4d5-4103-9ebe-9a8e88f48ee1" />

Se usó a 3 celdas y esto permite una velocidad máxima aproximada de 1.7m/s. Con el correcto algoritmo es una buena base donde trabajar.

## Sobre los sensores

Los sensores usados son E3ZC-BN06-R (cada uno 30USD) y se eligieron porque deberían ser mejores que los sensores fotoeléctricos Omron E3Z para esta aplicación. 

<img width="291" height="438" alt="8" src="https://github.com/user-attachments/assets/5312e8f5-68b5-461b-999b-413c0b78cec1" />

Los E3Z-D se comportan muy diferente ante diferentes colores/acabados superficiales.

<img width="398" height="461" alt="10" src="https://github.com/user-attachments/assets/1e3e9a75-2e82-403c-b75c-b295467dba96" />
Pero también está el modelo E3Z-LS que tiene un haz de luz que concentra toda la intensidad en un espacio muy pequeño, en el orden de milímetros, lo que hace que la reflexión captada sea casi independiente del área/color/acabado de la superficie. Además que cuenta con BGS (supresión de fondo) que son métodos para detectar objetos no solo en la intensidad sino que usa triangulación geométrica. 

El lado negativo es que esta gama de sensores son extremadamente caros (170 USD) en estado nuevo y originales y además su distancia de alcance es muy pequeña, por debajo de los 20cm.

<img width="452" height="285" alt="11" src="https://github.com/user-attachments/assets/c4f6f917-c359-4531-9637-ad92d9a139cc" />

Después de mucha búsqueda, encontré el Zhican E3ZC – BN06 que prometía ser todo lo que no podía adquirir con bajo presupuesto. Láser, luz visible, BGS y 60cm de detección, a solo 30USD cada uno. Claro que tiene que ser NPN si no quieres quemar tu ESP32.

Igualmente todo trae un riesgo y actualmente se encuentra en fase de prueba, si funciona al colocarlo y calibrarlo en el minisumo pero necesitaré más datos para sacarle provecho a lo que promete. Cuando tenga tiempo subiré actualizaciones.

<img width="452" height="329" alt="12" src="https://github.com/user-attachments/assets/90facac5-5929-4ea7-82dd-0e5d766fbf70" />

## Main board

Se trata de la primera versión de placa universal de Novatech [El mejor equipo de robótica del Perú].

Sus características principales:
* ESP32 wroom.
* 2x Drv8871 (config a 3.6A pico).
* 1 LED RGB.
* 9 pines de entrada para sensores.
* 1 botón.
* 3cm x 6cm x 1.2mm.
* 1 MOSFET switch general (hasta 15A de entrada).

<img width="452" height="291" alt="13" src="https://github.com/user-attachments/assets/40bc3a3f-5edd-4fb4-8fd8-d851865aec44" />

## Por mejorar / propuestas de mejora

* Falta hacer pruebas y obtener datos para saber si los mágicos y económicos sensores Zhican cumplen con lo descrito y también comparar con sensores más usados como los JS40F, rz60, E18-D80NK, etc. Calcular la altura y orientación óptima.
* Se pueden añadir hasta 4 sensores de este tipo para aumentar el campo de visión y poder tener mayor información de entrada.
* Se pueden cambiar los motores por unos menos potentes pero con mayor capacidad de control como los chihai 6v 330rpm 30:1, el cual trae encoders y con esto programar trayectorias de salida mucho más precisas que solo concatenando pwm.
* La PCB tiene un switch muy difícil de acceder así que si diseñan la suya, pensar en eso porque hay que estar retirando la batería cada vez que se quiere reiniciar y con el conector XT30 esto se vuelve una tarea complicada de hacer, sobre todo en competencia.
* Hay pines del ESP32 que se usan como strapping pins, los cuales cambian de estado al encender. Si diseñan una PCB tomar en cuenta cuáles son, hasta donde entiendo: GPIO 0, GPIO 2, GPIO 5, GPIO 12, y GPIO 15. En la versión actual un motor se enciende cada vez que se resetea y es peligroso.
