#include "Actions/ActionDisplayLEDs.h"

ActionDisplayLEDs::ActionDisplayLEDs(LED* p_yellowLED,
                                     LED* p_redLED,
                                     AlarmClock* p_alarmClock) 
    : m_yellowLED(p_yellowLED),
      m_redLED(p_redLED),
      m_alarmClock(p_alarmClock) {
        ;
      }

void ActionDisplayLEDs::execute() {
    this->m_redLED->shut();
    this->m_alarmClock->setDisplayAlarmState(true);
    if(this->m_alarmClock->getLastDisplayedAlarm()->isActivated()) {
        this->m_redLED->light();
    }
    while(this->m_alarmClock->getDisplayAlarmState() == true){
      this->m_yellowLED->flicker();
    }
}