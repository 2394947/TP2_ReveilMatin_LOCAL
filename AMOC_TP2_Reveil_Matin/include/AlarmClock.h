#pragma once
#include "FourDigits/Display4Digits.h"
#include "Buttons/ButtonDisplayAvailableAlarm.h"
#include "InternalClock.h"
#include "Alarm.h"
#include "config.h"

class AlarmClock {
private:
    ButtonDisplayAvailableAlarm* m_buttonDisplayAlarm;                         
    Alarm* m_alarms[DEFAULT_NB_ALARMS];                                        
    Display4Digits* m_display4Digits;                                          
    InternalClock* m_internalClock;                                            
    uint8_t m_alarmsIndex;
    void createDefaultAlarms();                                                             
    void ShowAvailableAlarms();                                                
    void nextAlarm();                                                          
    void DisplayTime();                                                     
public:
    AlarmClock(Display4Digits* p_display4Digits,
               ButtonDisplayAvailableAlarm* p_buttonDisplayAlarm,
               InternalClock* p_internalClock);                                
    void run();                                                                
};