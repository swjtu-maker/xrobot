#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <ros.h>
#include <std_msgs/UInt16.h>

//#define DEBUG

ros::NodeHandle  nh;

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
Stepper xRobotStepperLeft(stepsPerRevolution, 8, 9, 10, 11);
Stepper xRrobotStepperRight(stepsPerRevolution, 4, 5, 6, 7);

//小电机请将数值调小
int speed1=100;//小车速度控制0~255，数值越大，速度越快


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
  //led for test
  pinMode(13, OUTPUT);
  
  nh.initNode();
  nh.subscribe(sub);
  
}

void loop() {
  nh.spinOnce();
  delay(1); 
}

void goforward(){
  xRobotStepperLeft.setSpeed(speed1);  //rpm
  xRobotStepperLeft.step(stepsPerRevolution);
  xRobotStepperRight.setSpeed(speed1);  //rpm
  xRobotStepperRight.step(stepsPerRevolution);
}
void goback(){
  xRobotStepperLeft.setSpeed(speed1);  //rpm
  xRobotStepperLeft.step(-stepsPerRevolution);
  xRobotStepperRight.setSpeed(speed1);  //rpm
  xRobotStepperRight.step(-stepsPerRevolution);
}
void goleft(){
  xRobotStepperLeft.setSpeed(speed1);  //rpm
  xRobotStepperLeft.step(stepsPerRevolution);
  xRobotStepperRight.setSpeed(speed1);  //rpm
  xRobotStepperRight.step(-stepsPerRevolution);
}
void goright(){
  xRobotStepperLeft.setSpeed(speed1);  //rpm
  xRobotStepperLeft.step(-stepsPerRevolution);
  xRobotStepperRight.setSpeed(speed1);  //rpm
  xRobotStepperRight.step(stepsPerRevolution);
}

void stopcommand(){
  xRobotStepperLeft.setSpeed(0);  //rpm
  xRobotStepperLeft.step(stepsPerRevolution);
  xRobotStepperRight.setSpeed(0);  //rpm
  xRobotStepperRight.step(stepsPerRevolution);
}

