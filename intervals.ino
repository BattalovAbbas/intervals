#include <Servo.h> 
Servo myservo; 
int echoPin = 9; 
int trigPin = 8; 

Servo servo1; 
Servo servo2; 
Servo servo3; 
int distance = 0; 
int degrees =0; 
int mediumDistance =0;

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
	dist = pulseIn(echoPin, HIGH, 2941); 
	distance = (int)dist / 5.82;
	Serial.print(distance); 
	Serial.println(" mm"); 
} 
void loop() 
{ 
	distans ();
	mediumDistance = (mediumDistance + distance)/2;
	if(mediumDistance<=300)
	{ 
		servo2.write(0); 
		servo3.write(10); 
		degrees = (int)(mediumDistance/1.67); 
		servo1.write(degrees); 
		Serial.println(degrees); 
	} 
	else if(mediumDistance<=600) 
	{ 
		servo1.write(180); 
		servo3.write(10); 
		degrees = (int)((mediumDistance-300)/1.67); 
		servo2.write(degrees); 
		Serial.println(degrees); 
	} 
	else if(mediumDistance<=900) 
	{ 
		servo1.write(180); 
		servo2.write(180); 
		degrees = (int)((mediumDistance-600)/1.67); 
		servo3.write(degrees); 
		Serial.println(degrees); 
	} 
	delay(100); 
}
