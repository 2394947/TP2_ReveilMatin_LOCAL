#pragma once
#include <Arduino.h>

#define CLK 25
#define DIO 26
#define RED_PIN   14                        
#define YELLOW_PIN 12
#define BUZZER_PIN 13                        
#define BUTTON1_PIN 17                         
#define BUTTON2_PIN 16                       
#define BUTTON3_PIN 27                         

#define DEFAULT_NB_ALARMS 5
#define TIMEZONE -5 * 3600
#define UPDATE_INTERVAL 60000
#define NTP_SERVER_REGION "north-america.pool.ntp.org"

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
#define DIGIT_SEG_D 0b00001000
#define DIGIT_SEG_G 0b01000000
#define DIGIT_SEG_A 0b00000001
#define DIGIT_SEG_DP 0b10000000
#define DIGIT_NULL 0b00000000

#define TAB_0 0
#define TAB_1 1
#define TAB_2 2
#define TAB_3 3
#define TAB_4 4
#define TAB_5 5
#define TAB_6 6
#define TAB_7 7
#define TAB_8 8
#define TAB_9 9
#define TAB_A 10
#define TAB_B 11
#define TAB_C 12
#define TAB_D 13
#define TAB_E 14
#define TAB_F 15
#define TAB_SEG_D 16
#define TAB_SEG_G 17
#define TAB_SEG_A 18
#define TAB_SEG_DP 19
#define TAB_NULL 20

const uint8_t m_entiersTab[21] = {
        DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3,
        DIGIT_4, DIGIT_5, DIGIT_6, DIGIT_7,
        DIGIT_8, DIGIT_9, DIGIT_A, DIGIT_B,
        DIGIT_C, DIGIT_D, DIGIT_E, DIGIT_F,
        DIGIT_SEG_D, DIGIT_SEG_G, DIGIT_SEG_A, 
        DIGIT_SEG_DP, DIGIT_NULL };

#define SERIAL_SPEED 115200                 // vitesse Serial pour ESP32

#define INTERVAL_5 5000                     // 5 secondes
#define INTERVAL_4 4000                     // 4 secondes
#define INTERVAL_3 3000                     // 3 secondes
#define INTERVAL_2 2000                     // 2 secondes
#define INTERVAL_1 1000                     // 1 secondes
#define INTERVAL_50 50                      // 50 millis secondes
#define INTERVAL_40 40                      // 40 millis secondes
#define INTERVAL_30 30                      // 30 millis secondes
#define DEFAULT 0
