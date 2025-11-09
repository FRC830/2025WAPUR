#pragma once

//includes

#include <rev/SparkMax.h>
#include "CanConfig.h"


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
        const double speed = 0.20; //this is the speed elevator moves
        // level 1-4 height in rotations
        const double zero = 0.0;
        const double one = 2.727272727272727;
        const double two = 5.454545454545454;
        const double three = 8.181818181818182; 
        const double offset = 0.09; //tolerance
        int m_level = 0;
};