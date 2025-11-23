#include "cmds/ClawOut.h"
#include "MechanismConfig.h"

ClawOut::ClawOut(RobotControlData& data) : m_robotControlData(data)
{}

void ClawOut::Initialize()
{
    m_timer.Reset();
    m_timer.Start();
    m_robotControlData.clawInput.ClawState = 1;
}

void ClawOut::Execute()
{
     m_robotControlData.clawInput.ClawState = 1;
}

bool ClawOut::IsFinished()
{
    return (m_timer.Get() >= (units::time::second_t) k_clawOutDuration);
}

void ClawOut::End(bool interrupted)
{
    m_robotControlData.clawInput.ClawState = 0;
    m_timer.Stop();
}