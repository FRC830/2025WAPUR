
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
        m_speed = -k_speed; //move down
    }
    else if (k_levels[level] < current_pos - k_tolerance)
    {
        //target level is below current position
        m_speed = k_speed; //move up
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