#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <Arduino.h>

// --- PROTOTIPOS DE FUNCIONES ---
void resetearTiemposArranque();
bool ejecutarArranque(int posicion);
void ejecutarEstrategia(int est, int errorPista);

#endif // ESTRATEGIA_H