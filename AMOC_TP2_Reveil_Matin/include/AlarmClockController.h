#pragma once
#include "Alarm.h"
#include "constantes.h"
#include "Connection.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <algorithm>

class AlarmClockController {
private:
    String m_urlBase;
    Connection* m_connection;
    uint64_t m_lastUpdate; 
    uint16_t m_intervalUpdate;    
    void deserializeAlarms(String p_jsonAlarms);
    bool doesAlarmExists(String p_time);
public:
    Alarm* m_alarms[MAX_NB_ALARMS];
    AlarmClockController(
        Connection* p_connection,
        uint16_t p_m_intervalUpdate
        );
    void getAlarmsAPI();
    void displayAlarmsTimeAsc();
    void setAlarm(String p_time);
    void unsetAlarm(String p_time);
    void updateAlarm(String p_oldTime, String p_newTime);
    void deleteAlarm(String p_time);
    void getURL();
    void tick();
};