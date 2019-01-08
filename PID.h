#include <C:\Users\RD SINGH\Desktop\General\Robotics\ShawniganLakeCode\include\main.h>
#include <math.h>


pros::Motor leftBDrive_mtr(1, MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS);
pros::Motor rightBDrive_mtr(2, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);
pros::Motor leftFDrive_mtr(3, MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS);
pros::Motor rightFDrive_mtr(4, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);

pros::Motor flyLWheel_mtr(5, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);
pros::Motor flyRWheel_mtr(6, MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS);
pros::Motor ballIntake_mtr(7, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);

void driveMotors(int speed)
{
  leftFDrive_mtr.move(0);
  leftBDrive_mtr.move(0);
  rightBDrive_mtr.move(0);
  rightFDrive_mtr.move(0);
}

static void resetPos()
{
  leftBDrive_mtr.tare_position();
  rightBDrive_mtr.tare_position();
  rightFDrive_mtr.tare_position();
  leftFDrive_mtr.tare_position();
}

static void resetSensor(int target)
{
  leftFDrive_mtr.set_zero_position(target);
  rightBDrive_mtr.set_zero_position(target);
  leftBDrive_mtr.set_zero_position(target);
  rightFDrive_mtr.set_zero_position(target);
}

static void driveBrakeHold()
{
  leftFDrive_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  leftBDrive_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  rightFDrive_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  rightBDrive_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

}

static void resetBrake()
{
  leftFDrive_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  leftBDrive_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  rightFDrive_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  rightBDrive_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
}

static void movePID(int power)
{
  double kp = 0.695;

	int main = 0;
	int secondary = 0;
	int error = 1;
  int powerLeft, powerRight;

  int maxPower = power;
  int MIN_POWER = maxPower - 20;

  //int leftPos = (abs(lfdMotor.get_position()) + abs(lbdMotor.get_Position())/2;
	main = (abs(rightFDrive_mtr.get_position()) >= abs(leftFDrive_mtr.get_position())) ? abs(rightFDrive_mtr.get_position()) : abs(leftFDrive_mtr.get_position());
	secondary = (abs(rightFDrive_mtr.get_position()) >= abs(leftFDrive_mtr.get_position())) ? abs(leftFDrive_mtr.get_position()) : abs(rightFDrive_mtr.get_position());

	error = main - secondary;

	if(main > secondary)
	{
			power = power - error * kp;
	}

  if(power > 0)
  {
    if(power < MIN_POWER)
    {
      power = MIN_POWER;
    }
  }
  else if(power < 0)
  {
    if(power > -MIN_POWER)
    {
      power = -MIN_POWER;
    }
  }

  if(rightFDrive_mtr.get_position() > leftFDrive_mtr.get_position())
  {
    powerLeft = maxPower;
    powerRight = power;
  }
  else
  {
    powerLeft = power;
    powerRight = maxPower;
  }


  leftFDrive_mtr.move(powerLeft);
  rightFDrive_mtr.move(powerRight);
  leftBDrive_mtr.move(powerLeft);
  rightBDrive_mtr.move(powerRight);

}

static void turnPID(int power)
{
  double kp = 0.695;

  int main = 0;
  int secondary = 0;
  int error = 1;
  int powerLeft, powerRight;

  int maxPower = power;
  int MIN_POWER = maxPower - 20;

  //int leftPos = (abs(lfdMotor.get_position()) + abs(lbdMotor.get_Position())/2;
  main = (abs(rightFDrive_mtr.get_position()) >= abs(leftFDrive_mtr.get_position())) ? abs(rightFDrive_mtr.get_position()) : abs(leftFDrive_mtr.get_position());
  secondary = (abs(rightFDrive_mtr.get_position()) >= abs(leftFDrive_mtr.get_position())) ? abs(leftFDrive_mtr.get_position()) : abs(rightFDrive_mtr.get_position());

  error = main - secondary;

  if(main > secondary)
  {
      power = power - error * kp;
  }

  if(power > 0)
  {
    if(power < MIN_POWER)
    {
      power = MIN_POWER;
    }
  }
  else if(power < 0)
  {
    if(power > -MIN_POWER)
    {
      power = -MIN_POWER;
    }
  }

  if(rightFDrive_mtr.get_position() > leftFDrive_mtr.get_position())
  {
    powerLeft = maxPower;
    powerRight = power;
  }
  else
  {
    powerLeft = power;
    powerRight = maxPower;
  }


  leftFDrive_mtr.move(powerLeft);
  rightFDrive_mtr.move(-powerRight);
  leftBDrive_mtr.move(powerLeft);
  rightBDrive_mtr.move(-powerRight);
}
static void flyCoast()
{
  flyLWheel_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  flyRWheel_mtr.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

static void moveDrive(double targetDistance, int maxPower, int flyWheelP, int flipperP, int intakeP)
{
	double kp = 0.695;

	int currentDistance = 0;
	double error = 20;

  int targ = (targetDistance/12.566) * 360;

  int leftF, leftB, rightF, rightB;

  pros::Motor lfdMotor (1, MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor rfdMotor (2, MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor leftBDrive_mtr (3, MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES);
  pros::Motor rbdMotor (4, MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);

	while(error != 0)
	{
    leftF = abs(leftFDrive_mtr.get_position());
    leftB = abs(leftBDrive_mtr.get_position());
    rightF = abs(rfdMotor.get_position());
    rightB = abs(rightBDrive_mtr.get_position());

		currentDistance = (leftF + rightF)/2;

		error = targ - currentDistance;

    ballIntake_mtr.move(intakeP);

    flyLWheel_mtr.move(flyWheelP);
    flyRWheel_mtr.move(flyWheelP);

    movePID(maxPower);

    if(error < 15 && error > -15)
    {
      error = 0;
      driveMotors(0);
      driveBrakeHold();
      flyCoast();
    }
  }
  resetBrake();

  ballIntake_mtr.move(0);
}
