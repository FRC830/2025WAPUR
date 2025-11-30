#include "cmds/LevelTop.h"
#include "MechanismConfig.h"

LevelTop::LevelTop(RobotControlData& data) : m_robotControlData(data)
{}

void LevelTop::Initialize()
{
    m_robotControlData.elevatorInput.level = 0;
}

void LevelTop::Execute()
{
    m_robotControlData.elevatorInput.level = 3;
}

bool LevelTop::IsFinished()
{
    // 8.2 seconds
    return 0;
}

void LevelTop::End(bool interrupted)
{
}