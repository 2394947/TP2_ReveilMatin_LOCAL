#include "Program.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

// size_t melodyCount = 0;
// size_t currentMelodyIndex = 0;

Program::Program()
  : m_connection(nullptr),
    m_ntpClock(nullptr) {
        Display4DigitsProxy* p_proxy = new Display4DigitsProxyTM1637(
            CLK,
            DIO
            );
        Serial.begin(SERIAL_SPEED);
        this->m_yellowFlicker = new Flicker(YELLOW_PIN,INTERVAL_500,INTERVAL_500);
        this->m_redLED = new LED(RED_PIN);
        this->m_display4Digits = new Display4Digits(p_proxy);
        this->m_actionDisplayConnection = new ActionDisplayConnection(this->m_display4Digits);
        this->m_connection = new Connection(
            INTERVAL_5,
            this->m_actionDisplayConnection);
        this->m_connection->connectToNetwork();
        this->m_ntpClock = new NTPClock(
            NTP_SERVER_REGION,
            TIMEZONE, UPDATE_INTERVAL
            );
        this->m_internalClock = new InternalClock(
            this->m_ntpClock,
            INTERVAL_1
            );
        this->m_alarmClock = new AlarmClock(
            this->m_display4Digits,
            this->m_internalClock
            );
        this->m_actionDisplayAlarms = new ActionDisplayAlarms(this->m_alarmClock);
        this->m_actionDisplayLEDs = new ActionDisplayLEDs(
            this->m_yellowFlicker,
            this->m_redLED,
            this->m_alarmClock
            );
        this->m_actionActivateAlarm = new ActionActivateAlarm(this->m_alarmClock);
        this->m_buttonDisplayAlarms = new ButtonDisplayAvailableAlarm(
            BUTTON1_PIN,
            INTERVAL_40,
            this->m_actionDisplayAlarms,
            this->m_actionDisplayLEDs
            );
        this->m_buttonActivateAlarm = new ButtonActivateAlarm(
            BUTTON2_PIN,
            INTERVAL_40,
            this->m_actionActivateAlarm
            );
        setupCore1Task();

        // //test mélodie
        // m_buzzer = new Buzzer(BUZZER_PIN);
        // m_tetrisMelody = new Tetris();
        // m_doomMelody = new Doom();
        // m_superMarioBrosMelody = new SuperMarioBros();
        
        // m_melodies[0] = m_tetrisMelody->getMelody();
        // m_melodies[1] = m_doomMelody->getMelody();
        // m_melodies[2] = m_superMarioBrosMelody->getMelody();

        // m_melodyLengths[0] = m_tetrisMelody->getMelodyLength();
        // m_melodyLengths[1] = m_doomMelody->getMelodyLength();
        // m_melodyLengths[2] = m_superMarioBrosMelody->getMelodyLength();

        // melodyCount = sizeof(m_melodies) / sizeof(m_melodies[0]);
        // currentMelodyIndex = 0;

        // // Test mélodie initiale
        // m_buzzer->playMelody(m_melodies[currentMelodyIndex], m_melodyLengths[currentMelodyIndex]);
        // // test mélodie
}

/*************************************************************************************************************************************************/

// Lors du cours où vous nous avez présentés l'esp32, vous avez parlés des avantage de ce MCU dont le fait qu'il contiend 2 coeurs!
// Vous nous aviez aussi expliqué que cette avantage était parfait pour faire tourner des horloge internes sans interruption et 
// ralentissement causé par d'autres tâches et calculs sur les coeurs. Nous avons donc profité de cette exercice pour expérimenter
// et exploiter cette avantage puisque nous avons décidé d'inclure une classe qui calcule l'heure. Le but étant d'éviter de faire de 
// multiples requêtes NTP pour conserver l'heure. Même si nous faisons une requête NTP tous les jours à minuit pour recalibrer l'heure,
// le fait de rouler la classe InternalClock sur le coeur 1 nous permet de faire l'essai dans un but pédagogique.

// Références https://github.com/RalphBacon/ESP32-Dual-Core-Programming/blob/master/ESP32_DUALCORE_BLINK.ino  Lignes 41 à 48
// Par contre, après plusieurs essais et autres recherches, j'ai eu recour à chatgpt pour passer la méthode d'un objet (lignes 59 à 61 çi-dessous).                                                                                             */
void Program::setupCore1Task() {
    xTaskCreatePinnedToCore(
        [](void* param) {
            InternalClock* internalClock = static_cast<InternalClock*>(param);    // Fonction à implémenter 
            internalClock->run();
        },
        "InternalClockTask",                                                      // Nom de la tâche
        1024,                                                                     // Taille de la pile en octets
        this->m_internalClock,                                                    // Pointeur de InternalClock
        1,                                                                        // Priorité (1 à 5)
        nullptr,                                                                  // ID de la tâche (on le garde nul pour gérer auto)
        1                                                                         // Coeur 1
    );  
}
/*************************************************************************************************************************************************/

void Program::loop() {
    this->m_connection->tick();    
    this->m_alarmClock->run();
    this->m_buttonDisplayAlarms->tick();
    this->m_buttonActivateAlarm->tick();
    this->m_yellowFlicker->tick();
    //this->m_internalClock->tick(); // On n'a plus à appeler le tick de InternalClock dans la loop. le tick() est pris en charge par le coeur1 qui appel run() dans sa loop.

    // m_buzzer->tick();

    // if (!m_buzzer->isPlaying()) {
    //     currentMelodyIndex = (currentMelodyIndex + 1) % melodyCount;
    //     m_buzzer->playMelody(m_melodies[currentMelodyIndex], m_melodyLengths[currentMelodyIndex]);
    // }     
}
