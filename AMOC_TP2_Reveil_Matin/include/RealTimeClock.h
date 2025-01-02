#include <NTPClient.h>
#include <WiFiUdp.h>

class RealTimeClock
{
private:
    WiFiUDP m_ntpUDP;
    NTPClient m_timeClient;
    String m_lastTime;


public:
    RealTimeClock(const char *p_serverRegion, long p_timezone, unsigned long p_updateInterval);
    void DisplayTime();
};