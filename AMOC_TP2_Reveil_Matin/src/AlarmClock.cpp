#include "AlarmClock.h"

AlarmClock::AlarmClock(Display4Digits *p_display4Digits,
                       ButtonDisplayAvailableAlarm *p_buttonDisplayAlarm,
                       RealTimeClock *p_realTimeClock,
                       Alarm *p_alarms[DEFAULT_NB_ALARMS])
    : m_display4Digits(p_display4Digits),
      m_buttonDisplayAlarm(p_buttonDisplayAlarm),
      m_realTimeClock(p_realTimeClock)
{
    for (size_t i = 0; i < DEFAULT_NB_ALARMS; ++i)
    {
        m_alarms[i] = p_alarms[i];
    }
}

void AlarmClock::ShowAvailableAlarms()
{
    Alarm *alarm = this->m_alarms[this->m_alarmsIndex];
    uint8_t firstDigit = alarm->getHours() / 10;
    uint8_t secondDigit = alarm->getHours() % 10;
    uint8_t thirdDigit = alarm->getMinutes() / 10;
    uint8_t fourthDigit = alarm->getMinutes() % 10;

    this->m_display4Digits->display(firstDigit, secondDigit, thirdDigit, fourthDigit);
}

void AlarmClock::nextAlarm()
{
    if (this->m_alarmsIndex < DEFAULT_NB_ALARMS)
    {
        this->m_alarmsIndex++;
    }
    else{
        this->m_alarmsIndex = 0;
    }
}
