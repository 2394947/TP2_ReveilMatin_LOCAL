#include "LED.h"
#include "Connection.h"
#include "NTPClock.h"
#include "Flicker.h"
#include "InternalClock.h"
#include "Actions/ActionDisplayAlarms.h"
#include "Actions/ActionDisplayLEDs.h"
#include "Actions/ActionActivateAlarm.h"
#include "Buttons/ButtonDisplayAvailableAlarm.h"
#include "Buttons/ButtonActivateAlarm.h"
#include "AlarmClock.h"
#include "Actions/ActionDisplayConnection.h"
#include "FourDigits/Display4Digits.h"
#include "FourDigits/Display4DigitsProxyTM1637.h"
#include "Buzzer.h"
#include "Melody/Tetris.h"
#include "Melody/Doom.h"
#include "Melody/SuperMarioBros.h"
class Program
{
public:
    // Buzzer* m_buzzer;
    // Tetris* m_tetrisMelody;
    // Doom* m_doomMelody;
    // SuperMarioBros* m_superMarioBrosMelody;

    Flicker* m_yellowFlicker;
    LED* m_redLED;
    Display4Digits *m_display4Digits;
    Connection *m_connection;
    NTPClock *m_ntpClock;
    InternalClock* m_internalClock;
    AlarmClock* m_alarmClock;
    ActionDisplayAlarms* m_actionDisplayAlarms;
    ActionDisplayLEDs* m_actionDisplayLEDs;
    ActionActivateAlarm* m_actionActivateAlarm;
    ButtonDisplayAvailableAlarm* m_buttonDisplayAlarms;
    ButtonActivateAlarm* m_buttonActivateAlarm;
    ActionDisplayConnection *m_actionDisplayConnection;

    // int16_t* m_melodies[3];
    // size_t m_melodyLengths[3];

    Program();
    void loop();
    void setupCore1Task();
};