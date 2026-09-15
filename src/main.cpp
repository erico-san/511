#include <Arduino.h>

// --- INCLUSIÓN DE TODOS TUS MÓDULOS ---
#include "motores.h"
#include "sensores.h"
#include "arrancador.h"
#include "pid.h"
#include "servo.h"
#include "led.h"
#include "menu.h"
#include "estrategia.h"

// --- DECLARACIÓN DE LA MÁQUINA DE ESTADOS ---
// Esto sí se queda aquí porque es exclusivo de la lógica central del loop
enum EstadoRobot { ESTADO_ARRANQUE, ESTADO_CARRERA };
EstadoRobot estadoActual = ESTADO_ARRANQUE;

void setup() {
  Serial.begin(115200);

  // 1. Despertamos a todos los periféricos
  inicializarLED();
  inicializarMotores();
  inicializarServo();
  inicializarSensores();
  inicializarArrancador();

  // 2. Ejecutamos tu menú de configuración
  ejecutarMenuConfiguracion(); 
  
  // 3. Estado de reposo esperando la carrera
  motor(0, 0);
  moverServo('A'); 
  
  Serial.println("Configuración exitosa. Posición: " + String(posicionArranque));
  Serial.println("Estrategia: " + String(estrategia));
  Serial.println("Esperando señal de arranque...");
}

void loop() {
  // 1. Leemos la pista
  int estadoPista = obtenerErrorLinea();
  actualizarLedPID(estadoPista);

  // 2. CONTROL PRINCIPAL
  // 'robotActivo' es leída gracias al módulo arrancador.h
  if (robotActivo == true) {
    
    // --- MÁQUINA DE ESTADOS EN ACCIÓN ---
    switch (estadoActual) {
      
      case ESTADO_ARRANQUE:
        // Si devuelve true, la secuencia inicial terminó
        if (ejecutarArranque(posicionArranque) == true) {
          estadoActual = ESTADO_CARRERA; 
        }
        break;

      case ESTADO_CARRERA:
        // Lógica infinita según la estrategia del menú
        ejecutarEstrategia(estrategia, estadoPista);
        break;
    }

  } else {
    
    // ==========================================
    // MODO ESPERA (PARADA DE SEGURIDAD Y RESET)
    // ==========================================
    if (estadoActual != ESTADO_ARRANQUE) {
      motor(0, 0);       
      moverServo('A');   
      reiniciarPID(); 
      
      // Reiniciamos el cerebro para la próxima vez que levantes el arrancador
      estadoActual = ESTADO_ARRANQUE; 
      resetearTiemposArranque(); 
    }
  }
}