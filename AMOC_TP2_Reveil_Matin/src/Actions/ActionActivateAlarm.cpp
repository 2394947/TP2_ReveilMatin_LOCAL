#include "Actions/ActionActivateAlarm.h"

ActionActivateAlarm::ActionActivateAlarm(AlarmClock* p_alarmClock) : m_alarmClock(p_alarmClock) {
    ;
}

void ActionActivateAlarm::execute() {
  this->m_alarmClock->toggleAlarmState();
}