#pragma once
#include <Arduino.h>
#include "configNoteTone.h"

class Tetris {                              // Revoir pour couplet répétitifs...
public:
    // Constructeur par défaut
    Tetris() = default;

    // Méthode pour obtenir la mélodie
    const uint16_t* getMelody() const {
        return m_melody;
    }

private:
// Déclaration du tableau comme const pour qu'il soit stocké en mémoire flash
    static const uint16_t m_melody[];
};

const uint16_t Tetris::m_melody[] = {
        // notes of the moledy followed by the duration.
        // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
        // !!negative numbers are used to represent dotted notes,
        // so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!

        // Source:
        // https://github.com/robsoncouto/arduino-songs/tree/master
        
        //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192
  
        NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
        NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
        NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
        NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

        NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
        NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
        NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
        NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

        NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
        NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
        NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
        NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

        NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
        NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
        NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
        NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,
        

        NOTE_E5,2,  NOTE_C5,2,
        NOTE_D5,2,   NOTE_B4,2,
        NOTE_C5,2,   NOTE_A4,2,
        NOTE_GS4,2,  NOTE_B4,4,  REST,8, 
        NOTE_E5,2,   NOTE_C5,2,
        NOTE_D5,2,   NOTE_B4,2,
        NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
        NOTE_GS5,2,

};