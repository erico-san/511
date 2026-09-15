#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include "led.h" // Importamos los colores e instanciamos la estructura ColorRGB

// --- VARIABLES GLOBALES DEL MENÚ ---
// extern para que main.cpp pueda leer qué opciones elegiste
extern int posicionArranque;
extern int estrategia;

// --- PROTOTIPOS DE FUNCIONES ---
int obtenerSeleccion(ColorRGB color);
void ejecutarMenuConfiguracion();

#endif // MENU_H