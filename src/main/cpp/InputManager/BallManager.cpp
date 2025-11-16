#include "InputManager/BallManager.h"

void BallManager::HandleInput(RobotControlData &robotControlData) {

    if (robotControlData.launcherInput.LauncherState == 1) {
        releaseOneBall();
        m_ballTimer.Start();

    } else if (robotControlData.launcherInput.LauncherState == 2) {
        releaseAll();
    } else {
        ballTimerState = 0;
    }
}

void BallManager::releaseAll() {
    m_ball.SetFirstHatchState(1);
    m_ball.SetSecondHatchState(1);
}

void BallManager::releaseOneBall() {
    switch (ballTimerState) {
        case 0:
        {
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
            m_ballTimer.Reset();
            m_ball.SetFirstHatchState(0);
            m_ball.SetSecondHatchState(0);
            break;
        }
        
    default:
        break;
    }
}