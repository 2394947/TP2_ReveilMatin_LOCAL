#pragma once
#include <Arduino.h>
#include "configNoteTone.h"
#include "constantesMelodies.h"

class Melody {  
private:     
    int16_t* m_melody;               
public:
    Melody(int16_t* p_melody);
    int16_t* getMelody() const;
    size_t getMelodyLength() const;
};
