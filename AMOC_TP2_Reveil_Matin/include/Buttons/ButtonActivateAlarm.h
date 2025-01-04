#pragma once
#include <Arduino.h>
#include "Button.h"
#include "Actions/ActionActivateAlarm.h"
#include "constantes.h"
#include "../Task.h"

class ButtonActivateAlarm : Button , Task{
private:
    uint8_t m_pin;
    uint8_t m_buttonState;
    uint8_t m_lastButtonState;
    uint8_t m_lastButtonStableState;

    uint8_t m_actualTime;
    uint8_t m_lastTimeChange;
    uint8_t m_actionDelayMS;
    ActionActivateAlarm* m_actionActivateAlarm;
public:
    ButtonActivateAlarm( 
        uint8_t p_pin,
        uint8_t p_actionDelayMS,
        ActionActivateAlarm* p_actionActivateAlarm
    );
    void tick() override;
};
