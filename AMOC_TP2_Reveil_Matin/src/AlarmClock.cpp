#include "AlarmClock.h"

AlarmClock::AlarmClock(
    Display4Digits *p_display4Digits,
    InternalClock *p_internalClock
    )
      : m_display4Digits(p_display4Digits),
        m_internalClock(p_internalClock) {
            this->createDefaultAlarms();
}

void AlarmClock::showAvailableAlarms() {
    Alarm *alarm = this->m_alarms[this->m_alarmsIndex];
    uint8_t firstDigit = alarm->getHours() / 10;
    uint8_t secondDigit = alarm->getHours() % 10;
    uint8_t thirdDigit = alarm->getMinutes() / 10;
    uint8_t fourthDigit = alarm->getMinutes() % 10;

    this->m_display4Digits->display(firstDigit, secondDigit | TAB_SEG_DP, thirdDigit, fourthDigit);
    this->nextAlarm();
}

void AlarmClock::nextAlarm() {
    if (this->m_alarmsIndex < DEFAULT_NB_ALARMS)
    {
        this->m_alarmsIndex++;
    }
    else{
        this->m_alarmsIndex = 0;
    }
}

void AlarmClock::createDefaultAlarms() {
    for(uint8_t index=0; index<DEFAULT_NB_ALARMS;index++){
        this->m_alarms[index] = new Alarm(5+index,0);
    }
}

void AlarmClock::displayTime() {
    String time = this->m_internalClock->getInternalClockTime();
    int firstDigit = time.substring(0, 1).toInt();
    if(firstDigit == 0){
        firstDigit = 16;
    }
    int secondDigit = time.substring(1, 1).toInt();
    int thirdDigit = time.substring(2, 1).toInt();
    int fourthDigit = time.substring(3, 1).toInt();
    this->m_display4Digits->display(firstDigit,secondDigit,thirdDigit,fourthDigit);
}

Alarm* AlarmClock::getLastDisplayedAlarm() {
    return this->m_alarms[this->m_alarmsIndex];
}

void AlarmClock::run() {
    this->displayTime();
}

