#include "Buttons/ButtonActivateAlarm.h"

ButtonActivateAlarm::ButtonActivateAlarm(
    uint8_t p_pin,
    uint8_t p_actionDelayMS,
    ActionActivateAlarm* p_actionActivateAlarm
)
    : m_pin(p_pin),
      m_actionDelayMS(p_actionDelayMS),
      m_actionActivateAlarm(p_actionActivateAlarm),
      m_buttonState(HIGH),
      m_actualTime(DEFAULT),
      m_lastTimeChange(DEFAULT),
      m_lastButtonState(HIGH),
      m_lastButtonStableState(HIGH) {
        pinMode(this->m_pin,INPUT);
}


void ButtonActivateAlarm::tick() {
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
           this->m_actionActivateAlarm->execute();
        }
        this->m_lastButtonStableState = this->m_buttonState;
    }
}