#include "sensores.h"

volatile bool flagSensorIzq = false;
volatile bool flagSensorDer = false;

// Memoria local exclusiva para el comportamiento de salida de pista
int ultimoErrorValido = 0; 

// --- VARIABLES INTERNAS Y GLOBALES DEL CONTADOR (TURBO) ---
unsigned long tiempoEnRecta = 0; // Aquí se define físicamente la variable extern
unsigned long inicioRecta = 0;   
bool estabaEnRecta = false;      

// --- ISR: INTERRUPCIONES DE LOS SENSORES NPN ---
void IRAM_ATTR isrSensorIzq() {
  flagSensorIzq = (digitalRead(PIN_SENSOR_IZQ) == LOW);
}

void IRAM_ATTR isrSensorDer() {
  flagSensorDer = (digitalRead(PIN_SENSOR_DER) == LOW);
}

// --- FUNCIÓN DE INICIALIZACIÓN ---
void inicializarSensores() {
  pinMode(PIN_SENSOR_IZQ, INPUT_PULLUP);
  pinMode(PIN_SENSOR_DER, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_IZQ), isrSensorIzq, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_DER), isrSensorDer, CHANGE);
  
  // Sincronización inicial
  flagSensorIzq = (digitalRead(PIN_SENSOR_IZQ) == LOW);
  flagSensorDer = (digitalRead(PIN_SENSOR_DER) == LOW);
}

// --- DEVOLUCIÓN DE ESTADO / CÁLCULO DEL ERROR ---
int obtenerErrorLinea() {
  int errorActual = 0;
  bool leeIzq = flagSensorIzq;
  bool leeDer = flagSensorDer;

  if (leeIzq && leeDer) {
    errorActual = 0; 
    
    // --- LÓGICA DEL CONTADOR (INICIO/ACTUALIZACIÓN) ---
    if (!estabaEnRecta) {
      inicioRecta = millis(); 
      estabaEnRecta = true;
    }
    tiempoEnRecta = millis() - inicioRecta; 
    
  } else {
    // --- RESET DEL CONTADOR ---
    estabaEnRecta = false;
    tiempoEnRecta = 0;

    // --- LÓGICA DE ERRORES ---
    if (leeIzq && !leeDer) {
      errorActual = -1; 
    } else if (!leeIzq && leeDer) {
      errorActual = 1; 
    } else if (!leeIzq && !leeDer) {
      // Memoria de salida de pista usando la variable interna de este tab
      if (ultimoErrorValido < 0) errorActual = -2;
      else if (ultimoErrorValido > 0) errorActual = 2;
    }
  }

  ultimoErrorValido = errorActual; // Guardamos para el próximo ciclo

  imprimirTelemetriaError(leeIzq, leeDer, errorActual);
  return errorActual;
}

// --- FUNCIÓN DE LIMPIEZA DE MEMORIA ---
void resetearSensores() {
  ultimoErrorValido = 0; 
  estabaEnRecta = false;
  tiempoEnRecta = 0;
}

// --- FUNCIÓN DE TELEMETRÍA DE SENSORES (No bloqueante) ---
void imprimirTelemetriaError(bool izq, bool der, int error) {
  static unsigned long ultimoPrintError = 0; 
  
  if (millis() - ultimoPrintError > 100) {
    Serial.print("S_Izq: "); Serial.print(izq);
    Serial.print(" | S_Der: "); Serial.print(der);
    Serial.print(" | Error Calculado: "); Serial.println(error);
    
    ultimoPrintError = millis(); // Reiniciamos el cronómetro
  }
}