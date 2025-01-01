#pragma once
#include <TM1637Display.h>
#include "FourDigits/Display4Digits.h"

class ActionDisplayConnection {
private:
    enum State { SHOW_D, SHOW_G, SHOW_A, CONNECTED }; // États d'affichage
    State m_state;  // État actuel de l'affichage

    int m_lastUpdateTime; // Dernière mise à jour
    int m_interval; // Intervalle entre les états
    Display4Digits* m_display4Digits;

public:
    ActionDisplayConnection(Display4Digits* p_display4Digits,int p_interval);

    void displayConnectionAnimation();       // Met à jour l'état et l'affichage
};
