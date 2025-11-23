#pragma once

#include <rev/SparkMax.h>
#include "CanConfig.h"
#include <frc/Servo.h>

class Ball{
    public:
        Ball();
        ~Ball() = default;
        
        void SetFirstHatchState(int dir);
        void SetSecondHatchState(int dir);
        
    private:
        frc::Servo m_FirstHatchMotor{FIRST_HATCH_ID};
        frc::Servo m_SecondHatchMotor{SECOND_HATCH_ID};
};