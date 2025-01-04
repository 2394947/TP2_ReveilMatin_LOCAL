#pragma once
#include <Arduino.h>
#include "Button.h"
#include "Actions/ActionDisplayAlarms.h"
#include "Actions/ActionDisplayLEDs.h"
#include "constantes.h"
#include "../Task.h"

class ButtonDisplayAvailableAlarm : public Button, Task {
private:
    uint8_t m_pin;
    uint8_t m_buttonState;
    uint8_t m_lastButtonState;
    uint8_t m_lastButtonStableState;

    uint8_t m_actualTime;
    uint8_t m_lastTimeChange;
    uint8_t m_actionDelayMS;
    ActionDisplayAlarms* m_actionDisplayAlarms;
    ActionDisplayLEDs* m_actionDisplayLEDs;
public:
    ButtonDisplayAvailableAlarm( 
        uint8_t p_pin,
        uint8_t p_actionDelayMS,
        ActionDisplayAlarms* p_actionDisplayAlarms,
        ActionDisplayLEDs* p_actionDisplayLEDs
    );
    void tick() override;
};
