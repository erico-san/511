#include "menu.h"

// --- DEFINICIÓN DE VARIABLES GLOBALES ---
// Nacen en la memoria con un valor inicial por defecto de 1
int posicionArranque = 1; 
int estrategia = 1;       

// --- DEFINICIONES DE CONFIGURACIÓN ---
constexpr int PIN_BOTON = 0; // IO0

// ==========================================
// FUNCIÓN AUXILIAR DE CONTEO Y DEBOUNCE
// ==========================================
int obtenerSeleccion(ColorRGB color) {
  int conteo = 0;
  bool seleccionConfirmada = false;

  // --- VARIABLES DE LA CAPA 1: FILTRO ANTI-RUIDO (DEBOUNCE) ---
  bool estadoBotonFiltrado = false; 
  bool ultimoEstadoCrudo = false;
  unsigned long tiempoUltimoRuido = 0;
  const unsigned long tiempoEstabilidad = 30; // Exige 30ms de estabilidad

  // --- VARIABLES DE LA CAPA 2: LÓGICA DE TIEMPOS ---
  unsigned long tiempoInicioPresion = 0;
  bool botonEstabaPresionado = false;
  bool accionLargaRealizada = false;

  escribirColorRGB(COLOR_OFF);

  while (!seleccionConfirmada) {
    
    // CAPA 1: LIMPIEZA DE LA SEÑAL
    bool lecturaCruda = (digitalRead(PIN_BOTON) == LOW); // LOW = presionado

    if (lecturaCruda != ultimoEstadoCrudo) {
      tiempoUltimoRuido = millis();
    }
    
    if ((millis() - tiempoUltimoRuido) > tiempoEstabilidad) {
      if (lecturaCruda != estadoBotonFiltrado) {
        estadoBotonFiltrado = lecturaCruda; 
      }
    }
    ultimoEstadoCrudo = lecturaCruda;

    // CAPA 2: LÓGICA DE PULSACIONES
    if (estadoBotonFiltrado && !botonEstabaPresionado) {
      botonEstabaPresionado = true;
      tiempoInicioPresion = millis();
      accionLargaRealizada = false; 
    } 
    else if (estadoBotonFiltrado && botonEstabaPresionado) {
      if (!accionLargaRealizada && (millis() - tiempoInicioPresion >= 500)) {
        escribirColorRGB(COLOR_ROJO); delay(100); 
        escribirColorRGB(COLOR_OFF);  delay(200);
        
        accionLargaRealizada = true; 
        seleccionConfirmada = true;  
        
        while (digitalRead(PIN_BOTON) == LOW) {
          delay(10);
        }
      }
    } 
    else if (!estadoBotonFiltrado && botonEstabaPresionado) {
      botonEstabaPresionado = false;
      
      if (!accionLargaRealizada) {
        conteo++;
        if (conteo > 3) conteo = 1;
        
        for (int i = 0; i < conteo; i++) {
          escribirColorRGB(color);
          delay(100);
          escribirColorRGB(COLOR_OFF);
          delay(200); 
        }
      }
    }
  }
  
  if (conteo == 0) conteo = 1;

  return conteo;
}

// ==========================================
// FUNCIÓN MAESTRA DEL MENÚ
// ==========================================
void ejecutarMenuConfiguracion() {
  pinMode(PIN_BOTON, INPUT_PULLUP);
  
  // 1. FASE DE SELECCIÓN
  posicionArranque = obtenerSeleccion(COLOR_MORADO);
  estrategia = obtenerSeleccion(COLOR_AMARILLO);

  // 2. FASE DE CONFIRMACIÓN Y REPASO
  escribirColorRGB(COLOR_ROJO); delay(600); 
  escribirColorRGB(COLOR_OFF);  delay(600); 

  for (int i = 0; i < posicionArranque; i++) {
    escribirColorRGB(COLOR_MORADO); delay(150);
    escribirColorRGB(COLOR_OFF);    delay(600); 
  }

  delay(600); 

  for (int i = 0; i < estrategia; i++) {
    escribirColorRGB(COLOR_AMARILLO); delay(150);
    escribirColorRGB(COLOR_OFF);      delay(600); 
  }
  
  delay(1000);  
}