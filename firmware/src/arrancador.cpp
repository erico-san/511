#include "arrancador.h"

// --- DEFINICIÓN DE LA VARIABLE GLOBAL ---
volatile bool robotActivo = false; // Inicia apagado por seguridad

// --- ISR: INTERRUPCIÓN DEL ARRANCADOR ---
// Esta función se ejecuta automáticamente en microsegundos cuando el pin 4 cambia
void IRAM_ATTR isrArrancador() {
  if (digitalRead(PIN_ARRANCADOR) == HIGH) {
    robotActivo = true;  // Bandera arriba: El robot tiene permiso para moverse
  } else {
    robotActivo = false; // Bandera abajo: El robot debe detenerse
    
    // NOTA DE SEGURIDAD: 
    // Aunque podríamos intentar apagar los motores aquí mismo, llamar a funciones
    // complejas como motor() dentro de un ISR puede hacer que el ESP32 colapse.
    // Es más rápido y seguro bajar la bandera y dejar que el loop() los apague.
  }
}

// --- FUNCIÓN DE INICIALIZACIÓN ---
void inicializarArrancador() {
  pinMode(PIN_ARRANCADOR, INPUT); 
  
  // Configuramos la interrupción para que se dispare en modo "CHANGE".
  // Esto significa que la ISR se activará tanto cuando pase de 0 a 1, como de 1 a 0.
  attachInterrupt(digitalPinToInterrupt(PIN_ARRANCADOR), isrArrancador, CHANGE);
}