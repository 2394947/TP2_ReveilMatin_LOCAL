# Références
https://docs.arduino.cc/libraries/ntpclient/

https://rtd-debug-zh.readthedocs.io/zh-tw/latest/ambd_arduino/bw16/peripherals_and_examples/Peripheral%20Examples/Use%20NTPClient%20Library%20To%20Obtain%20Local%20Time.html#:~:text=Code%20Reference&text=The%20NTPClient%20needs%20to%20use,and%20update%20interval%20in%20milliseconds.

# WiFiUDP

`WiFiUDP` est une classe fournie par la bibliothèque Arduino pour gérer la communication via le protocole **UDP** (User Datagram Protocol) sur des appareils connectés au Wi-Fi, comme l'ESP32 ou l'ESP8266.

## Fonctions principales de WiFiUDP

- **Création de sockets UDP** : `WiFiUDP` permet d'ouvrir une connexion UDP pour envoyer ou recevoir des paquets de données.
- **Simplicité** : UDP est un protocole sans connexion, ce qui signifie qu'il est rapide mais ne garantit pas la livraison ou l'ordre des paquets.
- **Usage** : Idéal pour des tâches simples comme :
  - Communication avec des serveurs NTP (Network Time Protocol).
  - Échange de données légères où la perte de paquets est tolérable.

---

# NTPClient

`NTPClient` est une bibliothèque qui utilise `WiFiUDP` pour se connecter à un serveur NTP et obtenir l'heure actuelle. Elle est conçue pour simplifier la synchronisation de l'horloge d'un microcontrôleur avec une source fiable comme un serveur NTP.

## Pourquoi utiliser un serveur NTP ?

Un serveur NTP fournit une heure précise en **UTC** (Temps Universel Coordonné) et permet à votre appareil de synchroniser son horloge même s'il n'a pas de module **RTC** (Real-Time Clock).

---

# Relation entre WiFiUDP et NTPClient

- **WiFiUDP comme transport pour NTPClient** :  
  `WiFiUDP` établit la communication entre l'appareil (ESP32) et le serveur NTP via le protocole UDP.

- **NTPClient utilise WiFiUDP** :  
  `NTPClient` envoie une requête UDP à un serveur NTP en utilisant `WiFiUDP`.  
  Le serveur NTP répond avec l'heure actuelle.  
  `NTPClient` interprète et renvoie cette heure au format souhaité.
