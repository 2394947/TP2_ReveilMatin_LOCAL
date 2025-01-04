#include "Program.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

Program::Program()
  : m_connection(nullptr),
    m_ntpClock(nullptr) {
        Display4DigitsProxy* p_proxy = new Display4DigitsProxyTM1637(
            CLK,
            DIO
            );
        Serial.begin(SERIAL_SPEED);
        this->m_yellowLED = new LED(YELLOW_PIN);
        this->m_redLED = new LED(RED_PIN);
        this->m_display4Digits = new Display4Digits(p_proxy);
        this->m_actionDisplayConnection = new ActionDisplayConnection(this->m_display4Digits);
        this->m_connection = new Connection(
            INTERVAL_5,
            this->m_actionDisplayConnection);
        this->m_connection->connectToNetwork();
        this->m_ntpClock = new NTPClock(
            NTP_SERVER_REGION,
            TIMEZONE, UPDATE_INTERVAL
            );
        this->m_internalClock = new InternalClock(
            this->m_ntpClock,
            INTERVAL_1
            );
        this->m_alarmClock = new AlarmClock(
            this->m_display4Digits,
            this->m_internalClock
            );
        this->m_actionDisplayAlarms = new ActionDisplayAlarms(this->m_alarmClock);
        this->m_actionDisplayLEDs = new ActionDisplayLEDs(
            this->m_yellowLED,
            this->m_redLED,
            this->m_alarmClock
            );
        this->m_actionActivateAlarm = new ActionActivateAlarm(this->m_alarmClock);
        this->m_buttonDisplayAlarms = new ButtonDisplayAvailableAlarm(
            BUTTON1_PIN,
            INTERVAL_40,
            this->m_actionDisplayAlarms,
            this->m_actionDisplayLEDs
            );
        this->m_buttonActivateAlarm = new ButtonActivateAlarm(
            BUTTON2_PIN,
            INTERVAL_40,
            this->m_actionActivateAlarm
            );
}

// void Program::setupCore1Task() {
//     xTaskCreatePinnedToCore(
//         runInternalClockTask,
//         "InternalClockTask",
//         8192,
//         this->m_internalClock,
//         1, // priorité (1 à 5, 1 étant la plus haute)
//         nullptr,
//         1   // cœur 1
//     );
// }

void Program::loop() {
    this->m_connection->tick();
    this->m_internalClock->tick();
    this->m_alarmClock->run();
    this->m_buttonDisplayAlarms->tick();
    this->m_buttonActivateAlarm->tick();
}

// void Program::runInternalClockTask(void* parameter) {
//     InternalClock* internalClock = static_cast<InternalClock*>(parameter);
//     internalClock->run(); 
//     vTaskDelete(nullptr); 
// }