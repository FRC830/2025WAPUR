
#include "HAL/BallHAL.h"
#include <rev/SparkMax.h>

Ball::Ball() {
    //Constructor
}

void Ball::SetFirstHatchState(int state){
    m_FirstHatchMotor.Set(state);
}
void Ball::SetSecondHatchState(int state){
    m_SecondHatchMotor.Set(state);
}