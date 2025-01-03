#pragma once
#include "FourDigits/Display4Digits.h"
#include "InternalClock.h"
#include "Alarm.h"
#include "config.h"

class AlarmClock {
private:                       
    Alarm* m_alarms[DEFAULT_NB_ALARMS];                                        
    Display4Digits* m_display4Digits;                                          
    InternalClock* m_internalClock;                                            
    uint8_t m_alarmsIndex;
    void createDefaultAlarms();                                                             
    void nextAlarm();                                                          
    void displayTime();                                                     
public:
    AlarmClock(Display4Digits* p_display4Digits,
               InternalClock* p_internalClock);                                
    Alarm* getLastDisplayedAlarm();
    void showAvailableAlarms();                                                
    void run();                                                                
};