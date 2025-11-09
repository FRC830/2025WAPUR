#pragma once

#include <frc2/command/CommandHelper.h>
#include "RobotControlData.h"

class ClawOut : public frc2::CommandHelper<frc2::Command, ClawOut>
{
public:
    explicit ClawOut(RobotControlData& data);
    ~ClawOut() = default;

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

private:
    RobotControlData& m_robotControlData;
};