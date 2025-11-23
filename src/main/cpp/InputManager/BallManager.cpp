#include "InputManager/BallManager.h"
#include <iostream>

void BallManager::HandleInput(RobotControlData &robotControlData) {
    if (ballTimerState != 0) {
        // Continue processing the timer state machine
        releaseOneBall();
        return;
    }
    if (ballTimer2State != 0) {
        // Continue processing the timer state machine
        releaseAll();
        return;
    }
    
    switch (robotControlData.ballInput.hatchState) {
    case BallInput::RELEASE_ALL:
        if (releaseState == 1)
        {
            closeHatch();
            releaseState = 0;
            break;
        }
        releaseAll();
        break;
    case BallInput::RELEASE_ONE:
        releaseOneBall();
        m_ballTimer.Start();
        break;
    case BallInput::RELEASE_NONE:
        if (releaseState == 1){
            break;
        }
        closeHatch();
        break;
    default:
        // Handle unexpected values if necessary
        break;
    }
    
}

void BallManager::closeHatch() {
    m_ball.SetFirstHatchState(0);
    m_ball.SetSecondHatchState(0);
}

void BallManager::releaseAll() {
    switch (ballTimer2State) {
    case 0:
    {
        m_ballTimer2.Reset();
        m_ballTimer2.Start();
        ballTimer2State = 1;
        m_ball.SetFirstHatchState(1);
        m_ball.SetSecondHatchState(1);  
        break;
    }
    case 1:
    {
        if (m_ballTimer2.Get() > (units::time::second_t) 0.4) { //time elapsed check
            ballTimer2State = 0;
            m_ballTimer2.Stop();
            m_ballTimer2.Reset();
            break;
        }
        m_ball.SetFirstHatchState(1);
        m_ball.SetSecondHatchState(1);  
        break;
    }
    default:
        break;
    }
    releaseState = 1;
    
}

void BallManager::releaseOneBall() {
    switch (ballTimerState) {
    case 0:
    {
        m_ballTimer.Reset();
        m_ballTimer.Start();
        closeHatch();
        ballTimerState = 1;
    }
    case 1:
    {
        if (releaseState == 0){
            ballTimerState = 2;
            std::cout << releaseState << std::endl;
            break;
        }
        if (m_ballTimer.Get() > (units::time::second_t) 0.4) { //time elapsed check
            ballTimerState = 2;
            m_ballTimer.Reset();
            releaseState = 0;
            break;
        }
        closeHatch();
        break;
    }
    case 2:
    {
        m_ballTimer.Reset();
        ballTimerState = 3;
        m_ball.SetSecondHatchState(1); //opens second hatch
        break;
    }
    case 3:
    {
        if (m_ballTimer.Get() > (units::time::second_t) 0.4) { //time elapsed check
            m_ball.SetSecondHatchState(0);
            ballTimerState = 4;
            m_ballTimer.Reset();
            break;
        }
        m_ball.SetSecondHatchState(1);
        break;
    }
    case 4:
    {
        if (m_ballTimer.Get() > (units::time::second_t) 0.4) { //time elapsed check
            m_ball.SetFirstHatchState(1); //opens first hatch
            ballTimerState = 5;
            m_ballTimer.Reset();
            break;
        }
        m_ball.SetSecondHatchState(0);
        break;
    }
    case 5:
    {
        if (m_ballTimer.Get() > (units::time::second_t) 0.4) { //time elapsed check
            m_ball.SetFirstHatchState(0); //closes first hatch
            ballTimerState = 0;
            m_ballTimer.Stop();
            m_ballTimer.Reset();
            break;
        }
        m_ball.SetFirstHatchState(1);
        break;
    }
    default:
        break;
    }
}