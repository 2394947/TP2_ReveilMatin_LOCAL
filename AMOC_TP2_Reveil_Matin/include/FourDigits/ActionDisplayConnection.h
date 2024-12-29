#pragma once
#include <TM1637Display.h>
#include "Affichage4Digits.h"

class ActionDisplayConnection {
private:
    enum State { SHOW_D, SHOW_G, SHOW_A, CONNECTED }; // États d'affichage
    State m_state;  // État actuel de l'affichage

    int m_lastUpdateTime; // Dernière mise à jour
    int m_interval; // Intervalle entre les états
    Affichage4Digits* m_affichage4Digits;

public:
    ActionDisplayConnection(Affichage4Digits* p_affichage4Digits,int p_interval);

    void displayConnectionAnimation();       // Met à jour l'état et l'affichage
};
