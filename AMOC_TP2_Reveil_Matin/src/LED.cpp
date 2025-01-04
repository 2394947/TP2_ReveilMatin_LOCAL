#include "LED.h"
#include <Arduino.h>

LED::LED(const uint8_t p_pin) 
  : m_pin(p_pin),
    m_isTurnedOn(false),
    m_lastChange(DEFAULT),
    m_timeTurnedOnMS(INTERVAL_500),
    m_timeTurnedOffMS(INTERVAL_500) {
  pinMode(this->m_pin, OUTPUT);
}
void LED::light() const {  
  digitalWrite(this->m_pin, HIGH);  
}

void LED::shut() const { 
  digitalWrite(this->m_pin, LOW); 
}

void LED::flicker() {
  unsigned long now = millis();
  m_lastChange = now;

  while(millis() - m_lastChange < m_timeTurnedOnMS){
    this->light();
  }

  this->m_lastChange = millis();

  while(millis() - m_lastChange < m_timeTurnedOffMS){
    this->shut();
  }
}
