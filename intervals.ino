int led1 = 13; 
int led2 = 12; 
int led3 = 11; 
int led4 = 10; 
int led5 = 9; 
int interval1 = 1000; 
int interval2 = 500; 
int interval3 = 333; 
int interval4 = 250; 
int interval5 = 200; 
int state1 = LOW; 
int state2 = LOW; 
int state3 = LOW; 
int state4 = LOW; 
int state5 = LOW; 
unsigned long previousMillis1 = 0; 
unsigned long previousMillis2 = 0; 
unsigned long previousMillis3 = 0; 
unsigned long previousMillis4 = 0; 
unsigned long previousMillis5 = 0; 

void setup() 
{ 
	pinMode(led1, OUTPUT); 
	pinMode(led2, OUTPUT); 
	pinMode(led3, OUTPUT); 
	pinMode(led4, OUTPUT); 
	pinMode(led5, OUTPUT); 
} 

void function(unsigned long time, int led, int interval,unsigned long &previousMillis, int &state) 
	{ 
	if(time - previousMillis > interval) 
	{ 		
		previousMillis = time; 
		state = !state; 
		digitalWrite(led, state); 
	} 
}

void loop() 
{ 
	unsigned long time = millis(); 
	function(time,led1,interval1, previousMillis1,state1); 
	function(time,led2,interval2, previousMillis2,state2); 
	function(time,led3,interval3, previousMillis3,state3); 
	function(time,led4,interval4, previousMillis4,state4); 
	function(time,led5,interval5, previousMillis5,state5); 
}