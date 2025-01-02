#include "NTPClock.h"

RealTimeClock::RealTimeClock(const char *p_serverRegion, long p_timezone, unsigned long p_updateInterval)
    : m_ntpUDP(),
      m_timeClient(m_ntpUDP, p_serverRegion, p_timezone, p_updateInterval)
{
    this->m_timeClient.begin();
}

NTPClient RealTimeClock::getTime()
{
    if(this->m_timeClient.update()){
        return this->m_timeClient;
    }    
}