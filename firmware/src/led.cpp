#include "led.h"

// --- FUNCIÓN MAESTRA ---
void escribirColorRGB(ColorRGB color) {
  digitalWrite(PIN_LED_R, color.r);
  digitalWrite(PIN_LED_G, color.g);
  digitalWrite(PIN_LED_B, color.b);
}

// --- FUNCIÓN DE INICIALIZACIÓN ---
void inicializarLED() {
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  
  // Inicia en verde por defecto
  escribirColorRGB(COLOR_VERDE);
}

// --- FUNCIÓN RENOMBRADA PARA PID ---
// Se llama desde el PID porque es el feedback visual de la pista
void actualizarLedPID(int estado) {
  if (estado == 0) {
    escribirColorRGB(COLOR_VERDE);
  } 
  else if (estado == -1 || estado == -2) {
    escribirColorRGB(COLOR_ROJO);
  } 
  else if (estado == 1 || estado == 2) {
    escribirColorRGB(COLOR_AZUL);
  }
}