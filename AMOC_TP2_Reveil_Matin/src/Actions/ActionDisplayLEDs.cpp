#include "Actions/ActionDisplayLEDs.h"

ActionDisplayLEDs::ActionDisplayLEDs(Flicker* p_yellowFlicker,
                                     LED* p_redLED,
                                     AlarmClock* p_alarmClock) 
    : m_yellowFlicker(p_yellowFlicker),
      m_redLED(p_redLED),
      m_alarmClock(p_alarmClock) {
        ;
      }

void ActionDisplayLEDs::execute() {
    this->m_redLED->shut();
    this->m_yellowFlicker->setFlickingState(true);
    if(this->m_alarmClock->getLastDisplayedAlarm()->isActivated()) {   // A revoir car je crois que la logique ne fonctionnera pas.
        this->m_redLED->light();
    }
}