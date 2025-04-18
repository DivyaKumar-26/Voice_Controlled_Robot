#include <SoftwareSerial.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

SoftwareSerial BTSerial(2, 4); // RX = D2 and TX =D4

String bt_read=""; // to read bluetooth data 
int i=0;

int time_of_motion=4; // time of motion in seconds
 
void setup() {

Serial.begin(9600);
BTSerial.begin(9600);

}

void loop() {

  if (BTSerial.available()) {
    bt_read=BTSerial.readStringUntil('\n');
    bt_read.trim();
    bt_read.toLowerCase();
    Serial.println(bt_read);
    
}

   if(bt_read =="move forward" || bt_read=="go forward" || bt_read=="move straight" || bt_read=="go straight"|| bt_read=="go ahead"|| bt_read=="move ahead"){
       Serial.println("working!!");
        motor1.setSpeed(70);
        motor2.setSpeed(52);
        motor1.run(FORWARD);
        motor2.run(FORWARD);

        delay(1000*time_of_motion);
        motor1.setSpeed(0);
        motor2.setSpeed(0);
        bt_read="";

     } else if(bt_read=="move backward" || bt_read=="go backward" || bt_read=="move back" || bt_read==" go back"){

        motor1.setSpeed(70);
        motor2.setSpeed(52);
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);

        delay(1000*time_of_motion);
        motor1.setSpeed(0);
        motor2.setSpeed(0);
        bt_read="";
      } else if (bt_read=="move left"|| bt_read=="turn left"){
        
        motor1.setSpeed(130);
        motor2.setSpeed(65);
        motor1.run(FORWARD);
        motor2.run(FORWARD);

        delay(1000*time_of_motion);
        motor1.setSpeed(0);
        motor2.setSpeed(0);
        bt_read="" ;
      }else if (bt_read=="move right"|| bt_read=="turn right"){

        motor1.setSpeed(70);
        motor2.setSpeed(120);
        motor1.run(FORWARD);
        motor2.run(FORWARD);

        delay(1000*time_of_motion);
        motor1.setSpeed(0);
        motor2.setSpeed(0);
        bt_read="" ;


  }


}
