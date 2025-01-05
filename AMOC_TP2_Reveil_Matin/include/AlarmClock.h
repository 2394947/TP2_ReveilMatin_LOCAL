#pragma once
#include "FourDigits/Display4Digits.h"
#include "InternalClock.h"
#include "Alarm.h"
#include "AlarmClockController.h"
#include "constantes.h"

class AlarmClock {
private:                         
    AlarmClockController* m_alarmClockController;                                     
    Display4Digits* m_display4Digits;                                          
    InternalClock* m_internalClock;                                            
    uint8_t m_alarmsIndex;                                                           
    void nextAlarm();                                                          
    void displayTime(String p_time);  
    void displayClockTime();                                                   
public:
    AlarmClock(AlarmClockController* p_alarmClockController,
               Display4Digits* p_display4Digits,
               InternalClock* p_internalClock);                                
    Alarm* getLastDisplayedAlarm();
    void displayAvailableAlarms();                                              
    void run();                                                                
};