#include "Connection.h"
#include "RealTimeClock.h"

class Program
{
public:
    Connection *m_connection;
    RealTimeClock *m_realTimeClock;
    Program();
    void loop();
};