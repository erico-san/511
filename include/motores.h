#ifndef MOTORES_H
#define MOTORES_H

#include <Arduino.h>
#include "driver/mcpwm.h" // Librería nativa del ESP32 para el hardware PWM

// --- CONFIGURACIÓN DE HARDWARE ---
constexpr int PIN_L1 = 21; 
constexpr int PIN_L2 = 19; 
constexpr int PIN_R1 = 18; 
constexpr int PIN_R2 = 5;  

// --- PROTOTIPOS DE FUNCIONES ---
// Aquí solo le decimos al compilador que estas funciones existen
void inicializarMotores();
void motor(int velocidadIzq, int velocidadDer);
void testMotores();
void imprimirTelemetriaMotores(int vIzq, int vDer);

#endif // MOTORES_H