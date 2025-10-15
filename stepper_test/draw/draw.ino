#include <AccelStepper.h>
#include <math.h>  // 用于圆形计算

// 定义引脚
#define X_STEP_PIN 5
#define X_DIR_PIN 4
#define Y_STEP_PIN 9
#define Y_DIR_PIN 8

// 创建两个步进电机对象
AccelStepper stepperX(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN);
AccelStepper stepperY(AccelStepper::DRIVER, Y_STEP_PIN, Y_DIR_PIN);

// 图形参数
const float amplitude = 50.0;  // 图形幅度（步数）
const float period = 50.0;    // 周期（步数）

// 系统参数
const float maxSpeed = 100000.0;  // 最大速度（步/秒）
const float acceleration = 50000.0; // 加速度（步/秒²）

// 图形选择
enum Pattern { SINEWAVE, RECTANGLE, TRIANGLE, CIRCLE, HEART};
Pattern currentPattern = SINEWAVE; // 初始设置为正弦波

// 运动控制变量
bool movingForward = true;
float progress = 0.0; // 0.0到1.0表示图形绘制进度

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

  Serial.begin(9600);
  Serial.println("选择图形模式: 1=正弦波, 2=矩形, 3=三角形, 4=圆形, 5=爱心");
}

void loop() {
  // 检查串口输入以改变图形
  if (Serial.available()) {
    char c = Serial.read();
    switch(c) {
      case '1': currentPattern = SINEWAVE; break;
      case '2': currentPattern = RECTANGLE; break;
      case '3': currentPattern = TRIANGLE; break;
      case '4': currentPattern = CIRCLE; break;
      case '5': currentPattern = HEART; break;
    }
    progress = 0.0; // 重置进度
  }

  // 根据当前模式计算目标位置
  float xPos, yPos;
  calculatePattern(currentPattern, progress, &xPos, &yPos);
  
  // 设置目标位置
  stepperX.moveTo(xPos);
  stepperY.moveTo(yPos);
  
  // 运行电机到目标位置
  while (stepperX.distanceToGo() != 0 || stepperY.distanceToGo() != 0) {
    stepperX.run();
    stepperY.run();
  }
  
  // 更新进度
  if (movingForward) {
    progress += 0.001; // 调整这个值可以改变绘制速度
    if (progress >= 1.0) {
      movingForward = false;
    }
  } else {
    progress -= 0.001;
    if (progress <= 0.0) {
      movingForward = true;
    }
  }
}

// 计算不同图形的坐标
void calculatePattern(Pattern pattern, float t, float* x, float* y) {
  switch(pattern) {
    case SINEWAVE:
      // 正弦波: X轴线性移动，Y轴正弦变化
      *x = amplitude * (2*t - 1); // X从-amplitude到+amplitude
      *y = amplitude * sin(2 * PI * t);
      break;
      
    case RECTANGLE:
      // 矩形路径
      if (t < 0.25) { // 上边 (从左到右)
        *x = -amplitude + 8*amplitude*t;
        *y = amplitude;
      } else if (t < 0.5) { // 右边 (从上到下)
        *x = amplitude;
        *y = amplitude - 8*amplitude*(t-0.25);
      } else if (t < 0.75) { // 下边 (从右到左)
        *x = amplitude - 8*amplitude*(t-0.5);
        *y = -amplitude;
      } else { // 左边 (从下到上)
        *x = -amplitude;
        *y = -amplitude + 8*amplitude*(t-0.75);
      }
      break;
      
    case TRIANGLE:
      // 三角形路径
      if (t < 0.333) { // 从左下到右上
        *x = -amplitude + 6*amplitude*t;
        *y = -amplitude + 6*amplitude*t;
      } else if (t < 0.666) { // 从右上到右下
        *x = amplitude - 6*amplitude*(t-0.333);
        *y = amplitude - 6*amplitude*(t-0.333);
      } else { // 从右下回左下
        *x = -amplitude + 6*amplitude*(t-0.666);
        *y = -amplitude;
      }
      break;
      
    case CIRCLE:
      // 圆形路径
      *x = amplitude * cos(2 * PI * t);
      *y = amplitude * sin(2 * PI * t);
      break;

    case HEART:
      // 爱心形参数方程
      t = 2 * PI * t; // 转换为0-2π
      *x = 25 * amplitude/20 * pow(sin(t), 3);
      *y = amplitude/20 * (13*cos(t) - 5*cos(2*t) - 2*cos(3*t) - cos(4*t));
      break;
  }
}