#pragma once
#include "Action.h"
#include "LED.h"
#include "Flicker.h"
#include "AlarmClock.h"

class ActionDisplayLEDs : Action {
private:
    Flicker* m_yellowFlicker;
    LED* m_redLED;
    AlarmClock* m_alarmClock;
public:
    ActionDisplayLEDs(
        Flicker* p_yellowFlicker,
        LED* p_redLED,
        AlarmClock* p_alarmClock
        );
    void execute() override;
};
