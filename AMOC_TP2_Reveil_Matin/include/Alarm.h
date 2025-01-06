#pragma once
#include <Arduino.h>
#include "Buzzer.h"
#include "AlarmMelodies.h"

class Alarm
{
private:
    String m_time;
    bool m_isActive;
    Buzzer* m_buzzer;
    AlarmMelodies* m_alarmMelodies;
public:
    Alarm(
        String p_time, 
        bool p_isActive,
        Buzzer* p_buzzer
        );
    bool isActivated();
    void setAlarmMelody();
    String getTime();
};
