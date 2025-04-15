
El integrado LTC2440 es un conversor analógico digital de 24 bits de resolución de la empresa Analog Devices; su comunicación con el Arduino Uno, y en general, con cualquier microcontrolador, es mediante el protocolo SPI. 

1. Para que el arduino pueda leer la información del ADC, carga el código del archivo "Codigo_LTC2440.ino". 

2. A continuación se muestran las conexiones entre el LTC2440 y el Arduino Uno:

Arduino  -  LTC2440
SCK     -   SCK
SS      -   CS
MISO     -   SDO

![Conexion_LTC2440_Arduino](https://github.com/user-attachments/assets/00e40224-39cf-4fa2-8c95-90dc573eeff3)

Estas conexiones permitirán al Arduino Uno obtener, mediante el protocolo SPI, los valores de voltajes medidos por el ADC.
