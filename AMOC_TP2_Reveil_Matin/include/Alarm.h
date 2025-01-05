#pragma once
#include <Arduino.h>

class Alarm
{
private:
    String m_time;
    bool m_isActive;
public:
    Alarm(String p_time, bool p_isActive);

    void activate();
    void deactivate();
    bool isActivated();
    String getTime();
};