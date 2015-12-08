#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <ros.h>
#include <std_msgs/UInt16.h>

//#define DEBUG

ros::NodeHandle  nh;

//小电机请将数值调小
int speed1=64;//小车速度控制0~255，数值越大，速度越快

int enable1 = 22;
int enable2 = 23;

int dir1 = 24;
int dir2 = 25;

int pwm1 = 8;
int pwm2 = 9;

void goforward();
void goleft();
void goright();
void goback();
void stopcommand();
void move_cb( const std_msgs::UInt16& cmd_msg);

void move_cb( const std_msgs::UInt16& cmd_msg){
  //digitalWrite(13, HIGH-digitalRead(13));  //toggle led 
  //if(cmd_msg.data & 0x8000)//首位为1，向前
  if(cmd_msg.data == 0x8000)
  {
     goforward(); 
     delay(1000);
     stopcommand();
     digitalWrite(13, HIGH-digitalRead(13));  //toggle led 
  }
  else if(cmd_msg.data & 0x4000)//第二位为1，向后
  {
     goback();
    delay(1000);
     stopcommand();
  }
  else if(cmd_msg.data & 0x2000)//第三位为1，向左
  {
     goleft();
     delay(1000);
     stopcommand();
  }
  else if(cmd_msg.data & 0x1000)//第四位为1，向右
  {
     goright();
     delay(1000);
     stopcommand();
  }
  else
  {
     
  } 
  delay(1000);   
  delay(1000); 
  stopcommand();  
}

ros::Subscriber<std_msgs::UInt16> sub("movetest", move_cb);

void setup(){
  // put your setup code here, to run once:
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  //led for test
  pinMode(13, OUTPUT);
  
  digitalWrite(enable1,HIGH);
  digitalWrite(enable2,HIGH);
  
  nh.initNode();
  nh.subscribe(sub);
  
}

void loop() {
  nh.spinOnce();
  delay(1); 
}

void goforward(){
 digitalWrite(dir1,1);
 digitalWrite(dir2,1);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}
void goback(){
 digitalWrite(dir1,0);
 digitalWrite(dir2,0);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}
void goleft(){
 digitalWrite(dir1,1);
 digitalWrite(dir2,0);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}
void goright(){
 digitalWrite(dir1,0);
 digitalWrite(dir2,1);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
}

void stopcommand(){
  
 analogWrite(pwm1,0);
 analogWrite(pwm2,0);
 digitalWrite(enable1,LOW);
  digitalWrite(enable2,LOW);
}

