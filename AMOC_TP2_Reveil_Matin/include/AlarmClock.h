#pragma once
#include "FourDigits/Display4Digits.h"
#include "Buttons/ButtonDisplayAvailableAlarm.h"
#include "RealTimeClock.h"
#include "Alarm.h"
#include "config.h"

class AlarmClock {
private:
    ButtonDisplayAvailableAlarm* m_buttonDisplayAlarm;                         // Le bouton 1 du reveil, affiche les alarmes crees.
    Alarm* m_alarms[DEFAULT_NB_ALARMS];                                        // Le tableau d'alarmes, voir l'objet Alarm.
    Display4Digits* m_display4Digits;                                          // Le FourDigits qui affiche l'heure actuelle/ les alarmes.
    RealTimeClock* m_realTimeClock;                                            // L'horloge du reveil qui affiche lheure actuelle.
    uint8_t m_alarmsIndex;                                                     // En lien avec le bouton 1, Un index pour savoir on est rendu a afficher quelle alarme.
public:
    AlarmClock(Display4Digits* p_display4Digits,
               ButtonDisplayAvailableAlarm* p_buttonDisplayAlarm,
               RealTimeClock* p_realTimeClock,
                Alarm* p_alarms[DEFAULT_NB_ALARMS]);                           //Je me suis dis quon pourrait creer un tableau dalarmes par defaut dans le program.cpp ou config.h
    void ShowAvailableAlarms();                                                // En lien avec le bouton 1, affichera la prochaine alarme a chaque pression.
    void nextAlarm();                                                          // En lien avec le bouton 1, Incremente lindex du tableau des alarmes
    void run();                                                                // Met en marche le reveil Matin, sera mise dans loop() pour savoir quoi faire selon quel boutton est presse.. a suivre  
};