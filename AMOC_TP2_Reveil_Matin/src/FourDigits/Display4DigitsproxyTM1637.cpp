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
    uint8_t segment[4] = {DIGITS_ARRAY[p_d1], DIGITS_ARRAY[p_d2], DIGITS_ARRAY[p_d3], DIGITS_ARRAY[p_d4]};
    m_tm1637->setSegments(segment);
}
void Display4DigitsProxyTM1637::displayInteger( uint8_t p_valeur) {
    uint8_t segment[4] = {DIGITS_ARRAY[ARRAY_NULL], DIGITS_ARRAY[ARRAY_NULL], DIGITS_ARRAY[ARRAY_NULL], DIGITS_ARRAY[p_valeur]};
    m_tm1637->setSegments(segment);
}
