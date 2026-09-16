#include "estrategia.h"
#include "motores.h"   // Para la función motor()
#include "sensores.h"  // Para resetearSensores() y tiempoEnRecta
#include "servo.h"    // Para moverServo()
#include "pid.h"       // Para calcularPID()

// =================================================================
// 🚀 1. LÓGICA DE ARRANQUE (SECUENCIAS)
// =================================================================

struct Movimiento {
  int velIzq;
  int velDer;
  unsigned long duracion;
};

// --- DEFINICIÓN DE LAS 3 SECUENCIAS ---
// Secuencia Izquierda (Posición 1)
Movimiento secIzquierda[] = {
  //{100, 100, 150},  //de frente   
  {150, -150, 100}   //derecha //hay que hacerlo mas simple
};

// Secuencia Derecha (Posición 2)
Movimiento secDerecha[] = {
  //{100, 100, 150},  //de frente
  {-150, 150, 100}   //izquieda
};

// Secuencia Centro (Posición 3)
Movimiento secCentro[] = {
  //{-50, 200, 150},   // izquierda (poco mas de 90)
  //{100, 200, 250},   //circulo grande
  {-200, 200, 200}   //izquierda
};

int pasoActual = 0;
unsigned long inicioPaso = 0;
bool arranqueIniciado = false;

void resetearTiemposArranque() {
  pasoActual = 0;
  inicioPaso = 0;
  arranqueIniciado = false;
}

bool ejecutarArranque(int posicion) {
  
  // 1. Acciones de una sola vez (Inicio del arranque)
  if (!arranqueIniciado) {

    // ==========================================================
    // ¡AQUÍ! Limpiamos la lectura fantasma justo antes de movernos
    resetearSensores();   //colocar al final si no se confian en las medidas al girar en arranque
    // ==========================================================

    if (posicion == 1) { // 1 = Izquierda
      moverServo('D'); 
    } else if (posicion == 2) { // 2 = Derecha
      moverServo('I'); 
    } else if (posicion == 3) { // 3 = Centro
      moverServo('I'); 
    }
    arranqueIniciado = true;
  }

  // 2. Apuntar a la secuencia correcta según el nuevo mapeo
  Movimiento* secuencia;
  int totalPasos;

  if (posicion == 1) { // 1 = Izquierda
    secuencia = secIzquierda;
    totalPasos = 1; 
  } else if (posicion == 2) { // 2 = Derecha
    secuencia = secDerecha;
    totalPasos = 1; 
  } else if (posicion == 3) { // 3 = Centro
    secuencia = secCentro;
    totalPasos = 1;   //cambiar siempre que se modifica
  }

  // 3. Ejecutar la secuencia por pasos (sin delay)
  if (pasoActual < totalPasos) {
    
    if (inicioPaso == 0) inicioPaso = millis();

    motor(secuencia[pasoActual].velIzq, secuencia[pasoActual].velDer);

    if (millis() - inicioPaso >= secuencia[pasoActual].duracion) {
      pasoActual++;   
      inicioPaso = 0; 
    }
    
    return false; // Aún estamos en el arranque

  } else {
    return true; // El arranque terminó
  }
}

// =================================================================
// 🧠 2. LÓGICA DE ESTRATEGIAS (CARRERA INFINITA)
// =================================================================

void ejecutarEstrategia(int est, int errorPista) {
  
  float kp_actual = 0.0;
  float kd_actual = 0.0;
  int velBase = 0;

  switch (est) {
    
    case 1: //solo busqueda
      velBase = 0; 
      kp_actual = 35; 
      kd_actual = 20; 
      break;

    case 2: // busqueda con empuje 
      velBase = 0; 
      kp_actual = 50; 
      kd_actual = 40; 
      
      // ==========================================
      //    ACTIVACIÓN DEL TURBO
      // ==========================================

      if (tiempoEnRecta > 2000) {
        velBase = 50; 
        kp_actual = 50; 
        kd_actual = 35; 
      }
      break;
      
    case 3: //minisumo normal
      velBase = 120; 
      kp_actual = 50; 
      kd_actual = 40; 
      break;
  }

  float correccion = calcularPID(errorPista, kp_actual, kd_actual);

  int pwmIzq = velBase + correccion;
  int pwmDer = velBase - correccion;

  motor(pwmIzq, pwmDer);
}