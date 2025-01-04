#pragma once
#include "./Action.h"
#include <TM1637Display.h>
#include "FourDigits/Display4Digits.h"

class ActionDisplayConnection : public Action{
private:
    enum State { SHOW_D, SHOW_G, SHOW_A, CONNECTED };
    State m_state;
    Display4Digits* m_display4Digits;
public:
    ActionDisplayConnection(Display4Digits* p_display4Digits);
    void execute() override;
};

