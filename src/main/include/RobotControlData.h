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

struct ElevatorInput
{
    int level;

};
struct ElevatorOutput
{
    double speed;
    bool movedToLevel;
    double currentLevel;
};

struct SmartPlannerInput
{
    bool Left_L1;
    bool Right_L1;
    bool Left_L2;
    bool Right_L2;
};


struct RobotControlData {
    SwerveInput swerveInput;
    SmartPlannerInput plannerInput;
    ResetNavx resetNavx;
    ElevatorInput elevatorInput;
    ElevatorOutput elevatorOutput;
};


