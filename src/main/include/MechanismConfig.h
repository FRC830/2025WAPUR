#pragma once

#include <rev/config/SparkMaxConfig.h>
#include "PhotonVisionCamera.h"
#include <ctre/phoenix6/TalonFX.hpp>
#include <ctre/phoenix6/configs/Configs.hpp>

namespace {
namespace ratbot
{

    const double VOLTAGE_COMPENSATION = 10.5f;

    namespace VisionConfig
    {
        frc::Transform3d ROBOT_TO_CAMERA = frc::Transform3d(frc::Translation3d(11_in, 1.0_in, 27.5_in), frc::Rotation3d(0_rad, 0_deg, 0_rad));
    }
  

    namespace MoveToPoseConfig
    {
        // TODO: tune values on carpet
        const double MAX_TURN_SPEED_DEG_PER_SEC = 160.0f;
        const double TURN_FEED_FORWARD_DEG_PER_SEC = 20.0f;
        const double MAX_SPEED_M_PER_SEC = 1.32f; // todo: change!!!
        const double SPEED_FEED_FORWARD_M_PER_SEC = 0.1f; //todo: change!!!!!
    }
}
}