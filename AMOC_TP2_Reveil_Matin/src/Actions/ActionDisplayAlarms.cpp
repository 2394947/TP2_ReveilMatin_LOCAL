#include "Actions/ActionDisplayAlarms.h"

ActionDisplayAlarms::ActionDisplayAlarms(AlarmClock* p_alarmClock) : m_alarmClock(p_alarmClock) {
    ;
}

void ActionDisplayAlarms::execute() {
    this->m_alarmClock->showAvailableAlarms();
}