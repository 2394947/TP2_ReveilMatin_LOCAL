#include "Alarm.h"

Alarm::Alarm(String p_time,
             bool p_isActive) 
    :   m_time(p_time),
        m_isActive(p_isActive) { ; }

void Alarm::activate(){
    this->m_isActive = true;
}

void Alarm::deactivate(){
    this->m_isActive = false;
}

String Alarm::getTime() {
    return this->m_time;
}

bool Alarm::isActivated(){
    return this->m_isActive;
}