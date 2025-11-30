#include "cmds/LevelZero.h"
#include "MechanismConfig.h"
#include "HAL/ElevatorHAL.h"


LevelZero::LevelZero(RobotControlData& data) : m_robotControlData(data)
{}

void LevelZero::Initialize()
{
    m_robotControlData.elevatorInput.level = 0;
}

void LevelZero::Execute()
{
    m_robotControlData.elevatorInput.level = 0;
}

bool LevelZero::IsFinished()
{
    return  0;
}

void LevelZero::End(bool interrupted)
{
}