
int echoPin = 9; 
int trigPin = 8; 

int servoPin1 = 13;
int servoPin2 = 12;
int servoPin3 = 11;

int distance = 0; 
int pulse=0;
int mediumDistance =0;
int count=0;
void setup() 
{ 
	pinMode(trigPin, OUTPUT); 
	pinMode(echoPin, INPUT); 
	Serial.begin(9600); 
	pinMode(servoPin1, OUTPUT);
	pinMode(servoPin2, OUTPUT);
	pinMode(servoPin3, OUTPUT);
} 

void distans() 
{ 
	float dist; 
	digitalWrite(trigPin, LOW); 
	delayMicroseconds(2); 
	digitalWrite(trigPin, HIGH); 
	delayMicroseconds(10); 
	digitalWrite(trigPin, LOW); 
	dist = pulseIn(echoPin, HIGH, 2941); // 2941 микросекунд = 1000мм, индивидуально для каждого дальномера
	distance = (int)dist / 5.82;
	Serial.print(distance); 
	Serial.println(" mm"); 
} 
void loop() 
{ 
	count++; // Количество вызовов метода поиска дистанции
	distans(); //выход от 0 до 1000 мм
	mediumDistance = (mediumDistance*(count-1) + distance)/count; // Среденее значение среди всех дистанций
	if(mediumDistance<333)
	{ 
		digitalWrite(servoPin2,HIGH);
  		delayMicroseconds(544); // 544мкс-0°,2400мкс-180°,1475мкс-90°,1°= 10мкс, 1мм = 5,6мкс, индивидуально для каждого сервопривода
  		digitalWrite(servoPin2,LOW);
  		delay(20);
		digitalWrite(servoPin3,HIGH);
  		delayMicroseconds(544);
  		digitalWrite(servoPin3,LOW);
  		delay(20);
  		digitalWrite(servoPin1,HIGH);
  		delayMicroseconds(544+mediumDistance*5.6); // 0 градусов + дистанция*5.6
  		digitalWrite(servoPin1,LOW);
  		delay(20);
  		Serial.println((544+mediumDistance*5.6); 
	} 
	else if(mediumDistance<666) 
	{ 
		digitalWrite(servoPin1,HIGH);
  		delayMicroseconds(2400); 
  		digitalWrite(servoPin1,LOW);
  		delay(20);
		digitalWrite(servoPin3,HIGH);
  		delayMicroseconds(544);
  		digitalWrite(servoPin3,LOW);
  		delay(20);
  		digitalWrite(servoPin2,HIGH);
  		delayMicroseconds(544+(mediumDistance-333)*5.6);
  		digitalWrite(servoPin2,LOW);
  		delay(20);
  		Serial.println((544+(mediumDistance-333)*5.6); 
	} 
	else if(mediumDistance<1000) 
	{ 
		digitalWrite(servoPin1,HIGH);
  		delayMicroseconds(2400); 
  		digitalWrite(servoPin1,LOW);
  		delay(20);
		digitalWrite(servoPin2,HIGH);
  		delayMicroseconds(2400);
  		digitalWrite(servoPin2,LOW);
  		delay(20);
  		digitalWrite(servoPin3,HIGH);
  		delayMicroseconds(544+(mediumDistance-666)*5.6); 
  		digitalWrite(servoPin3,LOW);
  		delay(20);
  		Serial.println((544+(mediumDistance-666)*5.6); 
	} 
	delay(100); 
}
