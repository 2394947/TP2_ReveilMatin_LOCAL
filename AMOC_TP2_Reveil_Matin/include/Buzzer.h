#pragma once
#include <Arduino.h>
#include "constantes.h"

class Buzzer {
private:
    uint8_t m_pin;
    const int16_t* m_melody;
    size_t m_melodyLength;
    size_t m_currentNoteIndex;
    uint16_t m_noteDuration;
    
    uint64_t m_lastUpdateTime;

public:
    Buzzer(uint8_t p_pin);
    bool m_isPlaying;
    void playMelody(const int16_t* melodyArray, size_t length);
    void stopMelody();
    bool isPlaying() const;
    void tick();
};