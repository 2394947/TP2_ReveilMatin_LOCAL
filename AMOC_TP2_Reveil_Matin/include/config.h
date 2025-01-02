#pragma once
#include <Arduino.h>

#define DEFAULT_NB_ALARMS 5
#define CLK 25
#define DIO 26
#define TIMEZONE -5 * 3600
#define UPDATE_INTERVAL 60000
#define NTP_SERVER_REGION "north-america.pool.ntp.org"

const uint8_t m_entiersTab[20] = {
        0b00111111, 0b00000110, 0b01011011, 0b01001111, 
        0b01100110, 0b01101101, 0b01111101, 0b00000111, 
        0b01111111, 0b01100111, 0b01110111, 0b01111100, 
        0b00111001, 0b01011110, 0b01111001, 0b01110001, 
        0b00000000, 0b00000001, 0b00001000, 0b10000000 };


#define SERIAL_SPEED 115200                 // vitesse Serial pour ESP32

#define INTERVAL_5 5000                     // 5 secondes
#define INTERVAL_4 4000                     // 4 secondes
#define INTERVAL_3 3000                     // 3 secondes
#define INTERVAL_2 2000                     // 2 secondes
#define INTERVAL_1 1000                     // 1 secondes
#define INTERVAL_50 50                      // 50 millis secondes
#define INTERVAL_40 40                      // 40 millis secondes
#define INTERVAL_30 30                      // 30 millis secondes
#define DEFAUT 0

#define RED_PIN 25                          // digit/analog
#define GREEN_PIN 26                        // digit/analog
#define BLUE_PIN 17                         // digit/analog
// #define BUZZER_PIN                          // analog
// #define BUTTON1_PIN                         // digit/analog
// #define BUTTON2_PIN                         // digit/analog
// #define BUTTON3_PIN                         // digit/analog

#define WIFI_SSID_1 "SM-A520W3658"          // Réseau cell William "chalet"
#define WIFI_PASSWORD_1 "jqfv5091"

#define WIFI_SSID_2 "jennino2.4"      // Réseau chez Jenn
#define WIFI_PASSWORD_2 "willino.com"

#define WIFI_SSID_3 "TELUS5C4F"             // Réseau chez William
#define WIFI_PASSWORD_3 "fuTcD3YBUJSY"

#define WIFI_SSID_4 "iot_lab"               // Réseau Local 408
#define WIFI_PASSWORD_4 "engagelejeuquejelegagne"

#define URL_API_1 "http:// what ever "      // ip localhost cell chalet      
#define URL_API_2 "http://192.168.137.1:80" // ip localhost maison Jenn
#define URL_API_3 "http://192.168.1.75:80"  // ip localhost maison William
#define URL_API_4 "http://192.168.24.1:80"  // ip réservé local 408

#define NB_NETWORK 4
#define NB_TRY_MAX 20                       // Tableaux pour connexions

const String ssidList[NB_NETWORK] = {WIFI_SSID_1, WIFI_SSID_2, WIFI_SSID_3, WIFI_SSID_4 };
const String passwordList[NB_NETWORK] = { WIFI_PASSWORD_1, WIFI_PASSWORD_2, WIFI_PASSWORD_3,WIFI_PASSWORD_4 };
const String urlList[NB_NETWORK] = {URL_API_1, URL_API_2, URL_API_3, URL_API_4 };

