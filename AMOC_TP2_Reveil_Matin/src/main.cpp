#include <Arduino.h>
#include "Program.h"

Program* program;
void setup() {
    Serial.begin(SERIAL_SPEED);
    Serial.println("Initialisation...");
    delay(1000);
    program = new Program;
    Serial.println("Programme initialisé");
 }

void loop() { 
    program->loop();
}
