
#include "HAL/BallHAL.h"
#include <rev/SparkMax.h>
#include <iostream>

Ball::Ball() {
    //Constructor
}

void Ball::SetFirstHatchState(int state){
    if (state == 0)
    {
        m_FirstHatchMotor.SetAngle(FIRSTZERO);
   }
   else
   {
       m_FirstHatchMotor.SetAngle(state*90);
   }
    //std::cout << "min first" << m_FirstHatchMotor.GetMinAngle() <<std::endl;
   // std::cout << "max first" << m_FirstHatchMotor.GetMaxAngle() <<std::endl;

}
void Ball::SetSecondHatchState(int state){
    if (state == 0)
    {
    m_SecondHatchMotor.SetAngle(SECONDZERO);

    }
    else
    {
        m_SecondHatchMotor.SetAngle(state*90);
        //m_SecondHatchMotor.SetSpeed(0.1);
    }
       // std::cout << "min second" << m_SecondHatchMotor.GetMinAngle() <<std::endl;
   // std::cout << "max second" << m_SecondHatchMotor.GetMaxAngle() <<std::endl;
        //std::cout << "second hatch" << std::endl;
}