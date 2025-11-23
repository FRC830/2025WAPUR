#pragma once

//includes

#include <rev/SparkMax.h>
#include "CanConfig.h"
#include <array>

class Elevator
{
    public:
        Elevator();
        ~Elevator() = default;

        //functions the elvator has
        void SetElevatorLevel(int level);
        int GetElevatorLevel();

    private:
        //neo motor 
        // ELEVATOR_MOTOR_ID
        rev::spark::SparkMax m_elevatorMotor{ELEVATOR_MOTOR_ID, rev::spark::SparkMax::MotorType::kBrushless};
              
        //variables u needa use
        
        // speed
        double m_speed = 0.0;
        const double k_speed = 0.20; //this is the speed elevator moves
        // level 1-4 height in rotations
        const double level_zero = 0.0;
        const double level_one = 2.727272727272727;
        const double level_two = 5.454545454545454;
        const double level_three = 8.181818181818182; 
        const double k_tolerance = 0.09; //tolerance

        const std::array <double, 4> k_levels = {level_zero, level_one, level_two, level_three};
        int m_level = 0;
};