#include "Program.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

Program::Program()
    : m_connection(nullptr),
      m_realTimeClock(nullptr)
{
    Display4DigitsProxy* p_proxy = new Display4DigitsProxyTM1637(
    CLK,
    DIO
    );
    Display4Digits* p_display4Digits = new Display4Digits(p_proxy);
    this->m_display4Digits = p_display4Digits;
    this->m_actionDisplayConnection = new ActionDisplayConnection(this->m_display4Digits);
    this->m_connection = new Connection(INTERVAL_5,this->m_actionDisplayConnection);
    Serial.begin(SERIAL_SPEED);
    this->m_connection->connectToNetwork();
    this->m_realTimeClock = new RealTimeClock(NTP_SERVER_REGION, TIMEZONE, UPDATE_INTERVAL);
}

void Program::loop()
{
    this->m_connection->tick();
    this->m_realTimeClock->getTime();
}