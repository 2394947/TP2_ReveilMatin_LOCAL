#pragma once
#include <Arduino.h>
#include <FS.h>
#include "AlarmManager.h"

class WebServer;

class AlarmWebServer {
 public:
  AlarmWebServer();
  void tick();

 private:
  WebServer* m_webServer;
  AlarmManager* m_alarmManager;       // Gere le fichier des alarmes : ecriture,lecture

  void displayRoot(); // Je s'appelle root xD
  void ressourcesNotFound(String const& p_fileName);
  void initialiseRequestRoutes();
  void getAlarms();
  void addAlarm();
  void deleteAlarm();
  void modifyAlarm();
};