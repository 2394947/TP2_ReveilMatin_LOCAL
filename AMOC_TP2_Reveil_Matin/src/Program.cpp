#include "Program.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

Program::Program()
    : m_connection(nullptr),
      m_realTimeClock(nullptr)
{
    this->m_connection = new Connection(INTERVAL_5);
    Serial.begin(SERIAL_SPEED);
    this->m_connection->connectToNetwork();
    this->m_realTimeClock = new RealTimeClock(NTP_SERVER_REGION, TIMEZONE, UPDATE_INTERVAL);
}

void Program::loop()
{
    this->m_connection->tick();
    this->m_realTimeClock->DisplayTime();
}