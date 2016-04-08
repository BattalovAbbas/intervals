#include <Servo.h> 
Servo myservo; 
int echoPin = 9; 
int trigPin = 8; 

Servo servo1; 
Servo servo2; 
Servo servo3; 
<<<<<<< HEAD
int distance = 0; 
int degrees =0; 


=======
int distance = 0; // Расстояние
float degrees =0; // Угол
>>>>>>> origin/ThirdTask
void setup() 
{ 
	pinMode(trigPin, OUTPUT); 
	pinMode(echoPin, INPUT); 
	Serial.begin(9600); 

	servo1.attach(13); 
	servo2.attach(12); 
	servo3.attach(11); 
	servo2.write(0); 
	servo3.write(10); 
	servo1.write(10); 
} 

void distans () 
{ 
	float dist; 
	digitalWrite(trigPin, LOW); 
	delayMicroseconds(2); 
	digitalWrite(trigPin, HIGH); 
	delayMicroseconds(10); 
	digitalWrite(trigPin, LOW); 
	dist = pulseIn(echoPin, HIGH); 
	distance = (int)dist / 58 *10;
	Serial.print(distance); 
	Serial.println(" mm"); 
} 
void loop() 
{ 
<<<<<<< HEAD
	distans(); 
	if(distance<=300)
	{ 
		servo2.write(0); 
		servo3.write(10); 
		degrees = (int)(distance/1.67); // ������� ���� ������� 
		servo1.write(degrees); 
		Serial.println(degrees); 
	} 
	else if(distance<=600) 
	{ 
		servo1.write(180); 
		servo3.write(10); 
		degrees = (int)((distance-300)/1.67); 
		servo2.write(degrees); 
		Serial.println(degrees); 
	} 
	else if(distance<=900) 
	{ 
		servo1.write(180); 
		servo2.write(180); 
		degrees = (int)((distance-600)/1.67); 
		servo3.write(degrees); 
		Serial.println(degrees); 
	} 
	delay(100); 
}
=======
	if(Serial.available() > 0) // Ручной ввод дистанции в дальнейшем через Ультразвуковой датчик измерения расстояния HC-SR04
	{ 
		String split = Serial.readString(); 
		distance = split.toInt()-100; // Минус 100 м для точности датчика измерения расстояния
		Serial.println(distance); 
		if(distance<300) // Если расстояние меньше 300мм 
		{ 
			servo2.write(0); 
			servo3.write(0); 
			degrees = (int)(distance/1.67); // Рассчет угла наклона
			servo1.write(degrees); 
			Serial.println(degrees); 
			delay(1000); 
		} 
		else if(distance<600) 
		{ 
			servo1.write(180); 
			servo3.write(0); 
			degrees = (int)((distance-300)/1.67); 
			servo2.write(degrees); 
			Serial.println(degrees); 
			delay(1000); 
		} 
		else 
		{ 
			servo1.write(180); 
			servo2.write(180); 
			degrees = (int)((distance-600)/1.67); 
			servo3.write(degrees); 
			Serial.println(degrees); 
			delay(1000); 
		} 

	} 
}
>>>>>>> origin/ThirdTask
