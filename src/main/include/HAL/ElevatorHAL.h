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
        const double speed = 0.0;
        // level 1-4 height in rotations
        const double zero = 0.0;
        const double one = 0.0;
        const double two = 0.0;
        const double three = 0.0;
        const double offset = 0.0;
};