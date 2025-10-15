 #include <AccelStepper.h>

const int xdirPin  = 4;     // 方向控制引脚
const int xstepPin = 10;    // 步进控制引脚
const int ydirPin  = 5;     // 方向控制引脚
const int ystepPin = 11;    // 步进控制引脚
const int xmoveSteps = 300;     // 运行步数
const int ymoveSteps = 1000;    // 运行步数

AccelStepper stepperX(1, xstepPin, xdirPin);  // 建立步进电机对象
AccelStepper stepperY(2, ystepPin, ydirPin);

void setup() {
  Serial.begin(9600);
  pinMode(xstepPin, OUTPUT);
  pinMode(xdirPin,  OUTPUT);
  pinMode(ydirPin,  OUTPUT);
  pinMode(ystepPin, OUTPUT);
  
  // 设置电机参数
  stepperX.setMaxSpeed(10000);
  stepperX.setAcceleration(2000);
  
  stepperY.setMaxSpeed(20000);
  stepperY.setAcceleration(5000);
  
  // 初始位置设为0
  stepperX.setCurrentPosition(0);
  stepperY.setCurrentPosition(0);
}

void loop() {
  stepperX.run();
  stepperY.run();
}