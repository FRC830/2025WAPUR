#pragma once

#include <rev/SparkMax.h>
#include "CanConfig.h"

class Ball{
    public:
        Ball();
        ~Ball() = default;
        
        void SetFirstHatchState(int dir);
        void SetSecondHatchState(int dir);
        
    private:
        rev::spark::SparkMax m_FirstHatchMotor{FIRST_HATCH_ID, rev::spark::SparkMax::MotorType::kBrushless};
        rev::spark::SparkMax m_SecondHatchMotor{SECOND_HATCH_ID, rev::spark::SparkMax::MotorType::kBrushless};
};