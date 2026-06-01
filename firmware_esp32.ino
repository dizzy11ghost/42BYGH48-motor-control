#include <AccelStepper.h>

// Definición de pines para DRV8825
const int STEP_PIN = 12;
const int DIR_PIN = 14;
const int ENABLE_PIN = 13;

const float VELOCIDAD_MAX = 2000.0;
const float ACELERACION = 800.0;
const long VELOCIDAD_SERIAL = 115200;

// Inicialización del motor en modo Driver
AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
    Serial.begin(VELOCIDAD_SERIAL);

    pinMode(ENABLE_PIN, OUTPUT);
    digitalWrite(ENABLE_PIN, LOW); // Activar el driver

    // Configuración inicial de límites de seguridad
    stepper.setMaxSpeed(VELOCIDAD_MAX); // Pasos por segundo máximo
    stepper.setAcceleration(ACELERACION); // Aceleración (Control de rampa)
}

void loop() {
    // Escucha activa de comandos seriales (No bloqueante)
    if (Serial.available() > 0) {
        String data = Serial.readStringUntil('\n');
        processCommand(data);
    }
    
    // Ejecución del controlador de bajo nivel
    stepper.run();
}

void processCommand(String cmd) {
    // Formato: P:posicion,V:velocidad
    int pIdx = cmd.indexOf('P');
    int vIdx = cmd.indexOf('V');

    if (pIdx != -1 && vIdx != -1) {
        long newPos = cmd.substring(pIdx + 2, cmd.indexOf(',')).toInt();
        float newVel = cmd.substring(vIdx + 2).toFloat();

        // REQUERIMIENTO: Sobrescritura de comandos
        stepper.setMaxSpeed(newVel);
        stepper.moveTo(newPos);

        Serial.println("ACK: OK"); // Confirmación al PC
    }
}
