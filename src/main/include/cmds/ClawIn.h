#pragma once

#include <frc2/command/CommandHelper.h>
#include "RobotControlData.h"
#include <frc/Timer.h>

class ClawIn : public frc2::CommandHelper<frc2::Command, ClawIn>
{
public:
    explicit ClawIn(RobotControlData& data);
    ~ClawIn() = default;

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

private:
    RobotControlData& m_robotControlData;
    frc::Timer m_timer;
    const double k_ClawInDuration = 0.2;
};