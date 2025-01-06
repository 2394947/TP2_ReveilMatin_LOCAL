#pragma once
#include <Arduino.h>
#include "constantes.h"
#include "Buzzer.h"
#include "Melody/Melody.h"

class AlarmMelodies {
private:
    bool m_isAlarmActive;
    uint8_t m_nbSnoozes;
    uint8_t m_melodyIndex;
    Buzzer* m_buzzer;
    int16_t m_delay1;
    int16_t m_delay2;
    uint64_t m_lastUpdate;
    int16_t* m_melodyArray[NB_MELODIES];
    size_t m_melodyLength[NB_MELODIES];
    void setMelodyIndex();
    void playMelody();
    void stopMelody();

public:
    AlarmMelodies(
        uint16_t p_delay1,
        uint16_t p_delay2,
        Buzzer* p_buzzer
        );
    void activateAlarm();
    void deactivateAlarm(); 
    void snooze();
    void tick();  
};