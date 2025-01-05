#pragma once
#include <Arduino.h>

class Alarm
{
private:
    uint8_t m_hours;
    uint8_t m_minutes;
    bool m_isActive;

public:
    Alarm(uint8_t p_hours, uint8_t p_minutes);

    void activate();
    void deactivate();
    bool isActivated();
    uint8_t getHours();
    uint8_t getMinutes();
};