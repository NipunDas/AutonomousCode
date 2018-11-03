#include "DriveForward.h"

DriveForward::DriveForward(double distance_) : distance(distance_){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
}

// Called just before this Command runs the first time
void DriveForward::Initialize() {
	drive->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute() {
	drive->tankDrive(0.5, 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	if ((drive->leftDistance() + drive->rightDistance())/2 >= distance) {
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void DriveForward::End() {
	drive->tankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {

}
