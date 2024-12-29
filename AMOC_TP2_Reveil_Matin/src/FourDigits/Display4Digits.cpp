#include "FourDigits/Display4Digits.h"

Display4Digits::Display4Digits(Display4DigitsProxy* p_proxy)
    : m_proxy(p_proxy) {;}
 
void Display4Digits::display(
    uint8_t p_d1, 
    uint8_t p_d2,
    uint8_t p_d3,
    uint8_t p_d4
) {
    m_proxy->display(
        p_d1, 
        p_d2,
        p_d3,
        p_d4
    );
}
void Display4Digits::displayInteger(uint8_t p_valeur) {
    m_proxy->displayInteger(p_valeur);
}
    
