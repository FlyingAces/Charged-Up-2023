#include "subsystems/LimeLightSubsystem.h"


LimeLightSubsystem::LimeLightSubsystem() = default;

double LimeLightSubsystem::getX(){
    table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    return table->GetNumber("tx",0.0);
}

double LimeLightSubsystem::getY(){
    table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    return table->GetNumber("ty",0.0);
}

bool LimeLightSubsystem::hasTarget(){
    table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    return table->GetBoolean("tv", false);
}

double LimeLightSubsystem::getArea(){
    table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    return table->GetNumber("ta",0.0);
}

void LimeLightSubsystem::setLED(LEDMode mode){
    table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    table->PutNumber("ledMode", mode);
}

void LimeLightSubsystem::setMode(CamMode mode){
    table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    table->PutNumber("camMode", mode);
}

void LimeLightSubsystem::Periodic() {}