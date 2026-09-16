#ifndef PID_H
#define PID_H

#include <Arduino.h>

// --- PROTOTIPOS DE FUNCIONES ---
float calcularPID(int errorActual, float kp, float kd);
void reiniciarPID();

#endif // PID_H