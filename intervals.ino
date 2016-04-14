
int echoPin = 9; 
int trigPin = 8; 

int servoPin1 = 13;
int servoPin2 = 12;
int servoPin3 = 11;

double distance = 0; 
double mediumDistance =0; // Средняя дистанция
double distance1 =0; // Стандарное положение для первого серва
double distance2 =333; // Стандарное положение для второго серва
double distance3 =666; // Стандарное положение для третьего серва
int firstangle = 900;  // Нужно установить при каком значении серво будет в 0°
unsigned int count=0;  
double current=0;
double increment=10; // Шаг 
void setup() 
{ 
	pinMode(trigPin, OUTPUT); 
	pinMode(echoPin, INPUT); 
	Serial.begin(9600); 
	pinMode(servoPin1, OUTPUT);
	pinMode(servoPin2, OUTPUT);
	pinMode(servoPin3, OUTPUT);
	pulse(servoPin1, 0, -257); // все сервы в начальное положение
  	pulse(servoPin2, 0, -257);
  	pulse(servoPin3, 0, -257);
} 

void distans()  // Поиск расстояния
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
void pulse(int servoPin, double distance,double olddistance) // Метод установки положения серва
{
	olddistance = (double)olddistance*3.5 + firstangle;
	distance = (double)distance*3.5 +firstangle;
	if(distance>olddistance)
	{
		for(current = olddistance; current <distance; current+=increment)
		{
		     digitalWrite(servoPin, HIGH);
		     delayMicroseconds(current);
		     digitalWrite(servoPin, LOW);
		     delayMicroseconds(25000 - current); 
		}
	}
	else
	{
		for(current = olddistance; current >distance; current-=increment)
		{
		     digitalWrite(servoPin, HIGH);
		     delayMicroseconds(current);
		     digitalWrite(servoPin, LOW);
		     delayMicroseconds(25000 - current);
		}
	}
}
void loop() 
{ 
	//count++; // Количество вызовов метода поиска дистанции
	distans();
	//mediumDistance = (mediumDistance*(count-1) + distance)/count; // Среденее значение среди всех дистанций
	mediumDistance =distance;
	if(mediumDistance<333)
	{
		pulse(servoPin2, 0, distance2-333);
     	distance2=333;
		pulse(servoPin3, 0, distance3-666);
      	distance3=666;
		pulse(servoPin1, distance, distance1);
      	distance1 = mediumDistance;
	} 
	else if(mediumDistance<666) 
	{ 
		pulse(servoPin1, 333, distance1);
      	distance1=333;
		pulse(servoPin3, 0, distance3-666);
      	distance3=666;
		pulse(servoPin2, distance-333, distance2-333);
      	distance2 = mediumDistance;
	} 
	else if(mediumDistance<1000) 
	{ 
		pulse(servoPin1, 333, distance1);
      	distance1=333;
		pulse(servoPin2, 333, distance2-333);
      	distance2=666;
		pulse(servoPin3, distance-666, distance3-666);
      	distance3 = mediumDistance;
	} 
	delay(100); 
}
