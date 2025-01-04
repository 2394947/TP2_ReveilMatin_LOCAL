#pragma once
#include <Arduino.h>
#include <FS.h>

class WebServer;

class AlarmWebServer {
 public:
  AlarmWebServer();
  void tick();

 private:
  WebServer* m_webServer;
};