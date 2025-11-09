#pragma once

#include <frc2/command/CommandHelper.h>
#include "RobotControlData.h"

class LevelZero : public frc2::CommandHelper<frc2::Command, LevelZero>
{
public:
    explicit LevelZero(RobotControlData& data);
    ~LevelZero() = default;

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

private:
    RobotControlData& m_robotControlData;
};