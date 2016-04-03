#include <Servo.h> //используем библиотеку для работы с сервоприводом 
Servo servo1; 
Servo servo2; 
Servo servo3; 
int distance = 0; // Дистанция
float degrees =0; // Угол наклона
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
	if(Serial.available() > 0) // Ручной ввод расстояния, в дальшейшем через Ультразвуковой датчик измерения расстояния
	{ 
		String split = Serial.readString(); // Считываем дистанцию введеную дистанцию в мм
		distance = split.toInt()-100; // Минус 100 мм 
		Serial.println(distance); 
		if(distance<300) // Если расстояние меньше 300мм крутим первый серв
		{ 
			servo2.write(0); 
			servo3.write(0); 
			degrees = (int)(distance/1.67); // Высчитываем угол
			servo1.write(degrees); 
			Serial.println(degrees); 
			delay(1000); 
		} 
		else if(distance<600) Если расстояние больше 300 но меньше 600мм крутим второй серв
		{ 
			servo1.write(180); 
			servo3.write(0); 
			degrees = (int)((distance-300)/1.67); 
			servo2.write(degrees); 
			Serial.println(degrees); 
			delay(1000); 
		} 
		else Если расстояние больше 600 крутим третий серв
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