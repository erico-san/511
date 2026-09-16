#ifndef LED_H
#define LED_H

#include <Arduino.h>

// --- DEFINICIÓN DE LA ESTRUCTURA DE COLOR ---
struct ColorRGB {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

// --- DICCIONARIO DE COLORES PREDEFINIDOS ---
// Asumiendo que usas un LED de cátodo común (HIGH = enciende). 
// Si es ánodo común, solo invierte los HIGH por LOW.
constexpr ColorRGB COLOR_ROJO     = {HIGH, LOW, LOW};
constexpr ColorRGB COLOR_VERDE    = {LOW, HIGH, LOW};
constexpr ColorRGB COLOR_AZUL     = {LOW, LOW, HIGH};
constexpr ColorRGB COLOR_AMARILLO = {HIGH, HIGH, LOW};
constexpr ColorRGB COLOR_MORADO   = {HIGH, LOW, HIGH};
constexpr ColorRGB COLOR_OFF      = {LOW, LOW, LOW};

// --- CONFIGURACIÓN DE HARDWARE LED RGB ---
constexpr int PIN_LED_R = 12;
constexpr int PIN_LED_G = 13;
constexpr int PIN_LED_B = 14;

// --- PROTOTIPOS DE FUNCIONES ---
void escribirColorRGB(ColorRGB color);
void inicializarLED();
void actualizarLedPID(int estado);

#endif // LED_H