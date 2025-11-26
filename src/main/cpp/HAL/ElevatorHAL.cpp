
#include "HAL/ElevatorHAL.h"
#include <rev/SparkMax.h>
//#include <rev/CANSparkMax.h>


Elevator::Elevator()
{
    //constructor code
}

void Elevator::SetElevatorLevel(int level)
{
    //code to set elevator level

    double current_pos = m_elevatorMotor.GetEncoder().GetPosition();

    if (level >= int(k_levels.size()) || level < 0)
    {
        m_speed = 0; //invalid level, stop motor
    }
    else if (k_levels[level] > current_pos + k_tolerance)
    {
        //target level is above current position
        m_speed = k_speed; //move up
    }
    else if (k_levels[level] < current_pos - k_tolerance)
    {
        //target level is below current position
        m_speed = -k_speed; //move down
    }
    else
    {
        //target level is within tolerance
        m_speed = 0; //stop
    }


    m_level = level;
    m_elevatorMotor.Set(m_speed);
}

int Elevator::GetElevatorLevel()
{
    //code to get elevator level
    return m_level;
}
void Elevator::runElevator(int state)
{
    if(state==1)
    {
        m_speed = k_speed;
    }
    else if(state==-1)
    {
        m_speed = -k_speed;
    }
    else
    {
        m_speed = 0;
    }
    m_elevatorMotor.Set(m_speed);
} //1 is up, 0 is nothing, -1 is down