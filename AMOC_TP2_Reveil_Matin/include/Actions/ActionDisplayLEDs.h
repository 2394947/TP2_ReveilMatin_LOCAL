#pragma once
#include "Action.h"
#include "LED.h"
#include "AlarmClock.h"

class ActionDisplayLEDs : Action {
private:
    LED* m_yellowLED;
    LED* m_redLED;
    AlarmClock* m_alarmClock;
public:
    ActionDisplayLEDs(LED* p_yellowLED,
                      LED* p_redLED,
                      AlarmClock* p_alarmClock);
    void execute() override;
};