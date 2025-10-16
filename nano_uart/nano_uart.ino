// 坐标变量
int x = 0, y = 0;

void setup() {
  Serial.begin(115200);  // 硬件串口用于打印
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    data.trim();
    
    // 解析坐标格式
    if (data.startsWith("Center_text: (")) {
      int left = data.indexOf('(') + 1;
      int comma = data.indexOf(',');
      int right = data.indexOf(')');
      
      if (left < comma && comma < right) {
        x = data.substring(left, comma).toInt();
        y = data.substring(comma + 1, right).toInt();
        // 打印接收的坐标
        Serial.print(x); Serial.print(","); Serial.println(y);
      }
    }
  }
  delay(5);
}
    