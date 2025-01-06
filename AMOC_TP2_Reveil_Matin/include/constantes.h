#pragma once
#include <Arduino.h>

// Pour le fichier des alarmes
 const char* ALARM_FILE = "/alarms.json";
 const size_t MAX_SIZE = 2048;
 const size_t ALARM_FILE_SIZE = 256;
// Valeurs des pins
#define CLK 25
#define DIO 26
#define RED_PIN   14                        
#define YELLOW_PIN 12
#define BUZZER_PIN 5                        
#define BUTTON1_PIN 17                         
#define BUTTON2_PIN 16                       
#define BUTTON3_PIN 27                         

#define NB_MELODIES 3
#define MAX_NB_ALARMS 10
#define TIMEZONE -5 * 3600
#define UPDATE_INTERVAL 60000
#define NTP_SERVER_REGION "north-america.pool.ntp.org"

// Valeurs des index du tableau DIGITS_ARRAY
#define DIGIT_0 0b00111111
#define DIGIT_1 0b00000110
#define DIGIT_2 0b01011011
#define DIGIT_3 0b01001111
#define DIGIT_4 0b01100110
#define DIGIT_5 0b01101101
#define DIGIT_6 0b01111101
#define DIGIT_7 0b00000111
#define DIGIT_8 0b01111111
#define DIGIT_9 0b01100111
#define DIGIT_A 0b01110111
#define DIGIT_B 0b01111100
#define DIGIT_C 0b00111001
#define DIGIT_D 0b01011110
#define DIGIT_E 0b01111001
#define DIGIT_F 0b01110001
// Valeurs 0 à F incluant un | logique pour ajouter le 7ième bit pour afficher le DP
#define DIGIT_0_OR_DP DIGIT_0 | DIGIT_SEG_DP
#define DIGIT_1_OR_DP DIGIT_1 | DIGIT_SEG_DP
#define DIGIT_2_OR_DP DIGIT_2 | DIGIT_SEG_DP
#define DIGIT_3_OR_DP DIGIT_3 | DIGIT_SEG_DP
#define DIGIT_4_OR_DP DIGIT_4 | DIGIT_SEG_DP
#define DIGIT_5_OR_DP DIGIT_5 | DIGIT_SEG_DP
#define DIGIT_6_OR_DP DIGIT_6 | DIGIT_SEG_DP
#define DIGIT_7_OR_DP DIGIT_7 | DIGIT_SEG_DP
#define DIGIT_8_OR_DP DIGIT_8 | DIGIT_SEG_DP
#define DIGIT_9_OR_DP DIGIT_9 | DIGIT_SEG_DP
#define DIGIT_A_OR_DP DIGIT_A | DIGIT_SEG_DP
#define DIGIT_B_OR_DP DIGIT_B | DIGIT_SEG_DP
#define DIGIT_C_OR_DP DIGIT_C | DIGIT_SEG_DP
#define DIGIT_D_OR_DP DIGIT_D | DIGIT_SEG_DP
#define DIGIT_E_OR_DP DIGIT_E | DIGIT_SEG_DP
#define DIGIT_F_OR_DP DIGIT_F | DIGIT_SEG_DP
#define DIGIT_SEG_D 0b00001000
#define DIGIT_SEG_G 0b01000000
#define DIGIT_SEG_A 0b00000001
#define DIGIT_SEG_DP 0b10000000
#define DIGIT_NULL 0b00000000

// Références des # des index du tableau DIGITS_ARRAY
#define ARRAY_0 0
#define ARRAY_1 1
#define ARRAY_2 2
#define ARRAY_3 3
#define ARRAY_4 4
#define ARRAY_5 5
#define ARRAY_6 6
#define ARRAY_7 7
#define ARRAY_8 8
#define ARRAY_9 9
#define ARRAY_A 10
#define ARRAY_B 11
#define ARRAY_C 12
#define ARRAY_D 13
#define ARRAY_E 14
#define ARRAY_F 15
#define ARRAY_0_OR_DP 16
#define ARRAY_1_OR_DP 17
#define ARRAY_2_OR_DP 18
#define ARRAY_3_OR_DP 19
#define ARRAY_4_OR_DP 20 
#define ARRAY_5_OR_DP 21
#define ARRAY_6_OR_DP 22
#define ARRAY_7_OR_DP 23
#define ARRAY_8_OR_DP 24
#define ARRAY_9_OR_DP 25
#define ARRAY_A_OR_DP 26
#define ARRAY_B_OR_DP 27
#define ARRAY_C_OR_DP 28
#define ARRAY_D_OR_DP 29
#define ARRAY_E_OR_DP 30
#define ARRAY_F_OR_DP 31
#define ARRAY_SEG_D 32
#define ARRAY_SEG_G 33
#define ARRAY_SEG_A 34
#define ARRAY_SEG_DP 35
#define ARRAY_NULL 36

// Saut entre les valeurs std et les valeurs avec DP
#define OR_DP 16

// Tableau contenant les valeurs utilisées pour l'affichage de Display4Digits, plus qu'il n'en faut, peut être utilisé à d'autres fins
const uint8_t DIGITS_ARRAY[ARRAY_NULL + 1] = {
        DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4, DIGIT_5, DIGIT_6, DIGIT_7,
        DIGIT_8, DIGIT_9, DIGIT_A, DIGIT_B, DIGIT_C, DIGIT_D, DIGIT_E, DIGIT_F,
        DIGIT_0_OR_DP, DIGIT_1_OR_DP, DIGIT_2_OR_DP, DIGIT_3_OR_DP, DIGIT_4_OR_DP,
        DIGIT_5_OR_DP, DIGIT_6_OR_DP, DIGIT_7_OR_DP, DIGIT_8_OR_DP, DIGIT_9_OR_DP,
        DIGIT_A_OR_DP, DIGIT_B_OR_DP, DIGIT_C_OR_DP, DIGIT_D_OR_DP, DIGIT_E_OR_DP,
        DIGIT_F_OR_DP, DIGIT_SEG_D, DIGIT_SEG_G, DIGIT_SEG_A, DIGIT_SEG_DP, DIGIT_NULL 
        };

#define SERIAL_SPEED 115200                 // vitesse Serial pour ESP32

#define INTERVAL_5 5000                     // 5 secondes
#define INTERVAL_4 4000                     // 4 secondes
#define INTERVAL_3 3000                     // 3 secondes
#define INTERVAL_2 2000                     // 2 secondes
#define INTERVAL_1 1000                     // 1 secondes
#define INTERVAL_500 500                    // 500 millis secondes
#define INTERVAL_50 50                      // 50 millis secondes
#define INTERVAL_40 40                      // 40 millis secondes
#define INTERVAL_30 30                      // 30 millis secondes
#define DEFAULT 0                           // Hey ben... un simple "0"!

// Constantes pour la lectures des mélodies, valeurs des variables isolé de la source:
// https://github.com/robsoncouto/arduino-songs/tree/master
#define TEMPO 195                           // Vitesse par défaut de la mélodie
#define WHOLE_NOTE ((60000 * 4) / TEMPO)    // Durée d'une note entière en ms
#define DIVIDER DEFAULT                     // Valeur par défaut du diviseur 
#define NOTE_DURATION DEFAULT               // Durée par défaut d'une note
