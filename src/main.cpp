#include <Arduino.h>
#include "module.h"


void setup() {
    Serial.begin(115200);

    ConfigServer();

}

void loop() {
    ULSC();
    ULSC2();
    Serial.println(Vul);
    Serial.println(Vull);

}