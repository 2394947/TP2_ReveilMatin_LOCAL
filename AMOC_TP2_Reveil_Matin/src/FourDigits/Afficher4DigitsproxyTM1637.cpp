#include "FourDigits/Affichage4DigitsProxyTM1637.h"
#include "config.h"

Affichage4DigitsProxyTM1637::Affichage4DigitsProxyTM1637(
    uint8_t p_pinHorloge,
    uint8_t p_pinDonnees
) : 
    m_pinHorloge(p_pinHorloge),
    m_pinDonnees(p_pinDonnees) { 
        m_tm1637 = new TM1637Display(
            p_pinHorloge, 
            p_pinDonnees
            );} 
            
void Affichage4DigitsProxyTM1637::afficher(
    uint8_t p_d1, 
    uint8_t p_d2,
    uint8_t p_d3,
    uint8_t p_d4
) {
    uint8_t segment[4] = {m_entiersTab[p_d1], m_entiersTab[p_d2], m_entiersTab[p_d3], m_entiersTab[p_d4]};
    m_tm1637->setSegments(segment);
}
void Affichage4DigitsProxyTM1637::afficherEntier( uint8_t p_valeur) {
    uint8_t segment[4] = {m_entiersTab[16], m_entiersTab[16], m_entiersTab[16], m_entiersTab[p_valeur]};
    m_tm1637->setSegments(segment);
}
