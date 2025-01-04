#include "AlarmManager.h"

AlarmManager::AlarmManager()
: m_maxSize(MAX_SIZE) { ; }

DynamicJsonDocument AlarmManager::readAlarms() {    //Ouvre le fichier des alarmes en mode lecture et les renvoi dans un document Json.             
    File alarmFile = LittleFS.open(ALARM_FILE, "r");     // Pour le vocabulaire de manipulation de fichier : https://randomnerdtutorials.com/esp32-write-data-littlefs-arduino/
    if(!alarmFile) {
        Serial.println("Fichier d'alarmes inexistant, creation du fichier...");  // Debug pour voir le fonctionnement
        return DynamicJsonDocument(m_maxSize);
    }

    DynamicJsonDocument doc(this->m_maxSize);
    DeserializationError error = deserializeJson(doc,alarmFile);
    alarmFile.close();

    if(error) {
        Serial.println("Erreur lors de la lecture du fichier.");
        return DynamicJsonDocument(m_maxSize);
    }

    return doc;  
}

 void AlarmManager::writeAlarms(DynamicJsonDocument p_doc) { // Ouvre le fichier d'alarmes en mode ecriture "w" et insere les nouvelles alarmes. {
    File alarmFile = LittleFS.open(ALARM_FILE, "W");
     if(!alarmFile) {
        Serial.println("Fichier d'alarmes inexistant, ecriture impossible.");  // Debug pour voir le fonctionnement
    }else {
        serializeJson(p_doc,alarmFile);
    }
    alarmFile.close();
}