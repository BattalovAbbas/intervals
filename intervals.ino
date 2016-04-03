#include <Servo.h> 
Servo servo1; 
Servo servo2; 
Servo servo3; 
int distance = 0; 
float degrees =0; 
void setup() 
{ 
	servo1.attach(13); 
	servo2.attach(12); 
	servo3.attach(11); 
	Serial.begin(9600); 
	servo2.write(0); 
	servo3.write(0); 
	servo1.write(0); 
} 

void loop() 
{ 
	if(Serial.available() > 0) 
	{ 
		String split = Serial.readString(); 
		distance = split.toInt()-100; 
		Serial.println(distance); 
		if(distance<300) 
		{ 
			servo2.write(0); 
			servo3.write(0); 
			degrees = (int)(distance/1.67); 
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