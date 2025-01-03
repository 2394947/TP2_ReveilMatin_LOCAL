#pragma once
#include <Arduino.h>
#include "NTPClock.h"
#include "constantes.h"


class InternalClock {
private:
    NTPClock* m_NTPClock;
    uint16_t m_ntpTime;
    uint16_t m_currentTime;
    uint8_t m_hours;
    uint8_t m_minutes;
    uint8_t m_seconds;
    uint16_t m_lastUpdate;
    uint16_t m_intervalUpdate;
    void computeTime();
    void syncWithNTP();

public:
    InternalClock(
        NTPClock* p_NTPClock, 
        uint16_t p_intervalUpdate
        );
    String getInternalClockTime();
    void tick();
};