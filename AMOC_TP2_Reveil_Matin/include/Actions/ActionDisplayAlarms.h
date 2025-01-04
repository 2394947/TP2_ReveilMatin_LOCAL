#pragma once
#include "Action.h"
#include "AlarmClock.h"

class ActionDisplayAlarms : Action {
private:
    AlarmClock* m_alarmClock;
public:
    ActionDisplayAlarms(AlarmClock* p_alarmClock);
    void execute() override;
};
