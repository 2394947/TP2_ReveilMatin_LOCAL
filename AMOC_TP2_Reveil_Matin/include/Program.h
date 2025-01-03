#include "Connection.h"
#include "NTPClock.h"
#include "InternalClock.h"
#include "AlarmClock.h"
#include "Buttons/ButtonDisplayAvailableAlarm.h"
#include "Actions/ActionDisplayConnection.h"
#include "FourDigits/Display4Digits.h"
#include "FourDigits/Display4DigitsProxyTM1637.h"
class Program
{
public:
    Display4Digits *m_display4Digits;
    Connection *m_connection;
    NTPClock *m_ntpClock;
    InternalClock* m_internalClock;
    AlarmClock* m_alarmClock;
    ButtonDisplayAvailableAlarm* m_buttonDisplayAlarms;
    ActionDisplayConnection *m_actionDisplayConnection;
    Program();
    void loop();
};