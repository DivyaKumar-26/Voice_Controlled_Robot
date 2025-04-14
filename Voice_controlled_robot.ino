#include <Servo.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>



SoftwareSerial BTSerial(2, 4); // RX = D2 and TX =D4

Servo servom;

const int in1=8,in2=9,en1=10;
const int en2=11,in3=12,in4=13; // motor driver pins 

const int trig=4,echo=5;  // ultrasonic sensor pins

long duration=0;
float distance=0;
float mindistance=0.5; // for ultrasonic sensor calculations

int position=0; // servo control

String bt_read=""; // to read bluetooth data 

int time_of_motion=4; // time of motion in seconds

char switch_var;  // variable for switch case
 
void setup() {

pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(en1,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(en2,OUTPUT);

pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

servom.attach(6);

Serial.begin(9600);
BTSerial.begin(9600);



}

void loop() {

  if (BTSerial.available()) {
    bt_read=BTSerial.readStringUntil('\n');
    bt_read.trim();
    Serial.println(bt_read);
    
}

  // for(position=0;position<=180;position+=5){
  //   Serial.print(position);
  //   servom.write(position);
  //   delay(20);
  // } 

  // for(position=180;position>=0;position-=5){
  //   // Serial.print(position);
  //   servom.write(position);
  //   delay(20);
  // }

  // digitalWrite(trig,LOW);
  // delay(5);
  // digitalWrite(trig,HIGH);
  // delay(15);
  // digitalWrite(trig,LOW);

  // duration=pulseIn(echo,HIGH);
  // distance=duration*0.17;

  // if(distance>=mindistance){
    // Serial.println("code running!!");

  if(bt_read =="1"){
        Serial.println("working!!");
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(12, HIGH);
        digitalWrite(13, LOW);
        analogWrite(10,140);
        analogWrite(11,80);
        delay(1000*time_of_motion);
        analogWrite(en1,0);
        analogWrite(en2,0);

     } else if(bt_read=="move backward" || bt_read=="go backward" || bt_read=="move back" || bt_read==" go back"){
        
        Serial.println("working! !");

        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(en1,140);
        analogWrite(en2,80);
        delay(1000*time_of_motion);
        analogWrite(en1,0);
        analogWrite(en2,0);
      } else if (bt_read=="move left"|| bt_read=="turn left"){
        
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(en1,140);
        analogWrite(en2,80);
        delay(400*time_of_motion);
        analogWrite(en1,0);
        analogWrite(en2,0);
      }else if (bt_read=="move right"|| bt_read=="turn right"){
        
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        analogWrite(en1,140);
        analogWrite(en2,80);
        delay(400*time_of_motion);
        analogWrite(en1,0);
        analogWrite(en2,0);

  } //}
  // else{
   
  // Serial.println("minimum distance reached!!!");
  // BTSerial.write("minimum distance reached!!!");

  // }




}
