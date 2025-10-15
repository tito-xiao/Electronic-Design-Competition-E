#include <AccelStepper.h>

const int xdirPin  = 4;     // 方向控制引脚
const int xstepPin = 5;    // 步进控制引脚
const int ydirPin  = 8;     // 方向控制引脚
const int ystepPin = 9;    // 步进控制引脚
const int xmoveSteps = 300;     // 运行步数
const int ymoveSteps = 1000;    // 运行步数

#define CIRCLE_Puls  1600

AccelStepper stepperX(1, xstepPin, xdirPin);  // 建立步进电机对象
AccelStepper stepperY(2, ystepPin, ydirPin);

int center_x = 415;
int center_y = 235;
int error_X = 0;
int error_Y = 0;

// 按键引脚定义
#define BUTTON1_PIN 2
#define BUTTON2_PIN 3

enum States {
  STOP,
  LEFT,
  RIGHT,
  GOGOGO
} State = STOP;

enum BackStates {
  JUDGE,
  UP,
  DOWN,
  LEFT2,
  RIGHT2
} BackState;

int back = 1;
int time = 0, target = 0;

void setup() {
  Serial.begin(115200);  // 硬件串口用于打印
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

  pinMode(12, OUTPUT);  // 激光
  digitalWrite(12, LOW);  // 继电器

  pinMode(13, INPUT);  // 限位开关

  // 按键轮询
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);

  // 设置电机参数
  stepperX.setMaxSpeed(30000);
  // stepperX.setSpeed(10000);
  stepperX.setAcceleration(30000);

  stepperY.setMaxSpeed(30000);
  // stepperY.setSpeed(10000);
  stepperY.setAcceleration(30000);
  
  // 初始位置设为0
  stepperX.setCurrentPosition(0);
  stepperY.setCurrentPosition(0);
}

void loop() {
  switch (State)
  {
  case STOP:
      stepperX.stop();
      stepperY.stop();
      Serial.println("00000");
      if (digitalRead(A0) == 0) {
        
      } else if (digitalRead(A1) == 0) {
        State = RIGHT;
      } else if (digitalRead(A2) == 0) {
        State = LEFT;
      } else if (digitalRead(A3) == 0) {
        time = millis();
        target = 1800;
        State = GOGOGO;
      }
      break;
  case LEFT:
      switch(BackState) {
      case JUDGE:
          if (digitalRead(A4) == 1) {
            BackState = UP;
          } else {
            BackState = DOWN;
          }
      break;
      case UP:
          if (digitalRead(A4) == 1) {
            stepperY.move(CIRCLE_Puls*0.2);
            stepperY.runToPosition();
          } else {
            BackState = LEFT2; 
          }
      break;
      case DOWN:
          if (digitalRead(A4) == 0) {
            stepperY.move(-CIRCLE_Puls*0.2);
            stepperY.runToPosition();
          } else {
            BackState = LEFT2; 
          }
      break;
      case LEFT2:
          if (Serial.available()) {
            String data = Serial.readStringUntil('\n');
            data.trim();
            if (data.startsWith("Center_text: (")) {  // 解析坐标格式
              int left = data.indexOf('(') + 1;
              int comma = data.indexOf(',');
              int right = data.indexOf(')');
              
              if (left < comma && comma < right) {
                center_x = data.substring(left, comma).toInt();
                Serial.println(center_x);
                if (center_x == 9999) {
                  stepperX.move(-CIRCLE_Puls*0.01);
                  stepperX.runToPosition();
                } else {
                  time = millis();
                  target = 2500;
                  State = GOGOGO;
                }
              }
            }
          }
      break;
      }
      break;
  case RIGHT:
      switch(BackState) {
      case JUDGE:
          if (digitalRead(A4) == 1) {
            BackState = UP;
          } else {
            BackState = DOWN;
          }
      break;
      case UP:
          if (digitalRead(A4) == 1) {
            stepperY.move(CIRCLE_Puls*0.2);
            stepperY.runToPosition();
          } else {
            BackState = RIGHT2;
          }
      break;
      case DOWN:
          if (digitalRead(A4) == 0) {
            stepperY.move(-CIRCLE_Puls*0.2);
            stepperY.runToPosition();
          } else {
            BackState = RIGHT2; 
          }
      break;
      case RIGHT2:
          if (Serial.available()) {
            String data = Serial.readStringUntil('\n');
            data.trim();
            if (data.startsWith("Center_text: (")) {  // 解析坐标格式
              int left = data.indexOf('(') + 1;
              int comma = data.indexOf(',');
              int right = data.indexOf(')');
              
              if (left < comma && comma < right) {
                center_x = data.substring(left, comma).toInt();
                Serial.println(center_x);
                if (center_x == 9999) {
                  stepperX.move(CIRCLE_Puls*0.01);
                  stepperX.runToPosition();
                } else {
                  time = millis();
                  target = 2500;
                  State = GOGOGO;
                }
              }
            }
          }
      break;
      }
      break;
  case GOGOGO:
      if (Serial.available()) {
        String data = Serial.readStringUntil('\n');
        data.trim();
        if (data.startsWith("Center_text: (")) {  // 解析坐标格式
          int left = data.indexOf('(') + 1;
          int comma = data.indexOf(',');
          int right = data.indexOf(')');
          
          if (left < comma && comma < right) {
            center_x = data.substring(left, comma).toInt();
            center_y = data.substring(comma + 1, right).toInt();
            if (center_x == 9999) {
              center_x = 415;
            }
            if (center_y == 9999) {
              center_y = 235;
            }
            // 打印接收的坐标
            Serial.print(center_x);
            Serial.print(",");
            Serial.print(center_y);
            Serial.print(" ");
            Serial.print(error_X);
            Serial.print(",");
            Serial.println(error_Y);

            error_X = (center_x - 420) / 5;
            error_Y = (center_y - 240) / 5;

            // 设置新目标位置
            stepperX.move(error_X);
            stepperY.move(-error_Y);
          }
        }
      }
      stepperX.run();
      stepperY.run();
      if (millis() - time > target) {
        digitalWrite(12, HIGH);
      }
      break;
  }
}