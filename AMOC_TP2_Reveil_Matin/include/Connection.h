#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include "config.h"
#include "ActionDisplayConnection.h"

class Connection {
private:
    uint16_t m_lastUpdate; 
    uint16_t m_intervalUpdate;
    String m_url;
    bool m_isConnected;
    ActionDisplayConnection* m_actionDisplayConnection;
public:
    bool isConnected();
    Connection(uint16_t p_intervalUpdate, ActionDisplayConnection* p_actionDisplayConnection);
    void connectToNetwork();
    String getURL();
    void tick();
};