#pragma once
#include "Action.h"
#include "AlarmClock.h"

class ActionActivateAlarm : Action {
private:
    AlarmClock* m_alarmClock;
public:
    ActionActivateAlarm(AlarmClock* p_alarmClock);
    void execute() override;
};
