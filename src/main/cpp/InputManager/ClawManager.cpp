#include "InputManager/ClawManager.h"

void ClawManager::HandleInput(RobotControlData &robotControlData) {
    //SetClawLevel
    if (robotControlData.clawInput.WiggleState > 0) {
        switch(m_WiggleState){
            case 0:
                m_Claw.ClawIntake(1);
                m_wiggleTimer.Reset();
                m_wiggleTimer.Start();
                m_WiggleState = 1;
                break;
            case 1:
                if (m_wiggleTimer.Get() > (units::time::second_t) 0.15) {
                    m_Claw.ClawIntake(-1);
                    m_wiggleTimer.Reset();
                    m_WiggleState = 2;
                }
                break;
            case 2:
                if (m_wiggleTimer.Get() > (units::time::second_t) 0.15) {
                    m_Claw.ClawIntake(1);
                    m_wiggleTimer.Reset();
                    m_WiggleState = 3;
                }
                break;
            case 3:
                if (m_wiggleTimer.Get() > (units::time::second_t) 0.15) {
                    m_Claw.ClawIntake(0);
                    m_wiggleTimer.Stop();
                    m_WiggleState = 0;
                }
                break;
        }
    } 
    else {
        m_Claw.ClawIntake(robotControlData.clawInput.ClawState);
    }
    
    
}

void ClawManager::ResetState() {
    m_Claw.ClawIntake(0);
}