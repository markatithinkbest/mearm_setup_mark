/*
 * 10/16/2015
 * Mark Chen in Taichung, Taiwan
 *
 */

#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int STD_DELAY=13; //連續動作時的delay, 4很快,12很有機器人的慢節奏
int LONG_DELAY=60;//每一小動的delay,60 ok

int value=0;

// Arduino Senser Sheld 5.0
int m1Pin=3;
int m2Pin=5;
int m3Pin=6;
int m4Pin=9;

// 給定的伺服馬達,從 m 運動到 n
// 這兩個值的區間是 0 到180
// 但受到手臂結構限制,不能全部運動
// 因此要一個一個調試
void servoAct(Servo servo,int m, int n){
  if (m<n){
    for (int i=m;i<=n;i++){
      servo.write(i*1);
      delay(STD_DELAY);
    }
  }  
  if (m>n){
    for (int i=m;i>=n;i--){
    servo.write(i*1);
      delay(STD_DELAY);
      delay(STD_DELAY);
    }
  } 
  delay(LONG_DELAY);
}

// 這是組合的範例
void combo1(){
  servoAct(servo4,90,150);//底盤起始位置90度,轉到150度的位置
  
  servoAct(servo1,90,110);//張開手爪
  servoAct(servo2,90,160);//手臂向前
  servoAct(servo1,110,30);//握緊手爪  
  servoAct(servo2,160,90); //手臂回縮
   
  servoAct(servo4,150,90);//底盤轉到90度的位置
  servoAct(servo4,90,30); //底盤轉到30度的位置
    
  servoAct(servo2,90,160);//手臂向前
  servoAct(servo1,30,110);//張開手爪
  servoAct(servo2,160,90);//手臂回縮
  servoAct(servo1,110,30);//握緊手爪
  
  servoAct(servo4,30,90); //底盤轉到90度的起始位置 
} 

void testServo1(){
  servoAct(servo1,90,30);
  servoAct(servo1,30,90);
}
void testServo2(){
  servoAct(servo2,90,160);
  servoAct(servo2,160,90);    
}
void testServo3(){
  servoAct(servo3,90,160);
  servoAct(servo3,160,90);    
}
void testServo4(){
  servoAct(servo4,90,30);
  servoAct(servo4,30,90);    
  servoAct(servo4,90,150);
  servoAct(servo4,150,90);    
}





void setup() {
 
  servo1.attach(m1Pin); // 手爪
  servo2.attach(m2Pin); // 前後
  servo3.attach(m3Pin); // 上下
  servo4.attach(m4Pin); // 底盤

  for (int k=0;k<3;k++){
//    單獨伺服馬達測試
//    testServo1();
//    testServo2();
//    testServo3();
//    testServo4(); 

    //組合展示一:機械手臂到左旁拿東西放到右邊
    combo1(); 
  }
}

void loop() {
  // 另案開發,此處空白
}
