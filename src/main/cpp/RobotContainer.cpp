// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer* RobotContainer::mp_RobotContainer = NULL;
RobotContainer::RobotContainer() {
  // Set drive with controller to run as default
  m_DriveTrain.SetDefaultCommand(std::move(m_DriveWithController));
  // Set auto state to false
  m_DriveTrain.setAutoState(false);
  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  m_DriverButtonY.WhenPressed(m_ToggleDriveMode);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
