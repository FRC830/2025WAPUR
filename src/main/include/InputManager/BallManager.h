#pragma once
#include "RobotControlData.h"
#include "HAL/BallHAL.h"
#include <frc/Timer.h>

class BallManager {
    public:
        BallManager() = default; // constructor
        ~BallManager() = default; 
        void ResetState(RobotControlData &robotControlData); //takes in robot control data to reset door??
        void HandleInput(RobotControlData &robotControlData); //handles ball management logic
    private:
        Ball m_ball;
        void releaseOneBall();
        void releaseAll();
        frc::Timer m_ballTimer;
        int ballTimerState = 0;
};