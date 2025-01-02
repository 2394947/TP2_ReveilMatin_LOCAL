#include "Connection.h"
#include "NTPClock.h"
#include "Actions/ActionDisplayConnection.h"
#include "FourDigits/Display4Digits.h"
#include "FourDigits/Display4DigitsProxyTM1637.h"
class Program
{
public:
    Display4Digits *m_display4Digits;
    Connection *m_connection;
    RealTimeClock *m_realTimeClock;
    ActionDisplayConnection *m_actionDisplayConnection;
    Program();
    void loop();
};