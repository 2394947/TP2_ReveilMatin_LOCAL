#include "Actions/ActionActivateAlarm.h"

ActionActivateAlarm::ActionActivateAlarm(AlarmClock* p_alarmClock) : m_alarmClock(p_alarmClock) {
    ;
}

void ActionActivateAlarm::execute() {
    if(this->m_alarmClock->getLastDisplayedAlarm()->isActivated()){
        this->m_alarmClock->getLastDisplayedAlarm()->deactivate();
    }else {
         this->m_alarmClock->getLastDisplayedAlarm()->activate();
    }
}