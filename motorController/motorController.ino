/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *leftLegMotor  = AFMS.getMotor(1);
Adafruit_DCMotor *rightLegMotor = AFMS.getMotor(2);
Adafruit_DCMotor *waistMotor    = AFMS.getMotor(3);
Adafruit_DCMotor *armsMotor     = AFMS.getMotor(4);

const byte 1_STOP     = 0;
const byte 1_FORWARD  = 1;
const byte 1_BACKWARD = 2;

Adafruit_DCMotor *motors[] = {
  leftLegMotor,
  rightLegMotor,
  waistMotor,
  armsMotor};

void setup() {
  Serial.begin(9600);
  
  AFMS.begin();
  
  leftLegMotor->setSpeed(150);
  rightLegMotor->setSpeed(150);
  waistMotor->setSpeed(150);
  armsMotor->setSpeed(150);
}


void loop() {
  byte incomingByte = 0xFF;
  if(Serial.available()) {
    incomingByte = Serial.read();
  }
  if(incomingByte == 0xFF) {
    return;
  }
  byte m1 = incomingByte & 0x03;
  byte m2 = (incomingByte >> 2) & 0x03;
  byte op = (incomingByte >> 4) & 0x0F;
	switch(op) {
		case 1_FORWARD:
		motors[m1]->run(FORWARD);
		break;
		case 1_BACKWARD:
		motors[m1]->run(BACKWARD);
		break;
		case 1_STOP:
		motors[m1]->run(RELEASE);
		break;
		default:
		break;
	}
	
}
