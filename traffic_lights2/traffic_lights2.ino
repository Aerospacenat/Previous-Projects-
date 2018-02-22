// Owner Nathaniel David Robinson 
// GitHub Aerospacenat

int red = 12; // lights being assigned
int yellow = 11;
int green = 10;
int pgreen = 8; // pedestrion light 
int pred = 9;
int crossTime = 4000;  //
int lightsTime;
int changeTime;
int five;
int buzz = 7;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup(){
 pinMode(red, OUTPUT);
 pinMode(yellow, OUTPUT);
 pinMode(green, OUTPUT);
 pinMode(pgreen, OUTPUT);
 pinMode(pred, OUTPUT);
 pinMode(buzz, OUTPUT);
 pinMode(interruptPin, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(interruptPin),myInter , CHANGE); // interrupt 
lights();

}

void myInter(){
  state = HIGH;
}

void loop(){
  
  
 if(state==HIGH) {
   changeLights();  //function to change lights
   state = LOW;
   
   }
 else {
  lights(); // if button hasn't been pressed then it will carry on to a normal sequence.
 }
   }

    

  void lights(){
    
   digitalWrite(green,HIGH);  //green car light on
 digitalWrite(pred,HIGH); // pedrestian red light on 
 delay(2500);
 
 digitalWrite(green,LOW);  //green  light off
 digitalWrite(yellow,HIGH); //yellow  light on
 delay(1000);
 
 digitalWrite(yellow,LOW); //yellow  light off
 digitalWrite(red,HIGH); // red light on
 delay(3000); //wait 3 seconds
 
  digitalWrite(yellow,HIGH); //yellow light on
  delay(1000);
  
  digitalWrite(green,HIGH); // green light on
  digitalWrite(red,LOW); // red light off
  digitalWrite(yellow,LOW); // yellow light is off 
  changeTime = millis();
  
  }
 
void changeLights() {
  digitalWrite(green,HIGH); //green light on
  delay(2000);
  digitalWrite(green,LOW);  //green  light off
  digitalWrite(yellow,HIGH); //yellow  light on
  delay(1000);
  
  digitalWrite(yellow,LOW); //yellow  light off
  digitalWrite(red,HIGH); // red light on
  delay(1000); //allows time for cars to stop
  digitalWrite(pred,LOW);
  digitalWrite(pgreen,HIGH); // turns pedestrian light green on
  delay(crossTime); //wait 4 seconds

  for (int x=0; x<13; x++) { // flashes pedestrain green light 9 times to show the its about to turn red
    digitalWrite(pgreen, HIGH);
    digitalWrite(buzz, HIGH); 
    delay(150);
    digitalWrite(pgreen, LOW);
    digitalWrite(buzz, LOW);
    delay(150);
      }

  digitalWrite(pred,HIGH);
  digitalWrite(pgreen,LOW); // turns the green off and the red on.
  delay(250);
  digitalWrite(yellow,HIGH); // yellow light on
  delay(1000);
  digitalWrite(green,HIGH); //green light on
  digitalWrite(red,LOW); // red light off
  digitalWrite(yellow,LOW); //yellow off 
 
  
    
}

