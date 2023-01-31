#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ProfiledPIDCommand.h>

#include "subsystems/DriveTrainSubsystem.h"
#include "subsystems/GyroSubsystem.h"

class TurnToAnglePID: public frc2::CommandHelper<frc2::ProfiledPIDCommand<units::radians>, TurnToAnglePID> {
 
 public:
  TurnToAnglePID(DriveTrainSubsystem* p_drive, GyroSubsystem* p_Gyro, units::degree_t targetAngleDegrees);

  bool IsFinished() override;
};