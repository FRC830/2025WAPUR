#include "InputManager/BallManager.h"

void BallManager::HandleInput(RobotControlData &robotControlData) {
    if (ballTimerState != 0) {
        // Continue processing the timer state machine
        releaseOneBall();
        return;
    }
    switch (robotControlData.ballInput.hatchState) {
    case BallInput::RELEASE_ALL:
        releaseAll();
        break;
    case BallInput::RELEASE_ONE:
        releaseOneBall();
        break;
    case BallInput::RELEASE_NONE:
        closeHatch();
        break;
    default:
        // Handle unexpected values if necessary
        break;
    }
    
}

void BallManager::closeHatch() {
    m_ball.SetFirstHatchState(-1);
    m_ball.SetSecondHatchState(-1);
}

void BallManager::releaseAll() {
    m_ball.SetFirstHatchState(1);
    m_ball.SetSecondHatchState(1);
}

void BallManager::releaseOneBall() {
    switch (ballTimerState) {
    case 0:
    {
        m_ballTimer.Reset();
        m_ballTimer.Start();
        ballTimerState = 1;
        m_ball.SetSecondHatchState(1); //opens second hatch
        break;
    }
    case 1:
    {
        if (m_ballTimer.Get() > (units::time::second_t) 0.25) { //time elapsed check
            m_ball.SetSecondHatchState(-1);
            m_ball.SetFirstHatchState(1); //opens first hatch
            ballTimerState = 2;
            m_ballTimer.Reset();
            break;
        }
        m_ball.SetSecondHatchState(0);
        break;
    }
    case 2:
    {
        if (m_ballTimer.Get() > (units::time::second_t) 0.25) { //time elapsed check
            m_ball.SetFirstHatchState(-1);
            ballTimerState = 0;
            m_ballTimer.Stop();
            m_ballTimer.Reset();

            break;
        }
        m_ball.SetFirstHatchState(0);
    }
    default:

        break;
    }
}