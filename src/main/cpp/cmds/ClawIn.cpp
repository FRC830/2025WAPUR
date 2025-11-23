#include "cmds/ClawIn.h"
#include "MechanismConfig.h"

ClawIn::ClawIn(RobotControlData& data) : m_robotControlData(data)
{}

void ClawIn::Initialize()
{
    m_timer.Reset();
    m_timer.Start();
    m_robotControlData.clawInput.ClawState = -1;
}

void ClawIn::Execute()
{
     m_robotControlData.clawInput.ClawState = -1;
}

bool ClawIn::IsFinished()
{
    return (m_timer.Get() >= (units::time::second_t) k_ClawInDuration);
}

void ClawIn::End(bool interrupted)
{
    m_robotControlData.clawInput.ClawState = 0;
    m_timer.Stop();
}