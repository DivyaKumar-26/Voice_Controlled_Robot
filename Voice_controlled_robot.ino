#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

SoftwareSerial BTSerial(2, 4); // RX = D2 and TX =D4

const int trig=14,echo=15;  // ultrasonic sensor pins

long duration=0;
float distance=0;
float mindistance=0.5; // for ultrasonic sensor calculations

int position=0; // servo control

String bt_read=""; // to read bluetooth data 
int i=0;

int time_of_motion=4; // time of motion in seconds
 
void setup() {

pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

Serial.begin(9600);
BTSerial.begin(9600);



}

void loop() {

  if (BTSerial.available()) {
    bt_read=BTSerial.readStringUntil('\n');
    bt_read.trim();
    Serial.println(bt_read);
    
}


  digitalWrite(trig,LOW);
  delay(5);
  digitalWrite(trig,HIGH);
  delay(15);
  digitalWrite(trig,LOW);

  duration=pulseIn(echo,HIGH);
  distance=duration*0.17;

  if(distance>=mindistance){
    Serial.println("code running!!");

     if(bt_read =="move forward" || bt_read=="go forward" || bt_read==" move straight" || bt_read==" go straight"){

        motor1.setSpeed(60);
        motor2.setSpeed(60);
        motor1.run(FORWARD);
        motor2.run(FORWARD);

        delay(1000*time_of_motion);
        motor1.setSpeed(0);
        motor2.setSpeed(0);
        bt_read=""

     } else if(bt_read=="move backward" || bt_read=="go backward" || bt_read=="move back" || bt_read==" go back"){

        motor1.setSpeed(60);
        motor2.setSpeed(60);
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);

        delay(1000*time_of_motion);
        motor1.setSpeed(0);
        motor2.setSpeed(0);
        bt_read=""
      } else if (bt_read=="move left"|| bt_read=="turn left"){
        
        motor1.setSpeed(90);
        motor2.setSpeed(60);
        motor1.run(FORWARD);
        motor2.run(FORWARD);

        delay(400*time_of_motion);
        motor1.setSpeed(0);
        motor2.setSpeed(0);
        bt_read=""
      }else if (bt_read=="move right"|| bt_read=="turn right"){

        motor1.setSpeed(60);
        motor2.setSpeed(90);
        motor1.run(FORWARD);
        motor2.run(FORWARD);

        delay(400*time_of_motion);
        motor1.setSpeed(0);
        motor2.setSpeed(0);
        bt_read=""

  } }
  else{
   
  Serial.println("minimum distance reached!!!");
  BTSerial.write("minimum distance reached!!!");

  }


}
