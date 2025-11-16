#include "InputManager/BallManager.h"

void BallManager::HandleInput(RobotControlData &robotControlData) {
    
    //todo
    
}

void BallManager::releaseAll() {
    m_ball.SetFirstHatchState(1);
    m_ball.SetSecondHatchState(1);
}

void BallManager::releaseOneBall() {
    switch (ballTimerState) {
    case 0:
    {
        m_ballTimer.Start();
        ballTimerState = 1;
        m_ball.SetSecondHatchState(1);
        break;
    }
    case 1:
    {
        if (m_ballTimer.Get() > (units::time::second_t) 0.25) {
            m_ball.SetSecondHatchState(-1);
            m_ball.SetFirstHatchState(1);
            ballTimerState = 2;
            m_ballTimer.Reset();
            break;
        }
        m_ball.SetSecondHatchState(0);
        break;
    }
    case 2:
    {
        //todo
    }
    default:

        break;
    }
}