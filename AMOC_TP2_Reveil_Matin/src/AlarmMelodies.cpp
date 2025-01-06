#include "AlarmMelodies.h"

AlarmMelodies::AlarmMelodies(
    uint16_t p_delay1,
    uint16_t p_delay2,
    Buzzer* p_buzzer
    )
      : m_isAlarmActive(false),
        m_nbSnoozes(DEFAULT),
        m_melodyIndex(DEFAULT),
        m_buzzer(p_buzzer),
        m_delay1(p_delay1),
        m_delay2(p_delay2),
        m_lastUpdate(DEFAULT) {

            Melody* melody1 = new Melody(tetris);
            Melody* melody2 = new Melody(doom);
            Melody* melody3 = new Melody(superMarioBros);
            this->m_melodyArray[0] = melody1->getMelody();
            this->m_melodyArray[1] = melody2->getMelody();
            this->m_melodyArray[2] = melody3->getMelody();
            this->m_melodyLength[0] = melody1->getMelodyLength();
            this->m_melodyLength[1] = melody2->getMelodyLength();
            this->m_melodyLength[2] = melody3->getMelodyLength();
        }

void AlarmMelodies::setMelodyIndex() {
    this->m_melodyIndex = this->m_nbSnoozes;
}
void AlarmMelodies::playMelody() {
    if (this->m_isAlarmActive) {
        this->m_buzzer->playMelody(
            this->m_melodyArray[this->m_melodyIndex], 
            this->m_melodyLength[this->m_melodyIndex]
            );
    }
}
void AlarmMelodies::stopMelody() {
    this->m_buzzer->stopMelody();
}

void AlarmMelodies::activateAlarm() {
    if (!this->m_isAlarmActive) {
        this->m_isAlarmActive = true;
        playMelody();
    }
}
void AlarmMelodies::deactivateAlarm() {
    if (this->m_isAlarmActive) {
        this->m_isAlarmActive = false;
        this->m_nbSnoozes = DEFAULT;
    }
}
void AlarmMelodies::snooze() {
    if (this->m_nbSnoozes > NB_MELODIES -1) {
        this->m_nbSnoozes = 0;
        deactivateAlarm();
    }
    else {
        ++this->m_nbSnoozes;
        stopMelody();
    }
    setMelodyIndex();
}
void AlarmMelodies::tick() {
    uint64_t actualTime = millis();

    if (this->m_isAlarmActive && this->m_nbSnoozes == DEFAULT) {
        playMelody();
    } else {
        uint16_t delay = (this->m_nbSnoozes == 1) ? this->m_delay1 : this->m_delay2;

        if (actualTime - this->m_lastUpdate >= delay) {
            this->m_lastUpdate = actualTime;
            playMelody();
        }
    }
}
