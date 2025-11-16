
#include "HAL/BallHAL.h"
#include <rev/SparkMax.h>

Ball::Ball() {
    //Constructor
}

void Ball::SetFirstHatchState(int state){
    m_FirstHatchMotor.SetAngle(state*90);
}
void Ball::SetSecondHatchState(int state){
    m_SecondHatchMotor.SetAngle(state*90);
}