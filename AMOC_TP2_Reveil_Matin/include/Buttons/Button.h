#pragma once
#include <Arduino.h>

class Button {
private:
    uint8_t m_pin;
    uint8_t m_buttonState;
    uint8_t m_lastButtonState;
    uint8_t m_lastButtonStableState;

    uint64_t m_actualTime;
    uint64_t m_lastTimeChange;
    uint16_t m_actionDelayMS;
public:
    Button(
        uint8_t p_pin,
        uint16_t p_actionDelayMS
        );
};
