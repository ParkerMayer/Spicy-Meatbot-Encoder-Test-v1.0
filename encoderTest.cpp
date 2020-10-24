#include <Arduino.h>
#include <Ultrasonic.h>
#include <Adafruit_PWMServoDriver.h>
#include <PS2X_lib.h>
#include <Encoder.h>

void driveTo(int goal, int power);

//2160 ticks per revolution
//~172 ticks per inch

byte leftBackward = 6;
byte leftForward = 5;
byte leftPWM = 7;
byte rightForward = 3;
byte rightBackward = 2;
byte rightPWM = 4;

//hee hee i love coding

Encoder left(18, 19);
Encoder right(20, 21);

long leftOldPos  = -999;
long rightOldPos  = -999;

void setup() {

		pinMode(leftBackward, OUTPUT);
		pinMode(leftForward, OUTPUT);
		pinMode(leftPWM, OUTPUT);
		pinMode(rightForward, OUTPUT);
		pinMode(rightBackward, OUTPUT);
		pinMode(rightPWM, OUTPUT);

		delay(10);

		//Serial.begin(9600);

		//delay(10);

		left.write(0);
		right.write(0);

		delay(1000);

		driveTo(2064, 50);

}

void loop() {

	//this chunk of code prints the current encoder reading to the terminal
	//whenever the position changes
	//note: uncomment the begin() function call for the serial terminal in setup()
	//if you plan to use this code

	/*String leftNewPos = String(left.read()*(-1));
	if (leftNewPos.toInt() != leftOldPos) {
	leftOldPos = leftNewPos.toInt();
	Serial.println("left: " + leftNewPos);
	}
	delay(100);

	String rightNewPos = String(right.read());
	if (rightNewPos.toInt() != rightOldPos) {
		rightOldPos = rightNewPos.toInt();
		Serial.println("right: " + rightNewPos);
	}
	delay(100);*/
}


//this function takes in a goal number of ticks and value for motor power
//and drives the drivetrain motors at the power until they reach the goal number of ticks ;))
void driveTo(int goal, int power){

	digitalWrite(leftForward, HIGH);
	digitalWrite(leftBackward, LOW);
	digitalWrite(rightForward, HIGH);
	digitalWrite(rightBackward, LOW);

	int currentLeftPos = 0;
	int currentRightPos = 0;

	while(currentLeftPos < goal && currentRightPos < goal){

		analogWrite(leftPWM, power);
		analogWrite(rightPWM, power);

		currentLeftPos = left.read();
		currentRightPos = right.read();

	}

	analogWrite(leftPWM, 0);
	analogWrite(rightPWM, 0);

}

