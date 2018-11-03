#ifndef DriveForward_H
#define DriveForward_H

#include "../CommandBase.h"

class DriveForward : public CommandBase {
private:
	double distance;
public:
	DriveForward(double distance_);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForward_H
