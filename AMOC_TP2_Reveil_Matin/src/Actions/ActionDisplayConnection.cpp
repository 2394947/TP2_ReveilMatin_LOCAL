#include "Actions/ActionDisplayConnection.h"
#include "constantes.h"

ActionDisplayConnection::ActionDisplayConnection(Display4Digits* p_display4Digits)
    :  m_display4Digits(p_display4Digits),
       m_state(SHOW_D) { 
        ;
}

void ActionDisplayConnection::execute() {
        
        switch (m_state) {
            case SHOW_D:
                this->m_display4Digits->display(TAB_SEG_D, TAB_SEG_D, TAB_SEG_D, TAB_SEG_D); // Segment d
               m_state = SHOW_G;
                break;
            case SHOW_G:
                this->m_display4Digits->display(TAB_SEG_G, TAB_SEG_G, TAB_SEG_G, TAB_SEG_G); // Segment g
                m_state = SHOW_A;
                break;
            case SHOW_A:
                this->m_display4Digits->display(TAB_SEG_A, TAB_SEG_A, TAB_SEG_A, TAB_SEG_A); // Segment a
                m_state = SHOW_D;
                break;
        }
}


