#pragma once
#include <ArduinoJson.h>
#include <LittleFS.h>  // Bibliotheque de gestion de fichiers du systeme de fichiers
#include "constantes.h"

class AlarmManager {    // Jai remplace et simplifie la methode addstaticfile  de serveurWeb par writeAlarm, pas sur si il manque pas qlq chose..
private:
    size_t m_maxSize;
public:
    AlarmManager();
    DynamicJsonDocument readAlarms(); //DyanimicJsonDocument est deprecated, il faudra regarder comment utiliser JsonDocument a la place.
    void writeAlarms(DynamicJsonDocument p_doc);
};