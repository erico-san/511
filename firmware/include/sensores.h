#ifndef SENSORES_H
#define SENSORES_H

#include <Arduino.h>

// --- CONFIGURACIÓN DE HARDWARE SENSORES ---
constexpr int PIN_SENSOR_IZQ = 25; 
constexpr int PIN_SENSOR_DER = 23; 

// El truco 'extern': permite que la pestaña de estrategias lea el tiempo del turbo
extern unsigned long tiempoEnRecta; 

// --- PROTOTIPOS DE FUNCIONES ---
void inicializarSensores();
int obtenerErrorLinea();
void resetearSensores();
void imprimirTelemetriaError(bool izq, bool der, int error);

#endif // SENSORES_H