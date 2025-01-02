#include <NTPClient.h>
#include <WiFiUdp.h>

class NTPClock
{
private:
    WiFiUDP m_ntpUDP;
    NTPClient m_timeClient;

public:
    NTPClock(const char *p_serverRegion, long p_timezone, unsigned long p_updateInterval);
    NTPClient getTime();
};