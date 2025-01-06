#pragma once
#include <Arduino.h>
#include "Buzzer.h"


class Alarm
{
private:
    String m_time;
    bool m_isActive;

public:
    Alarm(
        String p_time, 
        bool p_isActive
        );
    bool isActivated();
    String getTime();
};