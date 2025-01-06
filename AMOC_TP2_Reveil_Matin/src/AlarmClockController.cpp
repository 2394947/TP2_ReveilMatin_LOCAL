#include "AlarmClockController.h"

AlarmClockController::AlarmClockController(
    Connection* p_connection,
    uint16_t p_intervalUpdate
) :
    m_alarms(nullptr),
    m_urlBase(" "),
    m_connection(p_connection),
    m_lastUpdate(DEFAULT),
    m_intervalUpdate(p_intervalUpdate) { ; }

void AlarmClockController::getUrl() {
    this->m_urlBase = this->m_connection->getUrl();
    Serial.println(this->m_urlBase);
}

void AlarmClockController::getAlarmsAPI() {
    HTTPClient http;
    String url = this->m_urlBase + ALARM_FILE;

    http.begin(url);
    int resultCode = http.GET();

    if(resultCode == 200) {
        this->deserializeAlarms(http.getString());
    }
}

void AlarmClockController::deserializeAlarms(String p_json) {
    DynamicJsonFocument doc(MAX_SIZE);

    DeserializationError error = deserializeJson(doc,p_json);
    Alarm* alarmsFromJson = new Alarm[MAX_NB_ALARMS];

    uint8_t index= 0;
    if(!error) {
      JsonArray jsonAlarms = doc.as<JsonArray>();
      for(JsonObject obj : array){
        Alarm* newAlarm = new Alarm(
            obj["time"],
            obj["isActive"]
            );     
        alarmsFromJson[index] = newAlarm;
        index++;
      }
      for(uint8_t index; index<MAX_NB_ALARMS;index++) {
        if(alarmsFromJson[index].time != this->m_alarms[index].time)    // alarmsFromJson     m_alarms
      }                                                                 //     12:30            08:20
    }
}

bool AlarmClockController::doesAlarmExists(String p_time) {
    uint8_t arrayLength = sizeof(this->m_alarms) / sizeof(this->m_alarms[0]);

    for(uint8_t index ; index < arrayLength; index++) {
        if(this->m_alarms[index]->getTime() == p_time) {
            return true;
        }
    }

    return false;
}

void AlarmClockController::setAlarm(String p_time) {
    bool alarmExists = this->doesAlarmExists(p_time);
    String url = alarmExists ? this->m_urlBase + ALARM_FILE : this->m_urlBase + ALARM_FILE + "/" + p_time;

    HTTPClient http;
    http.begin(url);
    http.addHeader("content-type", "application/json")
    int resultCode = alarmExists ? http.PATCH("{\"isActive\":\"true\"}") : http.POST("{\"\"time\":" + p_time + ",isActive\":\"true\"}");

    if(resultCode == 200) {
        Serial.println("Alarme activée.");
    }
    else {
        Serial.println("Erreur PUT pour activer, code : " + String(resultCode));
    }
    http.end();
} 

void AlarmClockController::unsetAlarm(String p_time) {
    String url = this->m_urlBase + ALARM_FILE + "/" + p_time;

    HTTPClient http;
    http.begin(url);
    http.addHeader("content-type", "application/json")
    int resultCode = http.PATCH("{\"isActive\":\"false\"}");

    if(resultCode == 200) {
        Serial.println("Alarme activée.");
    }
    else {
        Serial.println("Erreur PUT pour désactiver, code : " + String(resultCode));
    }
    http.end();     
}

void AlarmClockController::deleteAlarm(String p_time) {
    String url = this->m_urlBase + ALARM_FILE + "/" + p_time;

    HTTPClient http;
    http.begin(url);
    http.addHeader("content-type", "application/json")
    int resultCode = http.DELETE();

    if(resultCode == 200) {
        Serial.println("Alarme supprimée.");
    }
    else {
        Serial.println("Erreur DELETE pour supprimer, code : " + String(resultCode));
    }
    http.end(); 
}

void AlarmClockController::updateAlarm(String p_oldTime, String p_newTime) {
    String url = this->m_urlBase + ALARM_FILE + "/" + p_oldTime;

    HTTPClient http;
    http.begin(url);
    http.addHeader("content-type", "application/json")
    int resultCode = http.PATCH("{\"\"time\":" + p_newTime + "}");

    if(resultCode == 200) {
        Serial.println("Alarme modifiée.");
    }
    else {
        Serial.println("Erreur PATCH pour modifier, code : " + String(resultCode));
    }
    http.end(); 
}

void AlarmClockManager::displayAlarmsTimeAsc() {
    uint8_t arrayLength = sizeof(this->m_alarms) / sizeof(this->m_alarms[0]);
    Alarm* alarmsToDisplay = new ALarm[arrayLength];
    std::sort(alarmsToDisplay, alarmsToDisplay + arrayLength);

    String hours = "";
    String minutes = "";
    String state = "";

    for(uint8_t index ; index < arrayLength; index++) {
        hours = alarmsToDisplay[index].getTime().substring(0,2);
        minutes = alarmsToDisplay[index].getTime().substring(2,4);
        state = alarmsToDisplay[index].isActivated() ? "Active" : "Inactive";
        Serial.println("Time : " hours + ":" + minutes + " State : " + state);
    }
}

void AlarmClockController::tick() {
    uint64_t actualTime = millis();
    if (actualTime - this->m_lastUpdate >= this->m_intervalUpdate) {
        this->m_lastUpdate = actualTime;
        getAlarmsAPI();
    }
}