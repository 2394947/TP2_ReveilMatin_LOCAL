#include "InternalClock.h"

InternalClock::InternalClock(
    NTPClock* p_NTPClock, 
    uint16_t p_intervalUpdate
    )
      : m_NTPClock(p_NTPClock),
        m_currentTime(0),
        m_hours(0),
        m_minutes(0),
        m_seconds(0),
        m_lastUpdate(0),
        m_intervalUpdate(p_intervalUpdate) { 
            syncWithNTP();
         }

void InternalClock::computeTime() {
    // Incrémentation dans le tick() à toutes les 1000ms
    ++this->m_seconds;
    if (this->m_seconds >= 60) {
        this->m_seconds = 0;
        ++this->m_minutes;
        if (this->m_minutes >= 60) {
            this->m_minutes = 0;
            ++this->m_hours;
            if (this->m_hours >= 24) {
                this->m_hours = 0;
                syncWithNTP();
            }
        } 
    }
    this->m_currentTime = this->m_seconds + 
                         (this->m_minutes * 100) + 
                         (this->m_hours * 10000); 
}

void InternalClock::syncWithNTP() {
    unsigned long ntpHours = m_NTPClock->getTime().getHours();
    unsigned long ntpMinutes = m_NTPClock->getTime().getMinutes();
    unsigned long ntpSeconds = m_NTPClock->getTime().getSeconds();
    
    this->m_hours = ntpHours;
    this->m_minutes = ntpMinutes;
    this->m_seconds = ntpSeconds;

    // Mise à jour de m_currentTime au format HHMMSS par la méthode existante computeTime();
    computeTime();  
}        

String InternalClock::getInternalClockTime() {
    char HHMM[5];
    snprintf(HHMM, sizeof(HHMM), "%02u%02u", this->m_hours, this->m_minutes);
    return String(HHMM);  
}

void InternalClock::tick() {
    uint64_t currentMillis = millis();
    if (currentMillis - this->m_lastUpdate >= m_intervalUpdate) {
        this->m_lastUpdate += m_intervalUpdate;
        computeTime();
    }
}
