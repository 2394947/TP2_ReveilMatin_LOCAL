#include <Arduino.h>
#include "NTPClock.h"


class InternalClock {
private:
    NTPClock* m_NTPClock;
    String m_lastTime;
    String m_currentTime;
    uint16_t m_intervalUpdate;
    String computeTime();

public:
    InternalClock(NTPClock* p_NTPClock, uint16_t p_intervalUpdate);
    String getTime();
    void tick();
};