#include "Alarm.h"

Alarm::Alarm(String p_time,
             bool p_isActive,
             Buzzer* p_buzzer) 
    :   m_time(p_time),
        m_isActive(p_isActive),
        m_buzzer(p_buzzer),
        m_alarmMelodies(nullptr) { ; }

String Alarm::getTime() {
    return this->m_time;
}

bool Alarm::isActivated(){
    return this->m_isActive;
}

void Alarm::setAlarmMelody() {
    if(this->m_isActive) {
        this->m_alarmMelodies = new AlarmMelodies(INTERVAL_3M,INTERVAL_1M,this->m_buzzer);
    } else {
        if(this->m_alarmMelodies != nullptr) {
            delete this->m_alarmMelodies;
            this->m_alarmMelodies = nullptr;
        }
    }
}