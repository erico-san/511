#include "motores.h" // Conectamos este código con su propio "índice"

// --- FUNCIÓN DE INICIALIZACIÓN ---
void inicializarMotores() {
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0A, PIN_L1); 
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM0B, PIN_L2); 
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM1A, PIN_R1); 
  mcpwm_gpio_init(MCPWM_UNIT_0, MCPWM1B, PIN_R2); 

  mcpwm_config_t pwm_config;
  pwm_config.frequency = 2000;    // 2kHz: Frecuencia segura para driver DRV8871
  pwm_config.cmpr_a = 0;          
  pwm_config.cmpr_b = 0;          
  pwm_config.counter_mode = MCPWM_UP_COUNTER;
  pwm_config.duty_mode = MCPWM_DUTY_MODE_0;

  mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_0, &pwm_config); 
  mcpwm_init(MCPWM_UNIT_0, MCPWM_TIMER_1, &pwm_config); 
}

// --- FUNCIÓN DE TELEMETRÍA DE MOTORES (No bloqueante) ---
// En C++, si una función es llamada por otra, debe escribirse antes o estar en el .h
void imprimirTelemetriaMotores(int vIzq, int vDer) {
  // Al ser 'static', recuerda su valor aunque la función termine
  static unsigned long ultimoPrintMotor = 0; 
  
  // Evaluamos si ya pasaron 100ms desde la última impresión
  if (millis() - ultimoPrintMotor > 100) {
    Serial.print("M_Izq: "); Serial.print(vIzq);
    Serial.print(" | M_Der: "); Serial.println(vDer);
    
    ultimoPrintMotor = millis(); // Reiniciamos el cronómetro
  }
}

// --- FUNCIÓN MOTOR() (Corregida) ---
void motor(int velocidadIzq, int velocidadDer) {
  // Restringir los valores
  velocidadIzq = constrain(velocidadIzq, -255, 255);
  velocidadDer = constrain(velocidadDer, -255, 255);

  imprimirTelemetriaMotores(velocidadIzq, velocidadDer);
  // ==========================================
  // CONTROL MOTOR IZQUIERDO (Timer 0)
  // ==========================================
  if (velocidadIzq >= 0) {
    float duty = (velocidadIzq * 100.0) / 255.0;
    // 1. Clavamos el pin B en LOW
    mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B);
    // 2. Enviamos el Duty al pin A
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, duty);
    // 3. ¡LA CLAVE! Desbloqueamos el pin A para que el PWM salga físicamente
    mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A, MCPWM_DUTY_MODE_0); 
  } else {
    float duty = (abs(velocidadIzq) * 100.0) / 255.0;
    // 1. Clavamos el pin A en LOW
    mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_A);
    // 2. Enviamos el Duty al pin B
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, duty);
    // 3. Desbloqueamos el pin B
    mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_0, MCPWM_OPR_B, MCPWM_DUTY_MODE_0);
  }

  // ==========================================
  // CONTROL MOTOR DERECHO (Timer 1)
  // ==========================================
  if (velocidadDer >= 0) {
    float duty = (velocidadDer * 100.0) / 255.0;
    // 1. Clavamos el pin B en LOW
    mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_B);
    // 2. Enviamos el Duty al pin A
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_A, duty);
    // 3. Desbloqueamos el pin A
    mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_A, MCPWM_DUTY_MODE_0);
  } else {
    float duty = (abs(velocidadDer) * 100.0) / 255.0;
    // 1. Clavamos el pin A en LOW
    mcpwm_set_signal_low(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_A);
    // 2. Enviamos el Duty al pin B
    mcpwm_set_duty(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_B, duty);
    // 3. Desbloqueamos el pin B
    mcpwm_set_duty_type(MCPWM_UNIT_0, MCPWM_TIMER_1, MCPWM_OPR_B, MCPWM_DUTY_MODE_0);
  }
}

// --- FUNCIÓN DE PRUEBA ---
void testMotores() {
  motor(150, 150);
  delay(200);
  
  motor(0, 0);
  delay(100);
  
  motor(-150, -150);
  delay(200);
  
  motor(0, 0);
}