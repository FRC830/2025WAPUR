#pragma once

#include <frc2/command/CommandHelper.h>
#include "RobotControlData.h"

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
};