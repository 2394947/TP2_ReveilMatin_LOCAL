#include "Buttons/ButtonActivateAlarm.h"

ButtonActivateAlarm::ButtonActivateAlarm(
    uint8_t p_pin,
    uint8_t p_actionDelayMS,
    ActionActivateAlarm* p_actionActivateAlarm
)
    : Button(p_pin, p_actionDelayMS),
      m_actionActivateAlarm(p_actionActivateAlarm) { ; }

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
