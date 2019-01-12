#include "main.h"
#include "PID.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */



void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);


	while (true) {

    pros::lcd::print(0, std::string(std::to_string(leftBDrive_mtr.get_position())).c_str());

		leftBDrive_mtr.move(((master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_LEFT_X)/2)*1.5));
		leftFDrive_mtr.move(((master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_LEFT_X)/2)*1.5));
		rightFDrive_mtr.move(((master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_LEFT_X)/2)*1.5));
		rightBDrive_mtr.move(((master.get_analog(ANALOG_LEFT_Y) - master.get_analog(ANALOG_LEFT_X)/2)*1.5));

		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1))
		{
      for(int i = 1; i <= 127; i++)
			{
				flyWheel_mtr.move(i);
			}
			flyWheel_mtr.move(127);
		}
		else
		{
			flyWheel_mtr.move(0);
			flyCoast();
		}

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1))
		{
			ballIntake_mtr.move(100);
			indexer.move(100);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2))
		{
			ballIntake_mtr.move(100);
		}
		else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A))
		{
			ballIntake_mtr.move(-87);
		}
		else
		{
			indexer.move(0);
			ballIntake_mtr.move(0);
		}


    pros::delay(20);
	}
}
