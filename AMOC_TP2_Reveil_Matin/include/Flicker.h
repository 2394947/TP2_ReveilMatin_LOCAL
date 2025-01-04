#pragma once
#include <Arduino.h>
#include "LED.h"

class Flicker : public LED{
private:
    int m_timeTurnedOn;
    int m_timeTurnedOff;
    unsigned long m_actionTimeMS;
    uint32_t m_lastTimeactionDecrementedMS;
    int m_cycleStep;
    bool m_isFlicking;

    public:
    Flicker(const uint8_t p_pin,const int& p_timeTurnedOn, const int& p_timeTurnedOff);
    void tick();
    void setFlickingState(bool p_isFlicking);
    enum CycleStep { CYCLE_STEP_ON = 0, CYCLE_STEP_OFF = 1};
};