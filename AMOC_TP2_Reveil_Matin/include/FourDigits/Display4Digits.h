#pragma once
#include "Display4DigitsProxy.h"

class Display4Digits {
private:
    Display4DigitsProxy* m_proxy;
public:
    Display4Digits(Display4DigitsProxy* p_proxy);
    void display(
        uint8_t p_d1, 
        uint8_t p_d2,
        uint8_t p_d3,
        uint8_t p_d4
        );
    void displayInteger(uint8_t p_value);
};
