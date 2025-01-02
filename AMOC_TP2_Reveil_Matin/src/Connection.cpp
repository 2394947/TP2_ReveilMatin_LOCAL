#include "Connection.h"

Connection::Connection(
    uint16_t p_intervalUpdate,
    ActionDisplayConnection *p_actionDisplayConnection) : m_lastUpdate(DEFAUT),
                                                          m_actionDisplayConnection(p_actionDisplayConnection),
                                                          m_intervalUpdate(p_intervalUpdate),
                                                          m_url("inconnu"),
                                                          m_isConnected(false) { ; }

bool Connection::isConnected()
{
  return (WiFi.status() == WL_CONNECTED);
}

String Connection::getURL()
{
  return this->m_url;
}

void Connection::tick()
{
  uint64_t actualTime = millis();
  if (actualTime - this->m_lastUpdate >= this->m_intervalUpdate)
  {
    this->m_lastUpdate = actualTime;
    if (!isConnected())
    {
      Serial.println("Connexion perdue! Tentative de reconnexion...");
      connectToNetwork();
    }
  }
}

void Connection::connectToNetwork()
{

  for (uint8_t network = 0; network < NB_NETWORK && !m_isConnected; ++network)
  {
    uint8_t nbTry = 0;
    Serial.print("Connexion au réseau WiFi: ");
    Serial.println(ssidList[network]);
    WiFi.begin(ssidList[network], passwordList[network]);

    Serial.print("Connexion: [");
    while (nbTry < NB_TRY_MAX && WiFi.status() != WL_CONNECTED)
    {      
      delay(500);
      this->m_actionDisplayConnection->execute();
      Serial.print("=");
      ++nbTry;
    }
    Serial.print("]");
    Serial.println("");

    if (WiFi.status() == WL_CONNECTED)
    {
      this->m_url = urlList[network];
      Serial.print("Connecté au réseau WiFi: ");
      Serial.println(ssidList[network]);
      Serial.print("Adresse IP: ");
      Serial.println(WiFi.localIP());
      Serial.println("");
      m_isConnected = true;
    }
    else
    {
      Serial.print("Échec de connexion au réseau: ");
      Serial.println(ssidList[network]);
    }
  }
}
