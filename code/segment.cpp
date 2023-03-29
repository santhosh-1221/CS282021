#include<Arduino.h>
int T1 = 2; 
int T2 = 3; 
int T3 = 4; 
int Q1 = 5; 
int Q2 = 6; 
int Q3 = 7; 
void setup() {
  pinMode(T1, OUTPUT); 
  pinMode(T2, OUTPUT); 
  pinMode(T3, OUTPUT); 
  pinMode(Q1, INPUT);  
  pinMode(Q2, INPUT); 
  pinMode(Q3, INPUT); 
  Serial.begin(9600);  
}
void loop() {
  digitalWrite(T1, digitalRead(Q3)); 
  digitalWrite(T2, digitalRead(!Q1)); 
  digitalWrite(T3, digitalRead(!Q2));
  delay(1); 
  digitalWrite(T1, LOW); 
  digitalWrite(T2, LOW); 
  digitalWrite(T3, LOW);
  int state1 = digitalRead(Q1);
  int state2 = digitalRead(Q2);
  int state3 = digitalRead(Q3);
  Serial.print(state3);
  Serial.print(state2);
  Serial.println(state1);
  if (state3 == 0 && state2 == 0 && state1 == 0) {
    delay(1000);
    Serial.println("011");
  }
  else if (state3 == 0 && state2 == 1 && state1 == 1) {
    delay(1000);
    Serial.println("101");
  }
  else if (state3 == 1 && state2 == 0 && state1 == 1) {
    delay(1000);
    Serial.println("000");
  }
}
