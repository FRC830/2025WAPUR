
#include "HAL/ClawHAL.h"
#include <rev/SparkMax.h>

Claw::Claw()
{
    //Constuc
}
void Claw::ClawIntake(int dir){
    m_clawMotorA.Set(-dir*speed);
    m_clawMotorB.Set(dir*speed);
}
void Claw::RightIntake(int dir){
    m_clawMotorA.Set(-dir*speed);
}
void Claw::LeftIntake(int dir){
    m_clawMotorB.Set(dir*speed);
}
