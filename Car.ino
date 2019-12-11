#define TRIG 2 // Пины ультразвукового дальномера
#define ECHO 3

#define LINE_1 4 // Два выхода ИК-датчиков препятствия
#define LINE_2 5

#define MOTOR_A_CLK 6 // Пины для управления моторами через драйвер моторов
#define MOTOR_A_CCLK 7
#define MOTOR_B_CLK 8
#define MOTOR_B_CCLK 9

#define BUZZ 10 // Зуммер
#define FRONT_LEDS 11 // Передние и задние фары машины
#define BACK_LEDS 12

#include <Ultrasonic.h> 

Ultrasonic sonar(TRIG, ECHO);
byte dist;
unsigned long timer;  // Для мигания фарами
byte interval = 500;

void setup() {
	Serial.begin(9600); // Для НС-05
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

}

void up() {
	
}




