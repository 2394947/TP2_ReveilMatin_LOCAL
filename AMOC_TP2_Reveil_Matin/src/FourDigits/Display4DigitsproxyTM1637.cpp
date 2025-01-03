#include "FourDigits/Display4DigitsProxyTM1637.h"
#include "constantes.h"

Display4DigitsProxyTM1637::Display4DigitsProxyTM1637(
    uint8_t p_clockPin,
    uint8_t p_dataPin
) : 
    m_clockPin(p_clockPin),
    m_dataPin(p_dataPin) { 
        m_tm1637 = new TM1637Display(
            p_clockPin, 
            p_dataPin
            );} 
            
void Display4DigitsProxyTM1637::display(
    uint8_t p_d1, 
    uint8_t p_d2,
    uint8_t p_d3,
    uint8_t p_d4
) {
    uint8_t segment[4] = {m_entiersTab[p_d1], m_entiersTab[p_d2], m_entiersTab[p_d3], m_entiersTab[p_d4]};
    m_tm1637->setSegments(segment);
}
void Display4DigitsProxyTM1637::displayInteger( uint8_t p_valeur) {
    uint8_t segment[4] = {m_entiersTab[TAB_NULL], m_entiersTab[TAB_NULL], m_entiersTab[TAB_NULL], m_entiersTab[p_valeur]};
    m_tm1637->setSegments(segment);
}
