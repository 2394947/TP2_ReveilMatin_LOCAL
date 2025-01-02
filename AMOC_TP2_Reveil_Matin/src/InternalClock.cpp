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



// class InternalClock {
// private:
//     NTPClock* m_NTPClock;
//     uint16_t m_ntpTime;
//     uint16_t m_currentTime;
//     uint8_t m_hours;
//     uint8_t m_minutes;
//     uint16_t m_secondes;
//     uint16_t m_lastUpdate;
//     uint16_t m_intervalUpdate;
//     void computeTime();

// public:
//     InternalClock(
//         NTPClock* p_NTPClock, 
//         uint16_t p_intervalUpdate
//         );
//     String getTime();
//     void tick();
// };


