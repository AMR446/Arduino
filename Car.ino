
/*
	A line follower car
	which stops when the
	ultrasonic sensor detects
	an obstacle.

	Necessary modules: 

	x1 Ultrasonic sensor
	x1 Arduino of any type
	x1 H-bridge to conrol motors
	x4 DC Motors for wheels
	x4 wheels
	x2 IR obstacle sensors
	x4 led's for lights
	x2 Li-ion rechargeable batteries
	x1 A battery holder
	x1 Buzzer

*/

#define TRIG 2 // Pins of the Ultrasonic sensor
#define ECHO 3

#define LINE_1 4 // Two IR obstacle sensors
#define LINE_2 5

#define MOTOR_A_CLK 6 // Pins on the H-bridge
#define MOTOR_A_CCLK 7
#define MOTOR_B_CLK 8
#define MOTOR_B_CCLK 9

#define BUZZ 10 // Buzzer
#define FRONT_LEDS 11 // Front nd back lights of the car
#define BACK_LEDS 12

#define BLINK_TIME 500
#define MAX_DIST 15 
// cm

#include <Ultrasonic.h> 
#include <GyverTimer.h>

GTimer time(MS, BLINK_TIME);
Ultrasonic sonar(TRIG, ECHO);
byte dist;
bool rightln, leftln, leds = 0;

void setup() {
	Serial.begin(9600);
	pinMode(LINE_1, INPUT);
	pinMode(LINE_2, INPUT);
	pinMode(MOTOR_A_CLK, OUTPUT);
	pinMode(MOTOR_A_CCLK, OUTPUT);
	pinMode(MOTOR_B_CLK, OUTPUT);
	pinMode(MOTOR_B_CCLK, OUTPUT);
	pinMode(BUZZ, OUTPUT);
	pinMode(FRONT_LEDS, OUTPUT);
	pinMode(BACK_LEDS, OUTPUT);
}


void loop() {
	rightln = digitalRead(LINE_1);
	leftln = digitalRead(LINE_2);
	dist = sonar.read();

	if (rightln && leftln)
	{
		stop_car();
	} else if (!rightln && leftln)
	{
		turn_right();
	} else if (rightln && !leftln)
	{
		turn_left();
	} else if (!rightln && !leftln)
	{
		forward();
	}

	if (dist <= MAX_DIST) 
	{
		stop_car();
		digitalWrite(BUZZ, HIGH);
		if (time.isReady() && !leds)
		{
			digitalWrite(FRONT_LEDS, HIGH);
			digitalWrite(BACK_LEDS, LOW);
			leds = !leds;
		} else {
			digitalWrite(FRONT_LEDS, LOW);
			digitalWrite(BACK_LEDS, HIGH);
			leds = !leds;
		}
	} else {
		digitalWrite(BUZZ, LOW);
	}
}

void stop_car() {
	digitalWrite(MOTOR_A_CLK, LOW);
	digitalWrite(MOTOR_A_CCLK, LOW);
	digitalWrite(MOTOR_B_CLK, LOW);
	digitalWrite(MOTOR_B_CCLK, LOW);
}

void forward() {
	digitalWrite(MOTOR_A_CLK, HIGH);
	digitalWrite(MOTOR_A_CCLK, LOW);
	digitalWrite(MOTOR_B_CLK, HIGH);
	digitalWrite(MOTOR_B_CCLK, LOW);
}

void turn_right() {
	digitalWrite(MOTOR_A_CLK, HIGH);
	digitalWrite(MOTOR_A_CCLK, LOW);
	digitalWrite(MOTOR_B_CLK, LOW);
	digitalWrite(MOTOR_B_CCLK, HIGH);
}

void turn_left() {
	digitalWrite(MOTOR_A_CLK, LOW);
	digitalWrite(MOTOR_A_CCLK, HIGH);
	digitalWrite(MOTOR_B_CLK, HIGH);
	digitalWrite(MOTOR_B_CCLK, LOW);
}



