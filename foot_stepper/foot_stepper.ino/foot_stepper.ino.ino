/*
robot  moto control test

 */

int speed1=64;//小车速度控制0~255，数值越大，速度越快

int enable1 = 22;
int enable2 = 23;

int dir1 = 24;
int dir2 = 25;

int pwm1 = 8;
int pwm2 = 9;


void setup() {
  // nothing happens in setup
  pinMode(enable1, OUTPUT);
  pinMode(dir1, OUTPUT);
  digitalWrite(enable1, HIGH); 
   
  pinMode(enable2, OUTPUT);
  pinMode(dir2, OUTPUT);
  digitalWrite(enable2, HIGH);  
}

void loop() {
  digitalWrite(dir1, HIGH); 
   analogWrite(pwm1, speed1);
  digitalWrite(dir2, LOW); 
   analogWrite(pwm2, speed1);
}


