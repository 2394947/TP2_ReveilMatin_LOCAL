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
    this->m_ntpClock = new NTPClock(NTP_SERVER_REGION,
                                    TIMEZONE, UPDATE_INTERVAL
                                   );
    this->m_internalClock = new InternalClock(this->m_ntpClock,
                                              INTERVAL_1);
    this->m_buttonDisplayAlarms = new ButtonDisplayAvailableAlarm(pinButtonAlarms,INTERVAL_40);
    this->m_alarmClock = new AlarmClock(this->m_display4Digits,
                                        this->m_buttonDisplayAlarms
                                       ,this->m_internalClock
                                       );
    this->m_connection = new Connection(INTERVAL_5,
                                        this->m_actionDisplayConnection);
    this->m_connection->connectToNetwork();
}

void Program::loop() {
    this->m_connection->tick();
    this->m_alarmClock->run();
    // this->m_ntpClock->getTime();
}