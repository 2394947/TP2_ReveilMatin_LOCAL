#pragma once
#include <ArduinoJson.h>
#include <LittleFS.h>
#include "constantes.h"

class AlarmManager {    // Inspiré de la methode addstaticfile de serveurWeb
private:
    size_t m_maxSize;
public:
    AlarmManager();
    DynamicJsonDocument readAlarms();
    void writeAlarms(DynamicJsonDocument p_doc);
};