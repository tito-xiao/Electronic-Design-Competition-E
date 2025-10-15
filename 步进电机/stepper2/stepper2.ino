#include <AccelStepper.h>

#define STEPPER1_DIR_PIN    4
#define STEPPER1_STEP_PIN   5
#define STEPPER2_DIR_PIN    8
#define STEPPER2_STEP_PIN   9

AccelStepper stepper1(AccelStepper::DRIVER, STEPPER1_STEP_PIN, STEPPER1_DIR_PIN);  // 配置电机1 的脉冲引脚 方向引脚
AccelStepper stepper2(AccelStepper::DRIVER, STEPPER2_STEP_PIN, STEPPER2_DIR_PIN);  // 配置电机2 的脉冲引脚 方向引脚

#define pulse  3200  //电机旋转一圈的脉冲数
long positions[2];   //2个电机坐标位置

int pos1 = 50;
int pos2 = 50;

void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  stepper1.setMaxSpeed(pulse*1.5);      //设置1#电机最大速度
  stepper1.setSpeed(pulse*1.0);         //设置1#电机速度
  stepper1.setAcceleration(pulse/4);    //设置1#电机加速度
  stepper2.setMaxSpeed(pulse*1.5);
  stepper2.setSpeed(pulse*1.0);
  stepper2.setAcceleration(pulse/4);
  delay(100);
}

void loop() 
{
//  /*================1、绝对位置运动1---向前转3圈=============================*/
//   //设置电机的目标位置
//   positions[0] = pulse*3;
//   stepper1.runToNewPosition(positions[0]);
//   //串口反馈1#电机当前的位置
//   Serial.print("stepper1.currentPosition: ");
//   Serial.println(stepper1.currentPosition());
//   delay(500);
 
//  /*================2、绝对位置运动2---到零位=============================*/
//   // 设置电机的目标位置
//   positions[0] = pulse*0;
//   stepper1.runToNewPosition(positions[0]);
//   //串口反馈1#电机当前的位置
//   Serial.print("stepper1.currentPosition: ");
//   Serial.println(stepper1.currentPosition());
//   delay(500);


  //1、增量式运动---2秒运行一次
  // stepper1.move(pulse/4);
  // stepper1.runToPosition();
  // delay(500);

  //2、绝对位置运动--2秒运行一次
  stepper2.moveTo(pulse*0.25);
  stepper2.runToPosition();
  delay(500);
  stepper2.moveTo(pulse*0);
  stepper2.runToPosition();
  delay(500);

	// if (stepper1.distanceToGo() == 0)
	// {
	// 	// delay(500);
	// 	pos1 = -pos1;
	// 	stepper1.moveTo(pos1);
	// }
	// if (stepper2.distanceToGo() == 0)
	// {
	// 	// delay(500);
	// 	pos2 = -pos2;
	// 	stepper2.moveTo(pos2);
	// }
	// stepper1.run();
	// stepper2.run();
}