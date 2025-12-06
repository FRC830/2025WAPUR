#pragma once

//includes

#include <rev/SparkMax.h>
#include "CanConfig.h"
#include <array>
#include <frc/DigitalInput.h>

class Elevator
{
    public:
        Elevator();
        ~Elevator() = default;

        //functions the elvator has
        void SetElevatorLevel(int level);
        int GetElevatorLevel();
        void runElevator(int state);
    private:
        //neo motor 
        // ELEVATOR_MOTOR_ID
        frc::DigitalInput m_Limit{0};
        rev::spark::SparkMax m_elevatorMotor{ELEVATOR_MOTOR_ID, rev::spark::SparkMax::MotorType::kBrushless};
              
        //variables u needa use
        
        // speed
        double m_speed = 0.0;
        const double k_speed = 0.3; //this is the speed elevator moves
        // level 1-4 height in degrees
        // 2.9 inches per rev   
        
        const double level_zero = 0.0;
        const double level_one = -(5.172413 + (1/2.9))*360;
        const double level_two = -10.344827 * 360;
        const double level_three = -15.327586 * 360; 
        const double k_tolerance = 15; //tolerance
        double offset =  -0.68965 * 360;
        std::array <double, 4> k_levels = {level_zero, level_one + offset, level_two + offset, level_three + offset};

        int m_level = 0;
};