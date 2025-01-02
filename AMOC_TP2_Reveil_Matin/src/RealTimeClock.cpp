#include "RealTimeClock.h"

RealTimeClock::RealTimeClock(const char *p_serverRegion, long p_timezone, unsigned long p_updateInterval)
    : m_ntpUDP(),
      m_timeClient(m_ntpUDP, p_serverRegion, p_timezone, p_updateInterval),
      m_lastTime("")
{
    this->m_timeClient.begin();
}

void RealTimeClock::DisplayTime()
{
    
    this->m_timeClient.update();
    int hours = this->m_timeClient.getHours();
    int minutes = this->m_timeClient.getMinutes();
    String timeToPrint = String(hours) + ":" + (minutes < 10 ? "0" : "") + String(minutes);
    if (m_lastTime != timeToPrint)
    {
        Serial.println(timeToPrint);        
    }
    m_lastTime = timeToPrint;
}