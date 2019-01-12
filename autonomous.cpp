#include <math.h>
#include "PID.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */






/*void skillsAuton()
{
  pros::Motor flyLWheel_mtr(5, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);
  pros::Motor flyRWheel_mtr(6, MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS);
  pros::Motor ballIntake_mtr(7, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);
  pros::Motor chainBar_mtr(8, MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS);

  resetPos();

  //Moves forward
  moveDrive(45, 77, -91, 0, 0);

  //flips cap
  moveDrive(51, 127, -91, 0, -50);

  ballIntake_mtr.move(60);

  pros::delay(575);

  //moves back
  moveDrive(0, -77, -82, 0, 40);

  resetPos();

  driveMotors1(-77);

  pros::delay(300);

  resetPos();

  pause();

  //moves a bit forward
  moveDrive(7, 57, -82, 0, 30);

  pause();

  //turns
  driveTurn(-90, -70);

  pros::delay(750);

  resetPos();

  ballIntake_mtr.move(65);

  flyWheel(-80);

  pros::delay(1200);

  resetPos();

  //moves forward to the low flag
  moveDrive(28, 63, -91, 0, 0);

  ballIntake_mtr.move(127);

  flyWheel(-91);

  pros::delay(1200);

  driveMotors(-50);

  pros::delay(200);

  resetPos();

  //toggles low flag
  moveDrive(14, 62, 0, 0, 0);

  moveDrive(0, -77, 0, 0, 0);


  driveMotors1(-77);

  pros::delay(200);

  //turns
  driveMotors(50);

  pros::delay(150);

  resetPos();

  //turns towards cap
  driveMotors(50);

  pros::delay(800);

  resetPos();

  // resets alignment with the wall so that it is consistently able to flip the cap
  driveMotors1(-77);

  pros::delay(900);

  driveMotors1(0);

  pause();

  resetPos();

  //flips cap
  moveDrive(29, 67, 0, 0, -50);

  moveDrive(0, -77, 0, 0, 0);

  moveDrive(6, 77, 0, 0, 0);

  // comes back and turns towards the direction of the back of the field
  driveTurn(90, 70);

  pros::delay(1000);

  resetPos();

  //moves to the back of the field
  moveDrive(70, 114, 0, 0, 0);

  pros::delay(200);

  driveTurn(-90, -77);

  pros::delay(1000);

  resetPos();

  driveMotors1(-67);

  pros::delay(800);

  resetPos();

  moveDrive(42, 87, 0, 0, 0);

  moveDrive(52, 107, 0, 0, -60);

  pause();

  ballIntake_mtr.move(127);

  pros::delay(650);

  moveDrive(48, -67, 0, 0, 0);

  driveTurn(90, 77);

  pros::delay(1000);

  resetPos();

  moveDrive(10, 99, 0, 0, 0);

  pause();

  driveTurn(-82, -77);

  pros::delay(1000);

  resetPos();

  moveDrive(58, 77, 0, 0, 0);

  driveTurn(-90, -77);

  pros::delay(1000);

  resetPos();

  driveMotors1(-65);

  pros::delay(1400);

  resetPos();

  moveDrive(70, 100, -91, 0, 0);

  ballIntake_mtr.move(127);

  flyWheel(-91);

  pros::delay(1000);

  driveTurn(-15, -77);

  pros::delay(300);

  resetPos();

  moveDrive(30, 87, 0, 0, -90);

  moveDrive(3, -87, 0, 0, -90);

  driveTurn(-75, -67);

  pros::delay(800);

  resetPos();

  driveMotors1(-77);

  pros::delay(1500);

  moveDrive(7, 67, -95, 0, 0);

  pause();

  driveTurn(-90, -77);

  pros::delay(1200);

  resetPos();

  moveDrive(22, 67, 0, 0, 0);

  pause();

  driveTurn(90, 77);

  pros::delay(1000);

  driveMotors1(-80);

  pros::delay(1000);

  resetPos();

  moveDrive(95, 87, 0, 0, 127);

  resetPos();

}*/
/*
void skillsAuton()
{
  pros::Motor flyLWheel_mtr(5, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);
  pros::Motor flyRWheel_mtr(6, MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS);
  pros::Motor ballIntake_mtr(7, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);
  pros::Motor chainBar_mtr(8, MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS);

  resetPos();

  //Moves forward
  moveDrive(45, 77, -91, 0, 0);

  //flips cap
  moveDrive(51, 127, -91, 0, -50);

  ballIntake_mtr.move(60);

  pros::delay(575);

  //moves back
  moveDrive(0, -77, -82, 0, 40);

  resetPos();

  driveMotors1(-77);

  pros::delay(300);

  resetPos();

  pause();

  //moves a bit forward
  moveDrive(7, 57, -82, 0, 30);

  pause();

  //turns
  driveTurn(-90, -70);

  pros::delay(750);

  resetPos();

  ballIntake_mtr.move(65);

  flyWheel(-80);

  pros::delay(1200);

  resetPos();

  //moves forward to the low flag
  moveDrive(28, 63, -91, 0, 0);

  ballIntake_mtr.move(127);

  flyWheel(-91);

  pros::delay(1200);

  driveMotors(-50);

  pros::delay(200);

  resetPos();

  //toggles low flag
  moveDrive(14, 62, 0, 0, 0);

  moveDrive(0, -77, 0, 0, 0);


  driveMotors1(-77);

  pros::delay(200);

  //turns
  driveMotors(50);

  pros::delay(150);

  resetPos();

  //turns towards cap
  driveMotors(50);

  pros::delay(800);

  resetPos();

  // resets alignment with the wall so that it is consistently able to flip the cap
  driveMotors1(-77);

  pros::delay(900);

  driveMotors1(0);

  pause();

  resetPos();

  //flips cap
  moveDrive(29, 67, 0, 0, -50);

  moveDrive(0, -77, 0, 0, 0);

  moveDrive(6, 77, 0, 0, 0);

  // comes back and turns towards the direction of the back of the field
  driveTurn(90, 70);

  pros::delay(1000);

  resetPos();

  //moves to the back of the field
  moveDrive(70, 114, 0, 0, 0);

  pros::delay(200);

  driveTurn(-90, -77);

  pros::delay(1000);

  resetPos();

  driveMotors1(-67);

  pros::delay(800);

  resetPos();

  moveDrive(42, 87, 0, 0, 0);

  moveDrive(52, 127, 0, 0, -50);

  pause();

  ballIntake_mtr.move(127);

  pros::delay(650);

  moveDrive(0, -87, -86, 0, 0);

  moveDrive(5, 67, -88, 0, 0);

  driveTurn(-65, -67);

  pros::delay(600);

  ballIntake_mtr.move(127);

  flyWheel(-88);

  pros::delay(1000);

  driveTurn(-20, -67);

  pros::delay(400);

  resetPos();

  moveDrive(21.5, 67, 0, 0, 0);

  driveTurn(90, 77);

  pros::delay(1000);

  driveMotors1(-87);

  pros::delay(750);

  resetPos();

  moveDrive(45, 57, 0, 0, 90);

  ballIntake_mtr.move(90);

  pros::delay(3000);

  resetPos();

  moveDrive(40, 87, 0, 0, 90);

}

void blueFrontAuton()
{
  pros::Motor flyLWheel_mtr(5, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);
  pros::Motor flyRWheel_mtr(6, MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS);
  pros::Motor ballIntake_mtr(7, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);
  pros::Motor chainBar_mtr(8, MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS);

  resetPos();

  //Moves forward
  moveDrive(40, 107, -91, 0, 0);

  //flips cap
  moveDrive(46, 127, -91, 0, 20);

  ballIntake_mtr.move(60);

  pros::delay(575);

  //moves back
  moveDrive(0, -100, -82, 0, 40);

  resetPos();

  pause();

  driveMotors1(-87);

  pros::delay(300);

  resetPos();

  pause();

  //moves a bit forward
  moveDrive(7, 67, -82, 0, 30);

  pause();

  //turns
  driveTurn(90, 80);

  pros::delay(750);

  resetPos();

  ballIntake_mtr.move(95);

  flyWheel(-80);

  pros::delay(910);

  resetPos();

  //moves forward to the low flag
  moveDrive(27, 93, -91, 0, 0);

  ballIntake_mtr.move(127);

  flyWheel(-91);

  pros::delay(1100);

  driveMotors(50);

  pros::delay(200);

  resetPos();

  //toggles low flag
  moveDrive(14, 62, 0, 0, 0);

  moveDrive(0, -77, 0, 0, 0);


  driveMotors1(-97);

  pros::delay(200);

  driveMotors(-67);

  pros::delay(90);

  resetPos();

  moveDrive(40, -110, 0, 0, 0);

  pause();

  driveTurn(-90, -77);

  pros::delay(900);

  resetPos();

  driveMotors1(-97);

  pros::delay(600);

  resetPos();

  moveDrive(57, 100, 0, 0, 90);

}

void redFrontAuton()
{
  pros::Motor flyLWheel_mtr(5, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);
  pros::Motor flyRWheel_mtr(6, MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS);
  pros::Motor ballIntake_mtr(7, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);
  pros::Motor chainBar_mtr(8, MOTOR_GEARSET_18, false, MOTOR_ENCODER_ROTATIONS);

  resetPos();

  //Moves forward
  moveDrive(40, 107, -91, 0, 0);

  //flips cap
  moveDrive(46, 127, -91, 0, 20);

  ballIntake_mtr.move(60);

  pros::delay(575);

  //moves back
  moveDrive(0, -100, -82, 0, 40);

  resetPos();

  pause();

  driveMotors1(-87);

  pros::delay(300);

  resetPos();

  pause();

  //moves a bit forward
  moveDrive(7, 67, -82, 0, 30);

  pause();

  //turns
  driveTurn(-90, -80);

  pros::delay(750);

  resetPos();

  ballIntake_mtr.move(95);

  flyWheel(-80);

  pros::delay(910);

  resetPos();

  //moves forward to the low flag
  moveDrive(27, 93, -91, 0, 0);

  ballIntake_mtr.move(127);

  flyWheel(-91);

  pros::delay(1100);

  driveMotors(-50);

  pros::delay(200);

  resetPos();

  //toggles low flag
  moveDrive(14, 62, 0, 0, 0);

  moveDrive(0, -77, 0, 0, 0);


  driveMotors1(-97);

  pros::delay(200);

  driveMotors(67);

  pros::delay(90);

  resetPos();

  moveDrive(38, -110, 0, 0, 0);

  pause();

  driveTurn(90, 77);

  pros::delay(900);

  resetPos();

  driveMotors1(-97);

  pros::delay(600);

  resetPos();

  moveDrive(57, 100, 0, 0, 90);
}

void blueBackAuton()
{

}

void visionSense()
{
  pros::Vision vision (9);
  pros::Motor ballIntake_mtr(7, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);

  pros::vision_object_s_t obj = vision.get_by_sig(0, 2);

  if(obj.signature == sig)
  {
    while(obj.signature == sig)
    {
      flyWheel(-90);
      ballIntake_mtr.move(127);
    }
    while(obj.signature == sig)
    {
      flyWheel(-83);
      ballIntake_mtr.move(87);
    }
  }
  else
  {
    if(sig == 1)
    {
      driveTurn(15, 67);
      pros::delay(400);

      flyWheel(-91);
      ballIntake_mtr.move(127);

      pros::delay(1000);
    }
    else if(sig == 2)
    {
      driveTurn(-15, -67);
      pros::delay(400);

      flyWheel(-91);
      ballIntake_mtr.move(127);

      pros::delay(1000);
    }
  }

  flyWheel(0);
  ballIntake_mtr.move(0);
}

void redBackAuton()
{
  pros::Motor ballIntake_mtr(7, MOTOR_GEARSET_18, true, MOTOR_ENCODER_ROTATIONS);
  resetPos();

  //Moves forward
  moveDrive(40, 107, -91, 0, 0);

  //flips cap
  moveDrive(46, 127, -91, 0, 20);

  ballIntake_mtr.move(60);

  pros::delay(575);

  //moves back
  moveDrive(0, -100, -82, 0, 40);

  resetPos();

  pause();

  driveMotors1(-87);

  pros::delay(300);

  resetPos();

  pause();

  moveDrive(7, 67, -82, 0, 30);

  pause();

  driveTurn(-62, -57);

  pros::delay(600);

  ballIntake_mtr.move(87);

  flyWheel(-83);

  pros::delay(1000);

  ballIntake_mtr.move(87);

  flyWheel(-74);

  pros::delay(1000);

  ballIntake_mtr.move(0);

  flyWheel(0);

  driveTurn(100, 77);

  pros::delay(800);

  resetPos();

  moveDrive(50, 87, 0, 0, -90);

}*/

void autonomous()
{
  moveDrive(10, 91, 0, 0, 0);
}
