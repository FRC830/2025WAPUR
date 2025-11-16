#pragma once

struct SwerveInput{
    double xTranslation;
    double yTranslation;
    double rotation;
};

struct ResetNavx
{
    bool reset;
};


struct SmartPlannerInput
{
    bool Left_L1;
    bool Right_L1;
    bool Left_L2;
    bool Right_L2;
};

struct ElevatorInput{
    int targetLevel;
    int level;
};

struct ElevatorOutput{
    bool IsComplete;
    int presentLevel;
};
struct ClawInput{
    int ClawState;
};

struct LauncherInput{
    int LauncherState;
};

struct RobotControlData {
    SwerveInput swerveInput;
    SmartPlannerInput plannerInput;
    ResetNavx resetNavx;
    ElevatorInput elevatorInput;
    ElevatorOutput elevatorOutput;
    ClawInput clawInput;
    LauncherInput launcherInput;
};

