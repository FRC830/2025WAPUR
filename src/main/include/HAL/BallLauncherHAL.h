#pragma once

#include <rev/SparkMax.h>
#include "CanConfig.h"

class BallLauncher{
    public:
        BallLauncher();
        ~BallLauncher() = default;
        
        void SetFirstHatchState(bool dir);
        void SetSecondHatchState(bool dir);
        
    private:
        rev::spark::SparkMax m_FirstHatchMotorA{FIRST_HATCH_A_ID, rev::spark::SparkMax::MotorType::kBrushless};
        rev::spark::SparkMax m_FirstHatchMotorB{FIRST_HATCH_B_ID, rev::spark::SparkMax::MotorType::kBrushless};
        rev::spark::SparkMax m_SecondHatchMotorA{SECOND_HATCH_A_ID, rev::spark::SparkMax::MotorType::kBrushless};
        rev::spark::SparkMax m_SecondHatchMotorB{SECOND_HATCH_B_ID, rev::spark::SparkMax::MotorType::kBrushless};

        bool firstHatchState = false;
        bool SecondHatchState = false;
};