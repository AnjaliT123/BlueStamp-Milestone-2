#include <Servo.h>

int IRdetectorfl = 6;

int IRemitter = 3;
int IRdetectorfr = 7;
int distancefr;
int distancefl;
//Servo servo;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  pinMode(IRdetectorfr, INPUT);
  pinMode(IRemitter, OUTPUT);
  digitalWrite(IRemitter, HIGH);
  
  pinMode(IRdetectorfl, INPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  distancefr = readIR(IRdetectorfr);
  distancefl = readIR(IRdetectorfl);
  Serial.print(distancefl);
  Serial.print("\t");
  Serial.println(distancefr);
  
  if(distancefr==LOW && distancefl==LOW) digitalWrite(LED_BUILTIN, HIGH);
  else digitalWrite(LED_BUILTIN, LOW);
  
  delay(100);
  
}


int readIR(int IRdetector){
  tone(IRemitter, 38000, 8);
  delay(1);
  int ir = digitalRead(IRdetector);
  delay(1);
  return ir;
 
}




 
