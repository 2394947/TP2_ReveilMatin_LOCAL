#pragma once
#include <Arduino.h>
#include "Buzzer.h"

class Alarm
{
private:
    String m_time;
    bool m_isActive;
    Buzzer m_buzzer;

public:
    Alarm(
        String p_time, 
        bool p_isActive,
        Buzzer p_buzzer
        );
    bool isActivated();
    String getTime();
};
