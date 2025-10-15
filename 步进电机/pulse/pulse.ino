// 定义步进电机控制引脚
const int stepPin = 5;    // 脉冲引脚
const int dirPin = 4;     // 方向引脚

// 设置参数
const int stepsPerRevolution = 200;  // 步进电机每转步数（根据你的电机型号调整）
const int pulseWidthMicros = 100;    // 脉冲宽度（微秒）
const int speedDelay = 500;          // 每步之间的延迟（微秒）

void setup() {
  // 初始化引脚模式
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  
  // 初始状态
  digitalWrite(dirPin, LOW);   // 设置初始方向
  
  Serial.begin(9600);
  Serial.println("步进电机控制已启动");
}

void loop() {
  // 顺时针旋转一圈
  Serial.println("顺时针旋转");
  digitalWrite(dirPin, LOW);  // 设置方向为顺时针
  rotateMotor(stepsPerRevolution);
  
  delay(1000);  // 暂停1秒
  
  // 逆时针旋转一圈
  Serial.println("逆时针旋转");
  digitalWrite(dirPin, HIGH);  // 设置方向为逆时针
  rotateMotor(stepsPerRevolution);
  
  delay(1000);  // 暂停1秒
}

// 旋转电机的函数
void rotateMotor(int steps) {
  for (int i = 0; i < steps; i++) {
    // 产生一个脉冲
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pulseWidthMicros);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(speedDelay);
  }
}