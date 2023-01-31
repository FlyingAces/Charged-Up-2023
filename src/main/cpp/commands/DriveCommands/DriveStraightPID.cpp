#include "commands/DriveCommands/DriveStraightPID.h"

#include <frc/controller/ProfiledPIDController.h>

DriveDistPID::DriveDistPID(DriveTrainSubsystem* mp_drive, units::meter_t target) : CommandHelper(
          frc::ProfiledPIDController<units::meters>(PID_DRIVE_CONSTANTS::DRIVE_P , PID_DRIVE_CONSTANTS::DRIVE_I, PID_DRIVE_CONSTANTS::DRIVE_D, {PID_DRIVE_CONSTANTS::MAX_SPEED, PID_DRIVE_CONSTANTS::MAX_ACCEL}),
          // Close loop on heading
          [mp_drive] { return ((mp_drive->getRightDist()+mp_drive->getLeftDist())/2); },
          // Set reference to target
          target,
          // Pipe output to turn robot
          [mp_drive](double output, auto setpointState) {
            mp_drive->arcadeDrive(output, 0);
          },
          // Require the drive
          {mp_drive}) {
  GetController().SetTolerance(PID_DRIVE_CONSTANTS::DIST_TOLERANCE, PID_DRIVE_CONSTANTS::ACCEL_TOLERANCE);
  AddRequirements({mp_drive});
  mp_DriveTrain->zeroDTEncoders();
  GetController().Reset(0_m);
}
void DriveDistPID::Initialize() {
  mp_DriveTrain->zeroDTEncoders();
  GetController().Reset(0_m);
}
bool DriveDistPID::IsFinished() {
  return GetController().AtGoal();
}