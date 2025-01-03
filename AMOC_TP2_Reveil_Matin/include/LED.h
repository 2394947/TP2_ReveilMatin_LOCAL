#pragma once
#include <Arduino.h>
#include "constantes.h"

class LED {
private:
    uint8_t m_pin;
    bool m_isTurnedOn;
    unsigned long m_timeTurnedOnMS;
    unsigned long m_timeTurnedOffMS;
    unsigned long m_lastChange;
public:
    LED(const uint8_t p_pin);
    void light() const;
    void shut() const;
    void flicker();
};