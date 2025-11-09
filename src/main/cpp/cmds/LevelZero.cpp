#include "cmds/LevelZero.h"
#include "MechanismConfig.h"

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
    return (m_robotControlData.elevatorOutput.presentLevel == 0);
}

void LevelZero::End(bool interrupted)
{
}