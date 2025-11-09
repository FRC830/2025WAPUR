
#include "HAL/ClawHal.h"
#include <rev/SparkMax.h>

Claw::Claw()
{
    //Constuc
}
void Claw::ClawIntake(int dir){
    m_clawMotorA.Set(dir*speed);
    m_clawMotorB.Set(-dir*speed);
}
