#include "pid.h"

// --- VARIABLES GLOBALES PRIVADAS ---
// Memoria del PID (No necesita extern porque solo vive y se usa en este archivo)
int ultimoErrorPID = 0;

// --- FUNCIÓN PRINCIPAL DE CONTROL ---
// Ahora exige el error, Kp y Kd
float calcularPID(int errorActual, float kp, float kd) {
  
  float P = errorActual;
  float D = errorActual - ultimoErrorPID;
  
  float correccion = (P * kp) + (D * kd);
  
  // Guardamos el error para la siguiente derivada
  ultimoErrorPID = errorActual; 
  
  return correccion;
}

// --- FUNCIÓN DE LIMPIEZA ---
// Función auxiliar para resetear la memoria del PID cuando el robot se detiene
void reiniciarPID() {
  ultimoErrorPID = 0;
}