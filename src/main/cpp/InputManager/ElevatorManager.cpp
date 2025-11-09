#include "InputManager/ElevatorManager.h"

void ElevatorManager::HandleInput(RobotControlData &robotControlData) {
    //SetElevatorLevel
    m_Elevator.SetElevatorLevel(robotControlData.elevatorInput.level);
    robotControlData.elevatorOutput.presentLevel = m_Elevator.GetElevatorLevel();
    
}

void ElevatorManager::ResetState() {
    m_matchTimer.Reset();
    m_matchTimer.Start();
}