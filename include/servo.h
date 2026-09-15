#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <ESP32Servo.h>

// --- CONFIGURACIÓN DE HARDWARE SERVO (MÁXIMA RAPIDEZ) ---
constexpr int PIN_SERVO = 32;

// --- POSICIONES PREDEFINIDAS ---
constexpr int POS_DERECHA   = 10;  // Límite derecho
constexpr int POS_ARRIBA    = 90;  // Centro / Arriba
constexpr int POS_IZQUIERDA = 180; // Límite izquierdo

// --- PROTOTIPOS DE FUNCIONES ---
void inicializarServo();
void moverServo(char direccion);

#endif // SERVOS_H