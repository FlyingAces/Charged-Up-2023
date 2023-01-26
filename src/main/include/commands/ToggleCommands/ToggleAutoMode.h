#pragma once

#include <frc2/command/CommandBase.h>
#include<frc2/command/CommandHelper.h>

#include "subsystems/DriveTrainSubsystem.h"

class ToggleAutoMode : public frc2::CommandHelper<frc2::CommandBase, ToggleAutoMode> {
    public:
    explicit ToggleAutoMode(DriveTrainSubsystem* p_DriveTrain);

    void Execute() override;
    bool IsFinished() override;
    private:
    DriveTrainSubsystem* mp_DriveTrain;
};