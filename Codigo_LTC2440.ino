#include <SPI.h>

#define CS_PIN 10  // Pin de Chip Select del LTC2440
#define VREF 5.0   // Voltaje de referencia en volts

void setup() {
    Serial.begin(115200);
    SPI.begin();
    pinMode(CS_PIN, OUTPUT);
    digitalWrite(CS_PIN, HIGH);  // Deshabilita el LTC2440 al inicio
}

void loop() {
    long rawData = readLTC2440();
    float voltage = convertToVoltage(rawData);
    
    Serial.print("Raw Data: ");
    Serial.print(rawData, HEX);
    Serial.print(" | Voltage: ");
    Serial.print(voltage, 8);
    Serial.println(" V");

    delay(150);  // Espera de 150ms para coincidir con 6.9Hz
}

// Función para leer el valor de 32 bits del LTC2440
long readLTC2440() {
    digitalWrite(CS_PIN, LOW);  // Activa el LTC2440
    delayMicroseconds(1);       // Pequeña espera antes de iniciar la lectura

    long result = 0;
    for (int i = 0; i < 4; i++) {
        result = (result << 8) | SPI.transfer(0x00);
    }

    digitalWrite(CS_PIN, HIGH);  // Desactiva el LTC2440

    return result;
}

// Convierte los datos crudos en voltaje real
float convertToVoltage(long rawData) {
    rawData = (rawData >> 5) & 0xFFFFFF;  // Extraer los 24 bits útiles

    if (rawData & 0x800000) {  // Si el bit de signo está activo
        rawData -= 0x1000000;  // Ajuste para representar número negativo
    }

    float voltage = (rawData * VREF) / 16777215.0; // 16777215.0 = (2^24)-1
    return voltage;
}



