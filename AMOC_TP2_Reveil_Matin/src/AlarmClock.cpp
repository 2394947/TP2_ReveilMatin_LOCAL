#include "AlarmClock.h"

AlarmClock::AlarmClock(
    AlarmClockController* p_alarmClockController,
    Display4Digits *p_display4Digits,
    InternalClock *p_internalClock
    )
      : m_alarmClockController(p_alarmClockController),
        m_display4Digits(p_display4Digits),
        m_internalClock(p_internalClock) {
            this->createDefaultAlarms();
}

void AlarmClock::nextAlarm() {
    if (this->m_alarmsIndex < DEFAULT_NB_ALARMS)
    {
        this->m_alarmsIndex++;
    }
    else{
        this->m_alarmsIndex = DEFAULT;
    }
}

void AlarmClock::displayAvailableAlarms() {
    Alarm *alarm = this->m_alarmClockController->m_alarms[this->m_alarmsIndex];
    this->displayTime(alarm.time);
    this->nextAlarm();
}

void AlarmClock::displayClockTime() {
    String time = this->m_internalClock->getInternalClockTime();
    this->displayTime(time);
}

void AlarmClock::displayTime(String p_time) {
    int firstDigit = p_time.substring(0, 1).toInt();
    if(firstDigit == ARRAY_NULL){
        firstDigit = 16;
    }
    int secondDigit = p_time.substring(1, 2).toInt();
    int thirdDigit = p_time.substring(2, 3).toInt();
    int fourthDigit = p_time.substring(3, 4).toInt();
    this->m_display4Digits->display(firstDigit, secondDigit + OR_DP, thirdDigit, fourthDigit);
}

Alarm* AlarmClock::getLastDisplayedAlarm() {
    return this->m_alarms[this->m_alarmsIndex];
}

void AlarmClock::run() {
    this->displayTime();
}
