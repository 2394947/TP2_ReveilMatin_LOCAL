#pragma once
#include <Arduino.h>

class Buzzer {
private:
    uint8_t m_pin;
public:
    Buzzer (uint8_t p_pin);
};