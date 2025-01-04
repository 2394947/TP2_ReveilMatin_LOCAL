#include "Buzzer.h"

Buzzer::Buzzer(uint8_t pin) 
  : m_pin(pin), 
  m_currentNoteIndex(DEFAULT), 
  m_isPlaying(false), 
  m_lastUpdateTime(DEFAULT) {
    pinMode(m_pin, OUTPUT);
}

// Source:
// https://github.com/robsoncouto/arduino-songs/tree/master
// Voir aussi fichier TempCodeAUtiliserPourJouerMelodies dans le répertoire 
// include/Melody pour voir la version impérative du code de la source
void Buzzer::playMelody(const int16_t* melodyArray, size_t length) {
    m_melody = melodyArray;
    m_melodyLength = length;
    m_currentNoteIndex = 0;
    m_isPlaying = true;
    m_lastUpdateTime = millis();
}

void Buzzer::stopMelody() {
    noTone(m_pin);
    m_isPlaying = false;
}

bool Buzzer::isPlaying() const {
    return m_isPlaying;
}

void Buzzer::tick() {
    if (!m_isPlaying || m_currentNoteIndex >= m_melodyLength) {
        return;
    }

    uint64_t actualTime = millis();
    if (actualTime - m_lastUpdateTime >= m_noteDuration) {
        // Passer à la note suivante
        m_lastUpdateTime = actualTime;
        m_currentNoteIndex += 2;

        if (m_currentNoteIndex < m_melodyLength) {
            int note = pgm_read_word_near(m_melody + m_currentNoteIndex);
            int divider = pgm_read_word_near(m_melody + m_currentNoteIndex + 1);

            if (divider > 0) {
                // Note régulière
                m_noteDuration = WHOLE_NOTE / divider;
            } else if (divider < 0) {
                // Note pointée
                m_noteDuration = WHOLE_NOTE / abs(divider);
                m_noteDuration *= 1.5;
            }

            m_noteDuration *= 0.9; // Jouer la note pendant 90% de sa durée

            if (note > 0) {
                tone(m_pin, note, m_noteDuration);
            }
        } else {
            // Fin de la mélodie
            stopMelody();
        }
    }
}
