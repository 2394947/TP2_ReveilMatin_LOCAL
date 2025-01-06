#include "Melody/Melody.h"

Melody::Melody(int16_t* p_melody) : m_melody(p_melody) { ; }

int16_t* Melody::getMelody() const {
        return m_melody;
}

size_t Melody::getMelodyLength() const {
        return sizeof(m_melody) / sizeof(m_melody[0]);
}