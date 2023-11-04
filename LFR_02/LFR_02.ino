#include "CytronMotorDriver.h" //Include "Cytron Motor Library"
// Maker Line Sensor Pin Connection
#define LINE_D1   4
#define LINE_D2   5
#define LINE_D3   6
#define LINE_D4   7
#define LINE_D5   12

#define S0 0
#define S1 75
#define S2 150
#define S3 200
#define S4 255

// Configure the motor driver.
CytronMD motorL(PWM_PWM, 11, 10);   // motor 1 = Left motor, M1A = Pin 3, M1B = Pin 9.
CytronMD motorR(PWM_PWM, 3, 9); // motor 2= right motor, M2A = Pin 10, M2B = Pin 11.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LINE_D1, INPUT);
  pinMode(LINE_D2, INPUT);
  pinMode(LINE_D3, INPUT);
  pinMode(LINE_D4, INPUT);
  pinMode(LINE_D5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int D1 = digitalRead(LINE_D1);
  int D2 = digitalRead(LINE_D2);
  int D3 = digitalRead(LINE_D3);
  int D4 = digitalRead(LINE_D4);
  int D5 = digitalRead(LINE_D5);
  int arr[5] = {D1, D2, D3, D4, D5};
  
  // Convert the binary array to a decimal number
  int decimalNumber = 0;
  for (int i = 0; i < 5; i++) {
    decimalNumber = (decimalNumber << 1) | arr[i];
  }
  
  // Serial.print("Binary Array: ");
  // for (int i = 0; i < 5; i++) {
  //   Serial.print(arr[i]);
  // }
  // Serial.print(" -> Decimal Number: ");
  // Serial.println(decimalNumber);
  // delay(500);

if (decimalNumber==1) {
    motorL.setSpeed(S4);   
   motorR.setSpeed(0); 
}
 else if (decimalNumber==2) {
    motorL.setSpeed(S4);   
   motorR.setSpeed(S2);
}
  else if (decimalNumber==3) {
    motorL.setSpeed(S4);   
   motorR.setSpeed(S1); 
}
 else if (decimalNumber==4) {
    motorL.setSpeed(S4);   
   motorR.setSpeed(S4);
}
 else if (decimalNumber==5) {
    motorL.setSpeed(S4);   
   motorR.setSpeed(0);
}
 else if (decimalNumber==6) {
    motorL.setSpeed(S4);   
   motorR.setSpeed(S2);
}
 else if (decimalNumber==7) {
    motorL.setSpeed(S4);   
   motorR.setSpeed(0);
}
 else if (decimalNumber==8) {
    motorL.setSpeed(S2);   
   motorR.setSpeed(S4);
}
 else if (decimalNumber==12) {
    motorL.setSpeed(S4);   
   motorR.setSpeed(S2);
}
 else if (decimalNumber==15) {
    motorL.setSpeed(S4);   
   motorR.setSpeed(0);
}
 else if (decimalNumber==16) {
    motorL.setSpeed(0);   
   motorR.setSpeed(S4);
}
 else if (decimalNumber==21) {
    motorL.setSpeed(0);   
   motorR.setSpeed(S4);
}
 else if (decimalNumber==24) {
    motorL.setSpeed(S1);   
   motorR.setSpeed(S4);
}
 else if (decimalNumber==28) {
    motorL.setSpeed(0);   
   motorR.setSpeed(S4);
}
 else if (decimalNumber==30) {
    motorL.setSpeed(0);   
   motorR.setSpeed(S4);
}
 else if (decimalNumber==31) {
    motorL.setSpeed(S4);   
   motorR.setSpeed(S4);
}
}