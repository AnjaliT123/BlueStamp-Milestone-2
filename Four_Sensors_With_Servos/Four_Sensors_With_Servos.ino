#include <Servo.h>

//one pin for the IR emitters, and 4 pins for each detector
int IRemitter = 3;
int IRdetectorfr = 4;
int IRdetectorfl = 5;
int IRdetectorbr = 6;
int IRdetectorbl = 7;

//each distance reads 1 or 0, where 1 means the wave was detected, and 0 means the wave wasn't detected
int distancefr;
int distancefl;
int distancebr;
int distancebl;

Servo leftServo;
Servo rightServo;

void setup() {
  //for testing purposes, use the built in LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  pinMode(IRemitter, OUTPUT);
  digitalWrite(IRemitter, HIGH);
  
  pinMode(IRdetectorfr, INPUT);
  pinMode(IRdetectorfl, INPUT);
  pinMode(IRdetectorbr, INPUT);
  pinMode(IRdetectorbl, INPUT);
  
  Serial.begin(9600);

  rightServo.attach(9);   //attaches rightServo to 9 pin
  leftServo.attach(10);   //attaches leftServo to 10 pin
  rightServo.write(90);   //no movement on this servo
  leftServo.write(90);    //no movement
  
}

void loop() {
  distancefr = readIR(IRdetectorfr); //read from the detector 
  distancefl = readIR(IRdetectorfl);
  distancebr = readIR(IRdetectorbr); //read from the detector 
  distancebl = readIR(IRdetectorbl);
  

  //move servos if a surface was detected
  if(distancebl==LOW && distancebr==LOW && distancefl==LOW && distancefr==LOW){   //LOW
    digitalWrite(LED_BUILTIN, HIGH);
    leftServo.write(180);
    rightServo.write(0);
    
  }

  //stop the servos if no surface detected
  else{  
    digitalWrite(LED_BUILTIN, LOW);

    leftServo.write(90);
    rightServo.write(90);
    
  }

  delay(100);

}

int readIR(int IRdetector){
  tone(IRemitter, 38000, 8);
  delay(1);
  int ir = digitalRead(IRdetector); //0 means wave detected, 1 means not
  delay(1);
  return ir;
 
}
  


