#include "Buttons/ButtonDisplayAvailableAlarm.h"

ButtonDisplayAvailableAlarm::ButtonDisplayAvailableAlarm(
    uint8_t p_pin,
    uint8_t p_actionDelayMS
)
    : m_pin(p_pin),
      m_actionDelayMS(p_actionDelayMS) {
        pinMode(this->m_pin,INPUT);
        this->m_buttonState = HIGH;
        this->m_actualTime = 0;
        this->m_lastTimeChange = 0;
        this->m_lastButtonState = HIGH;
        this->m_lastButtonStableState = HIGH;
        this->m_isPressed = false;
}


void ButtonDisplayAvailableAlarm::tick() {
    this->m_buttonState = digitalRead(this->m_pin);
    this->m_actualTime = millis();
    if (this->m_buttonState != this->m_lastButtonState)
    {
        this->m_lastTimeChange = this->m_actualTime;
        this->m_lastButtonState = this->m_buttonState;
    }
    if (this->m_actualTime - this->m_lastTimeChange >  this->m_actionDelayMS)
    {
        if (this->m_lastButtonStableState == LOW && this->m_buttonState == HIGH)
        {
           this->m_isPressed = true;
        }
        this->m_lastButtonStableState = this->m_buttonState;
    }
}