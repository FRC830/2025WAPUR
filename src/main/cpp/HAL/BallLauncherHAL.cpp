
#include "HAL/BallLauncherHAL.h"
#include <rev/SparkMax.h>

BallLauncher::BallLauncher()
{
    //Constructor
}

void BallLauncher::SetFirstHatchState(bool state){
    if (state){
        m_FirstHatchMotorA.Set(1.0);
        m_FirstHatchMotorB.Set(-1.0);
    } else {
        m_FirstHatchMotorA.Set(0.0);
        m_FirstHatchMotorB.Set(0.0);
    }
}
void BallLauncher::SetSecondHatchState(bool state){
    if (state){
        m_SecondHatchMotorA.Set(1.0);
        m_SecondHatchMotorB.Set(-1.0);
    } else {
        m_SecondHatchMotorA.Set(0.0);
        m_SecondHatchMotorB.Set(0.0);
    }
}