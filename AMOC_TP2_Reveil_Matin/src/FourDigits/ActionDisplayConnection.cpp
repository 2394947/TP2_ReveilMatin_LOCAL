#include "FourDigits/ActionDisplayConnection.h"
#include "config.h"

ActionDisplayConnection::ActionDisplayConnection(Affichage4Digits* p_affichage4Digits, int p_interval)
    :  m_affichage4Digits(p_affichage4Digits),
       m_interval(p_interval){ 
        this->m_lastUpdateTime = 0;
}

void ActionDisplayConnection::displayConnectionAnimation() {
    unsigned long currentTime = millis();

    if (currentTime - m_lastUpdateTime >= m_interval) {
        m_lastUpdateTime = currentTime;

        // Gestion des animations avant la connexion
        switch (m_state) {
            case SHOW_D:
                this->m_affichage4Digits->afficher(0,0,0,0); // Segment d
                m_state = SHOW_G;
                break;
            case SHOW_G:
                this->m_affichage4Digits->afficher(1,1,1,1); // Segment g
                m_state = SHOW_A;
                break;
            case SHOW_A:
                this->m_affichage4Digits->afficher(2,2,2,2); // Segment a
                m_state = SHOW_D;
                break;
        }
    }
}


