#pragma once
#include <Arduino.h>
#include "configNoteTone.h"

class SuperMarioBros {                      
public:
    SuperMarioBros();
    int16_t* getMelody() const;
    size_t getMelodyLength() const;

private:
    // Déclaration du tableau comme const pour qu'il soit stocké en mémoire flash
    static int16_t m_melody[];
};
