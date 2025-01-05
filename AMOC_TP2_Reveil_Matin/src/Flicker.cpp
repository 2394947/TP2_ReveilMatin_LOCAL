#include "Flicker.h"

Flicker::Flicker(const uint8_t p_pin,
                 const int &p_timeTurnedOn,
                 const int &p_timeTurnedOff)
    : LED(p_pin),
      m_timeTurnedOn(p_timeTurnedOn),
      m_timeTurnedOff(p_timeTurnedOff),
      m_actionTimeMS(DEFAULT),
      m_lastTimeActionDecrementedMS(DEFAULT),
      m_cycleStep(CYCLE_STEP_ON),
      m_isFlicking(false) {
            this->m_lastTimeActionDecrementedMS = micros();
}

void Flicker::tick() {
    if (this->m_isFlicking) {
        while (this->m_actionTimeMS > DEFAULT &&
               (micros() - this->m_lastTimeActionDecrementedMS) >= INTERVAL_1)
        {
            --this->m_actionTimeMS;
            this->m_lastTimeActionDecrementedMS += INTERVAL_1;
        }

        if (this->m_actionTimeMS == 0)
        {
            switch (this->m_cycleStep)
            {
            case CycleStep::CYCLE_STEP_ON:
                this->light();
                this->m_actionTimeMS = this->m_timeTurnedOn;
                this->m_cycleStep = CycleStep::CYCLE_STEP_OFF;
                break;
            case CycleStep::CYCLE_STEP_OFF:
                this->shut();
                this->m_actionTimeMS = this->m_timeTurnedOff;
                this->m_cycleStep = CycleStep::CYCLE_STEP_ON;
            default:
                break;
            }
        }
    }
}

  void Flicker::setFlickingState(bool p_isFlicking) {
    this->m_isFlicking = p_isFlicking;
  }
