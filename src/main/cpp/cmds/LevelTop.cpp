#include "cmds/LevelTop.h"
#include "MechanismConfig.h"

LevelTop::LevelTop(RobotControlData& data) : m_robotControlData(data)
{}

void LevelTop::Initialize()
{
    m_robotControlData.elevatorInput.level = 0;
    m_timer.Reset();
    m_timer.Start();
}

void LevelTop::Execute()
{
    m_robotControlData.elevatorInput.level = 3;
}

bool LevelTop::IsFinished()
{
    // 9 seconds
    return m_timer.Get().value() > 9;
}

void LevelTop::End(bool interrupted)
{
    m_timer.Stop();
}