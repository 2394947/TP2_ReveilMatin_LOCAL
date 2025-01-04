#pragma once
#include <Arduino.h>

class Display4DigitsProxy {
public:
    virtual void display(
        uint8_t p_d1, 
        uint8_t p_d2,
        uint8_t p_d3,
        uint8_t p_d4
    ) = 0;
    virtual void displayInteger(
        uint8_t p_value
    ) = 0;
};
