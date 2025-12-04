#pragma once

#include <frc2/command/CommandHelper.h>
#include "RobotControlData.h"
#include "HAL/ElevatorHAL.h"
#include <frc/Timer.h>


class LevelTop : public frc2::CommandHelper<frc2::Command, LevelTop>
{
public:
    explicit LevelTop(RobotControlData& data);
    ~LevelTop() = default;

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted) override;

private:
    RobotControlData& m_robotControlData;
    frc::Timer m_timer;
    //Elevator el;
};