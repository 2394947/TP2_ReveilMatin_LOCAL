#include "FourDigits/ActionDisplayConnection.h"
#include "config.h"

ActionDisplayConnection::ActionDisplayConnection(Display4Digits* p_display4Digits, int p_interval)
    :  m_display4Digits(p_display4Digits),
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
                this->m_display4Digits->display(0,0,0,0); // Segment d
                m_state = SHOW_G;
                break;
            case SHOW_G:
                this->m_display4Digits->display(1,1,1,1); // Segment g
                m_state = SHOW_A;
                break;
            case SHOW_A:
                this->m_display4Digits->display(2,2,2,2); // Segment a
                m_state = SHOW_D;
                break;
        }
    }
}


