#ifndef ARRANCADOR_H
#define ARRANCADOR_H

#include <Arduino.h>

// --- VARIABLES GLOBALES COMPARTIDAS ---
// Usamos 'extern' para que main.cpp y la lógica de carrera puedan ver si el robot tiene permiso de moverse.
// 'volatile' es obligatorio porque esta variable cambia dentro de una interrupción de hardware.
extern volatile bool robotActivo;

// --- CONFIGURACIÓN DE HARDWARE ARRANCADOR ---
constexpr int PIN_ARRANCADOR = 4;

// --- PROTOTIPOS DE FUNCIONES ---
void inicializarArrancador();

#endif // ARRANCADOR_H