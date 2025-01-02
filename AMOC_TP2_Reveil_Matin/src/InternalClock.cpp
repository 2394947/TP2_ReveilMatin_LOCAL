#include "InternalClock.h"

InternalClock::InternalClock(
    NTPClock* p_NTPClock, 
    uint16_t p_intervalUpdate
    )
      : m_NTPClock(p_NTPClock),
        m_currentTime(0),
        m_hours(0),
        m_minutes(0),
        m_secondes(0),
        m_lastUpdate(0),
        m_intervalUpdate(p_intervalUpdate) { 
            this->m_ntpTime = (m_NTPClock->getTime().getHours() * 1000) + 
                              (m_NTPClock->getTime().getMinutes() * 100) + 
                              (m_NTPClock->getTime().getSeconds());
         }

void InternalClock::computeTime() {
    // Work in progress ;)
}

String InternalClock::getTime() {
    return String(this->m_currentTime);  
}

void InternalClock::tick() {
    // Work in progress ;)
}
