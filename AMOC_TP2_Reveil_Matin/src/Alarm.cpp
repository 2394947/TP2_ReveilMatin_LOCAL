#include "Alarm.h"

Alarm::Alarm(uint8_t p_hours,
             uint8_t p_minutes) 
    : m_hours(p_hours),
      m_minutes(p_minutes) {
        this->m_isActive = false;
      }

void Alarm::activate(){
    this->m_isActive = true;
}

void Alarm::deactivate(){
    this->m_isActive = false;
}

uint8_t Alarm::getHours(){
    return this->m_hours;
}

uint8_t Alarm::getMinutes(){
    return this->m_minutes;
}