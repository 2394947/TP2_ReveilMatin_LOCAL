#include "AlarmWebServer.h"
#include <ArduinoJson.h>
#include <Arduino.h>
#include <WebServer.h>
#include <detail/RequestHandlersImpl.h>


// Note: pour bootstrap, nous pourrions utiliser un CDN ce qui
// - économiserait de l'espace
// - permettrait de gagner du temps de traitement car
// potentiellement déjà dans la cache du navigateur


#ifdef FS_LITTLEFS

#include <LittleFS.h>

#define FS LittleFS

#else

#include <SPIFFS.h>
#define FS SPIFFS

#endif

String toURI(const String &path) {
#ifdef FS_LITTLEFS
  return path;
#else
  // PFL : Le but est ici de gommer les problèmes de SPIFFS qui ne supporte plus les
  // noms de fichiers avec des / pour simuler des répertoires
  // Pour que le fichier HTML fonctionne toujours, vous allons simplement changer l'URI des fichiers
  if (path.endsWith(".css")) {
    return String("/css") + path;
  } else if (path.endsWith(".js")) {
    return String("/js") + path;
  }

  return path;
#endif
}


AlarmWebServer::AlarmWebServer() {
  FS.begin(true);
  this->m_alarmManager = new AlarmManager();
  this->m_webServer = new WebServer(); 
  this->initialiseRequestRoutes();
  this->m_webServer->begin();
}

void AlarmWebServer::tick() { this->m_webServer->handleClient(); }

void AlarmWebServer::ressourcesNotFound(const String& p_ressourceName) {
  Serial.println("Ressource '" + p_ressourceName + "' non trouvée !");
  this->m_webServer->send(404, "text/plain",
                          "Ressource '" + p_ressourceName + "' non trouvée !");
}

void AlarmWebServer::initialiseRequestRoutes() {
  this->m_webServer->on("/alarms", HTTP_GET,[this]() {this->getAlarms(); });
  this->m_webServer->on("/alarms", HTTP_POST,[this]() {this->addAlarm(); });
  this->m_webServer->on("/alarms/{id}",HTTP_DELETE,[this]() {this->deleteAlarm(); });
  this->m_webServer->on("/alarms/{id}", HTTP_PATCH,[this]() {this->modifyAlarm(); }); // Patch permet de faire un changement partiel de l'alarme (actif/inactif) sans l'ecraser:  https://developer.mozilla.org/fr/docs/Web/HTTP/Methods/PATCH
  this->m_webServer->onNotFound([this]() { this->ressourcesNotFound(this->m_webServer->uri()); });
}

void AlarmWebServer::getAlarms() {
  String result = " ";
  DynamicJsonDocument alarms = this->m_alarmManager->readAlarms();
  serializeJson(alarms,result);
  this->m_webServer->send(200, "application/json", result);
}

void AlarmWebServer::addAlarm() {
  String body = this->m_webServer->arg("plain");

  if(body.isEmpty()){
    this->m_webServer->send(400, "text/plain","Requête invalide.");
  }else {
    DynamicJsonDocument alarms = this->m_alarmManager->readAlarms();
    DynamicJsonDocument newAlarm(ALARM_FILE_SIZE);

    DeserializationError error = deserializeJson(newAlarm,body);
    if(error) {
      this->m_webServer->send(400, "text/plain", "Erreur dans le fichier envoyé.");
    }
    alarms.add(newAlarm);
    this->m_alarmManager->writeAlarms(alarms);
  }
}

  // Pour faire ces methodes, il faut etre en mesure de manipuler les id des alarmes. je crois quil
  // faudra dabord ajouter la logique de lactionneur dans AlarmManager avant.

void AlarmWebServer::deleteAlarm() {
  // Todo
}

void AlarmWebServer::modifyAlarm() {
  // Todo
}


