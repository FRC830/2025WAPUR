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
    bool isComplete;
    int presentLevel;
};

struct ClawInput{
    int ClawState;
};

struct BallInput{
    enum HatchState {
        RELEASE_NONE = 0,
        RELEASE_ONE = 1,
        RELEASE_ALL = 2
    };
    HatchState hatchState;
};

struct RobotControlData {
    SwerveInput swerveInput;
    SmartPlannerInput plannerInput;
    ResetNavx resetNavx;
    ElevatorInput elevatorInput;
    ElevatorOutput elevatorOutput;
    ClawInput clawInput;
    BallInput ballInput;
};

