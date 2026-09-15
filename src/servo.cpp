#include "servo.h"

// Creamos el objeto del servo (Exclusivo de este archivo)
Servo miServo;

// --- FUNCIÓN DE INICIALIZACIÓN (Llamada en el Setup) ---
void inicializarServo() {
  // Reservar el temporizador 0 para evitar choques con otros periféricos
  ESP32PWM::allocateTimer(0);
  
  // Configuración de la señal
  miServo.setPeriodHertz(50);
  miServo.attach(PIN_SERVO, 500, 2400); 
  
  // Iniciar mirando hacia "Arriba" (90°) por seguridad mecánica
  miServo.write(POS_ARRIBA); 
}

// --- FUNCIÓN DE CONTROL POR CARÁCTER ---
// Entradas válidas: 'D' (Derecha), 'A' (Arriba), 'I' (Izquierda)
void moverServo(char direccion) {
  switch (direccion) {
    case 'D':
    case 'd':
      miServo.write(POS_DERECHA);
      break;
      
    case 'A':
    case 'a':
      miServo.write(POS_ARRIBA);
      break;
      
    case 'I':
    case 'i':
      miServo.write(POS_IZQUIERDA);
      break;
      
    default:
      // Si por error se envía una letra inválida, se ignora el comando
      break; 
  }
}