#include "Program.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

uint8_t pinButtonAlarms = 17; 

Program::Program()
    : m_connection(nullptr),
      m_ntpClock(nullptr) {
    Display4DigitsProxy* p_proxy = new Display4DigitsProxyTM1637(
    CLK,
    DIO
    );
    Serial.begin(SERIAL_SPEED);
    Display4Digits* p_display4Digits = new Display4Digits(p_proxy);
    this->m_display4Digits = p_display4Digits;
    this->m_actionDisplayConnection = new ActionDisplayConnection(this->m_display4Digits);
    this->m_connection = new Connection(INTERVAL_5,
                                        this->m_actionDisplayConnection);
    this->m_connection->connectToNetwork();
    this->m_ntpClock = new NTPClock(NTP_SERVER_REGION,
                                    TIMEZONE, UPDATE_INTERVAL
                                   );
    this->m_internalClock = new InternalClock(this->m_ntpClock,
                                              INTERVAL_1);
    this->m_alarmClock = new AlarmClock(this->m_display4Digits,
                                        this->m_internalClock
                                       );
    this->m_actionDisplayAlarms = new ActionDisplayAlarms(this->m_alarmClock);
    this->m_buttonDisplayAlarms = new ButtonDisplayAvailableAlarm(pinButtonAlarms,INTERVAL_40,this->m_actionDisplayAlarms);
}

void Program::loop() {
    this->m_connection->tick();
    this->m_internalClock->tick();
    this->m_alarmClock->run();
    this->m_buttonDisplayAlarms->tick();
}