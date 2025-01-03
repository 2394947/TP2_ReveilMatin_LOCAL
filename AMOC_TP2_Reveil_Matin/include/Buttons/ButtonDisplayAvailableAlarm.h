#pragma once
#include <Arduino.h>
#include "Button.h"
#include "Actions/ActionDisplayAlarms.h"
#include "config.h"

class ButtonDisplayAvailableAlarm : Button {
private:
    uint8_t m_pin;
    uint8_t m_buttonState;
    uint8_t m_lastButtonState;
    uint8_t m_lastButtonStableState;

    uint8_t m_actualTime;
    uint8_t m_lastTimeChange;
    uint8_t m_actionDelayMS;
    ActionDisplayAlarms* m_actionDisplayAlarms;
public:
    ButtonDisplayAvailableAlarm( 
        uint8_t p_pin,
        uint8_t p_actionDelayMS,
        ActionDisplayAlarms* p_actionDisplayAlarms
    );
    void tick() override;
};