int led1 = 13; 
int led2 = 12; 
int led3 = 11; 
int led4 = 10; 
int led5 = 9; 
unsigned long interval1 = 200000; 
unsigned long interval2 = 250000; 
unsigned long interval3 = 333; 
unsigned long interval4 = 500; 
unsigned long interval5 = 1000; 
int state1 = LOW; 
int state2 = LOW; 
int state3 = LOW; 
int state4 = LOW; 
int state5 = LOW; 
unsigned long previousMicros1 = 0; 
unsigned long previousMicros2 = 0; 
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
    Serial.begin(9600); 
} 

void function(unsigned long time, int led, unsigned long interval,unsigned long &previous, int &state) 
{ 
    if(time - previous > interval) 
    { 
        state = !state; 
        previous = time; 
        digitalWrite(led, state); 
    } 
} 

void loop() 
{ 
    unsigned long timeMillis = millis(); 
    unsigned long timeMicros = micros(); 
    function(timeMicros,led1,interval1, previousMicros1,state1); 
    function(timeMicros,led2,interval2, previousMicros2,state2); 
    function(timeMillis,led3,interval3, previousMillis3,state3); 
    function(timeMillis,led4,interval4, previousMillis4,state4); 
    function(timeMillis,led5,interval5, previousMillis5,state5); 
    if(Serial.available() > 0) 
    { 
        String split = Serial.readString(); 
        Serial.println("led = " + split.substring(0, 1)+" interval = " + split.substring(2, split.length())); 
        switch(split.substring(0, 1).toInt()) 
        { 
            case 1: 
            interval1=split.substring(2, split.length()).toInt(); 
            break; 
            case 2: 
            interval2=split.substring(2, split.length()).toInt(); 
            break; 
            case 3: 
            interval3=split.substring(2, split.length()).toInt(); 
            break; 
            case 4: 
            interval4=split.substring(2, split.length()).toInt(); 
            break; 
            case 5: 
            interval5=split.substring(2, split.length()).toInt(); 
            break; 
        } 
    } 
}