#include "InternalClock.h"

InternalClock::InternalClock(
    NTPClock* p_NTPClock, 
    uint16_t p_intervalUpdate
    )
      : m_NTPClock(p_NTPClock),
        m_currentTime(DEFAULT),
        m_hours(DEFAULT),
        m_minutes(DEFAULT),
        m_seconds(DEFAULT),
        m_lastUpdate(DEFAULT),
        m_intervalUpdate(p_intervalUpdate) { 
            syncWithNTP();
         }

void InternalClock::computeTime() {
    // Incrémentation dans le tick() à toutes les 1000ms
    ++this->m_seconds;
    if (this->m_seconds >= 60) {
        this->m_seconds = DEFAULT;
        ++this->m_minutes;
        if (this->m_minutes >= 60) {
            this->m_minutes = DEFAULT;
            ++this->m_hours;
            if (this->m_hours >= 24) {
                this->m_hours = DEFAULT;
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
    String HHMM = String(this->m_hours) + 
                  (this->m_minutes < 10 ? "0" : "") + 
                  String(this->m_minutes);
    return HHMM;  
}

void InternalClock::tick() {
    uint64_t actualTime = millis();
    if (actualTime - this->m_lastUpdate >= this->m_intervalUpdate) {
        computeTime();
        this->m_lastUpdate = actualTime;       
    }
}

/**************************************************************************************************************/
// Références https://github.com/RalphBacon/ESP32-Dual-Core-Programming/blob/master/ESP32_DUALCORE_BLINK.ino
// lignes 10 et 22 créer une fonction pour rouler mon tick() dans une boucle infinis qui roulera sur le coeur1.
void InternalClock::run() {
    while (true) { 
        tick();
    }
}
/**************************************************************************************************************/
