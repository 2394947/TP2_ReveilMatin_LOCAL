#pragma once
#include <Arduino.h>
#include "Buzzer.h"
#include "Melody/Melody.h"

class Alarm
{
private:
    String m_time;
    bool m_isActive;
    Buzzer* m_buzzer;
    Melody* m_melody;
public:
    Alarm(
        String p_time, 
        bool p_isActive,
        Buzzer* p_buzzer
        );
    bool isActivated();
    void createAlarmMelody();
    String getTime();
};
