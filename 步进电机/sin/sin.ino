#include <AccelStepper.h>

// 定义引脚
#define X_STEP_PIN 5
#define X_DIR_PIN 4
#define Y_STEP_PIN 9
#define Y_DIR_PIN 8

// 创建两个步进电机对象
AccelStepper stepperX(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN);
AccelStepper stepperY(AccelStepper::DRIVER, Y_STEP_PIN, Y_DIR_PIN);

// 正弦波参数
const float amplitude = 100.0;  // 正弦波幅度（步数）
const float period = 400.0;    // 正弦波周期（步数）
const float stepsPerDegree = 10.0; // 每度对应的步数

// 系统参数
const float maxSpeed = 100000.0;  // 最大速度（步/秒）
const float acceleration = 50000.0;  // 加速度（步/秒²）

// 运动方向
bool movingForward = true;

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

  // 设置步进电机参数
  stepperX.setMaxSpeed(maxSpeed);
  stepperX.setAcceleration(acceleration);
  
  stepperY.setMaxSpeed(maxSpeed);
  stepperY.setAcceleration(acceleration);
}

void loop() {
  static float xPos = 0;
  
  // 计算Y轴位置（正弦函数）
  float yPos = amplitude * sin(2 * PI * xPos / period);
  
  // 设置目标位置
  stepperX.moveTo(xPos);
  stepperY.moveTo(yPos);
  
  // 运行电机到目标位置
  while (stepperX.distanceToGo() != 0 || stepperY.distanceToGo() != 0) {
    stepperX.run();
    stepperY.run();
  }
  
  // 更新X位置（根据方向）
  if (movingForward) {
    xPos += 0.1;
    if (xPos >= period) {
      movingForward = false;
    }
  } else {
    xPos -= 0.1;
    if (xPos <= 0) {
      movingForward = true;
    }
  }
}