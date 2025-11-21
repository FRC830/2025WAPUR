#include "ControllerInterface.h"
#include <iostream>

void ControllerInterface::UpdateRobotControlData(RobotControlData &controlData)
{
    UpdateSwerveInput(controlData);
    UpdateSmartplannerInput(controlData);
    UpdateNavxInput(controlData);
    UpdateElevatorInput(controlData);
    UpdateClawInput(controlData);  

    // code for the VibrateController function
    if (m_timer.Get().value()>=m_globalDuration)
    {
        m_pilot.SetRumble(frc::GenericHID::RumbleType::kLeftRumble, 0.0);
        m_pilot.SetRumble(frc::GenericHID::RumbleType::kRightRumble, 0.0);
    }
}

void ControllerInterface::UpdateElevatorInput(RobotControlData &controlData)
{
    if(m_copilot.GetAButtonPressed()){
        controlData.elevatorInput.level = 0;
    }
    else if(m_copilot.GetBButtonPressed()){
        controlData.elevatorInput.level = 1;
    }
    else if(m_copilot.GetXButtonPressed()){
        controlData.elevatorInput.level = 2;
    }
    else if(m_copilot.GetYButtonPressed()){
        controlData.elevatorInput.level = 3;
    }
}

void ControllerInterface::UpdateBallInput(RobotControlData &controlData)
{
    if(m_copilot.GetRightBumperButtonPressed()){
        controlData.ballInput.hatchState = BallInput::RELEASE_ALL; // Release ALL balls
    }
    else if(m_copilot.GetLeftBumperButtonPressed()){
        controlData.ballInput.hatchState = BallInput::RELEASE_ONE; // Release ONE balls
    }
    else{
        controlData.ballInput.hatchState = BallInput::RELEASE_NONE; // Do not release balls
    }
}

void ControllerInterface::UpdateNavxInput(RobotControlData &controlData)
{
    controlData.resetNavx.reset = m_pilot.GetStartButtonPressed();
}

void ControllerInterface::UpdateSwerveInput(RobotControlData &controlData)
{  
    
    controlData.swerveInput.xTranslation = -m_pilot.GetLeftY();
    controlData.swerveInput.yTranslation = -m_pilot.GetLeftX();
    controlData.swerveInput.rotation = -m_pilot.GetRightX();


 
}

void ControllerInterface::UpdateClawInput(RobotControlData &controlData)
{
    if(m_copilot.GetLeftY() < -0.1){
        controlData.clawInput.ClawState = -1; // Intake
    }
    else if(m_copilot.GetLeftY() > 0.1){
        controlData.clawInput.ClawState = 1; // Outtake
    }
    else{
        controlData.clawInput.ClawState = 0; // Stop
    }
}



void ControllerInterface::UpdateSmartplannerInput(RobotControlData &controlData)
{
   // if (m_copilot.GetLeftTriggerAxis() > 0.1) {controlData.plannerInput.Left_L1 = true;}
   // else if (m_copilot.GetRightTriggerAxis() > 0.1) {controlData.plannerInput.Right_L1 = true;}
    if (m_copilot.GetLeftTriggerAxis() > 0.1) {controlData.plannerInput.Left_L2 = true;}
    else if (m_copilot.GetRightTriggerAxis() > 0.1) {controlData.plannerInput.Right_L2 = true;}
    else 
    {
        controlData.plannerInput.Left_L1 = false;
        controlData.plannerInput.Left_L2 = false;
        controlData.plannerInput.Right_L1 = false;
        controlData.plannerInput.Right_L2 = false;
    }

}

void ControllerInterface::VibrateController(double intensity, double duration)
{
    m_globalDuration = duration;
    m_timer.Restart();
    m_pilot.SetRumble(frc::GenericHID::RumbleType::kLeftRumble, intensity);
    m_pilot.SetRumble(frc::GenericHID::RumbleType::kRightRumble, intensity);
}
