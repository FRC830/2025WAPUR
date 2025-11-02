#pragma once

#include "HAL/ElevatorHAL.h"
#include "RobotControlData.h"
#include <frc/Timer.h>

class ElevatorManager {

    public:
        ElevatorManager() = default;
        ~ElevatorManager() = default;
        void ResetState();
        void HandleInput(RobotControlData &robotControlData);
    private:
        Elevator m_Elevator;
        frc::Timer m_matchTimer;
};
//holaaaa papi

