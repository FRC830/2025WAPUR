
#include "HAL/ElevatorHAL.h"
#include <rev/SparkMax.h>
#include <string.h>
//#include <rev/CANSparkMax.h>
#include <frc/smartdashboard/SmartDashboard.h>


Elevator::Elevator()
{
    //constructor code
}
#include <iostream>
void Elevator::SetElevatorLevel(int level)
{
    //code to set elevator level

    double current_pos = m_elevatorMotor.GetEncoder().GetPosition();
    //std::cout << "current pos: " << current_pos << std::endl;
    //std::cout << "target pos: " << k_levels[level] << std::endl;

    frc::SmartDashboard::PutNumber("current_pos", current_pos);

    if (level >= int(k_levels.size()) || level < 0)
    {
        m_speed = 0; //invalid level, stop motor
        //std::cout << "invalid" << std::endl;
    }
    else if (k_levels[level] < current_pos - k_tolerance)
    {
        //target level is below current position
        m_speed = -k_speed; //move down
        
        //std::cout << "move up" << std::endl;
    }
    else if (k_levels[level] > current_pos + k_tolerance)
    {
        //target level is above current position
        m_speed = k_speed; //move up
        if (!m_Limit.Get()) // false = tripped
        {
            m_speed = 0;
            offset = current_pos;
            k_levels[0] = level_zero + offset;
            k_levels[1] = level_one + offset;
            k_levels[2] = level_two + offset;
            k_levels[3] = level_three + offset;
        }
        
        //std::cout << "move down" << std::endl;
    }
    else
    {
        //target level is within tolerance
        m_speed = 0; //stop
        //std::cout << "stop" << std::endl;
    }


    m_level = level;
    //std::cout << "level " << m_level << std::endl;
    //std::cout << "speed" << m_speed << std::endl;
    m_elevatorMotor.Set(m_speed);
}

int Elevator::GetElevatorLevel()
{
    int f_level;
    double current_pos = m_elevatorMotor.GetEncoder().GetPosition();
    if (k_levels[0] < current_pos - k_tolerance || k_levels[0] > current_pos + k_tolerance )
    {
        f_level = 0;
    }
    else if (k_levels[1] < current_pos - k_tolerance || k_levels[1] > current_pos + k_tolerance )
    {
        f_level = 1;
    }
    else if (k_levels[2] < current_pos - k_tolerance || k_levels[2] > current_pos + k_tolerance )
    {
        f_level = 2;
    }
    else if (k_levels[3] < current_pos - k_tolerance || k_levels[3] > current_pos + k_tolerance )
    {
        f_level = 3;
    }
    else
    {
        f_level = -1;
    }
    
    //code to get elevator level
    
    return f_level;
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