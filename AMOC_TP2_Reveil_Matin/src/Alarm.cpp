#include "Alarm.h"

Alarm::Alarm(String p_time,
             bool p_isActive,
             Buzzer p_buzzer) 
    :   m_time(p_time),
        m_isActive(p_isActive) { ; }

String Alarm::getTime() {
    return this->m_time;
}

bool Alarm::isActivated(){
    return this->m_isActive;
}