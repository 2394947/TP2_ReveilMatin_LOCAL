#include "Buttons/Button.h"

Button::Button(uint8_t p_pin,
               uint16_t p_actionDelayMS)
    : m_pin(p_pin),
      m_actionDelayMS(p_actionDelayMS),
      m_buttonState(HIGH),
      m_actualTime(DEFAULT),
      m_lastTimeChange(DEFAULT),
      m_lastButtonState(HIGH),
      m_lastButtonStableState(HIGH) {
        pinMode(this->m_pin,INPUT);
    }
    