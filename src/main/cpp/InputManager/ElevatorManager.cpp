#include "InputManager/ElevatorManager.h"

void ElevatorManager::HandleInput(RobotControlData &robotControlData) {
    //SetElevatorLevel
    m_Elevator.SetElevatorLevel(robotControlData.elevatorInput.level);
    
}

void ElevatorManager::ResetState() {
    m_matchTimer.Reset();
    m_matchTimer.Start();
}