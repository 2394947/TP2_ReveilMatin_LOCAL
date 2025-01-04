#pragma once
#include <Arduino.h>

#define WIFI_SSID_1 "SM-A520W3658"          // Réseau cell William "chalet"
#define WIFI_PASSWORD_1 "jqfv5091"

#define WIFI_SSID_2 "jennino2.4"            // Réseau chez Jenn
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

