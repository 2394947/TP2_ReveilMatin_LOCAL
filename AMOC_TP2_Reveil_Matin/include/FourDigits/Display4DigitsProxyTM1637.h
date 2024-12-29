#pragma once
#include <Arduino.h>
#include <TM1637Display.h>
#include "Display4DigitsProxy.h"

class Display4DigitsProxyTM1637 : public Display4DigitsProxy
{
private:
    TM1637Display *m_tm1637;
    uint8_t m_clockPin;
    uint8_t m_dataPin;

public:
    Display4DigitsProxyTM1637(
        uint8_t p_clockPin,
        uint8_t p_dataPin);
    void display(
        uint8_t p_d1,
        uint8_t p_d2,
        uint8_t p_d3,
        uint8_t p_d4) override;
    void displayInteger(uint8_t p_value) override;

    void tick();
};