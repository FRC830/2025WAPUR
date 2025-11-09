#pragma once
#include "HAL/ClawHAL.h"
#include "RobotControlData.h"
#include <frc/Timer.h>

class ClawManager {

    public:
        ClawManager() = default;
        ~ClawManager() = default;
        void ResetState();
        void HandleInput(RobotControlData &robotControlData);
    private:
        Claw m_Claw;
};