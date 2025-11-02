
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

    double pos = m_elevatorMotor.GetEncoder().GetPosition();


    if (level == 0)
    {
        if (pos > zero + offset)
        {
            m_speed = speed; //move up
        }
        else
        {
            m_speed = 0; //stop
        }
    }
    else if (level == 1)
    {
        if (pos > one + offset)
        {
            m_speed = -speed; //move down
        }
        else if (pos < one -offset)
        { 
            m_speed = speed; //move up
        }
        else{
            m_speed = 0; //stop
        }
    }
    else if (level == 2)
    {
        if (pos > two + offset)
        {
            m_speed = -speed; //move down
        }
        else if (pos < two - offset)
        {
            m_speed = speed; //move up
        }        
        else{
            m_speed = 0; //stop
        }
    }
    else if (level == 3)
    {    
        if (pos < three - offset)
        {
           m_speed = speed; //move up
        }
        else
        {
            m_speed = 0; //stop
        }
    }
    else
    {
        m_speed = 0; //stop
    }


    m_elevatorMotor.Set(m_speed);
}

int Elevator::GetElevatorLevel()
{
    //code to get elevator level
    return 0;
}