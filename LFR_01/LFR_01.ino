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

pinMode(LINE_D1, INPUT);
pinMode(LINE_D2, INPUT);
pinMode(LINE_D3, INPUT);
pinMode(LINE_D4, INPUT);
pinMode(LINE_D5, INPUT);
}
void loop() {
 // Perform line following
 int D1 = digitalRead(LINE_D1);
 int D2 = digitalRead(LINE_D2);
 int D3 = digitalRead(LINE_D3);
 int D4 = digitalRead(LINE_D4);
 int D5 = digitalRead(LINE_D5);
 if (D1==0 && D2==0 && D3==1 && D4==0 && D5==0) {
   motorL.setSpeed(S4);   
   motorR.setSpeed(S4);    //robot move forward
 }
  else if (D1==0 && D2==1 && D3==1 && D4==0 && D5==0) {
   motorL.setSpeed(S3);   
   motorR.setSpeed(S4);    //robot move slightly left
 }
 else if (D1==0 && D2==1 && D3==0 && D4==0 && D5==0) {
   motorL.setSpeed(S2);   
   motorR.setSpeed(S4);    //robot move slightly left
 }
 else if (D1==1 && D2==1 && D3==0 && D4==0 && D5==0) {
   motorL.setSpeed(S1);   
   motorR.setSpeed(S4);    //robot slowing down, move more to left
 }
 else if (D1==1 && D2==0 && D3==0 && D4==0 && D5==0) {
   motorL.setSpeed(S0);   
   motorR.setSpeed(S4);     //robot slowing down, move more to left
 }
  else if (D1==0 && D2==0 && D3==1 && D4==1 && D5==0) {
   motorL.setSpeed(S4);   
   motorR.setSpeed(S3);     //robot move slightly right
 }
 else if (D1==0 && D2==0 && D3==0 && D4==1 && D5==0) {
   motorL.setSpeed(S4);   
   motorR.setSpeed(S2);    //robot move slightly right
 }
 else if (D1==0 && D2==0 && D3==0 && D4==1 && D5==1) {
   motorL.setSpeed(S4);   
   motorR.setSpeed(S1);    //robot slowing down, move more to right
 }
 else if (D1==0 && D2==0 && D3==0 && D4==0 && D5==1) {
   motorL.setSpeed(S4);   
   motorR.setSpeed(S0);     //robot slowing down, move more to right
 }
 else if (D1==1 && D2==0 && D3==1 && D4==0 && D5==0) {
   motorL.setSpeed(S0);   
   motorR.setSpeed(S4);     //Sharp Turn, move Left
 }
 else if (D1==0 && D2==0 && D3==1 && D4==0 && D5==1) {
   motorL.setSpeed(S4);   
   motorR.setSpeed(S0);     //Sharp Turn, move Right
 }
 else if (D1==1 && D2==1 && D3==1 && D4==0 && D5==0) {
   motorL.setSpeed(S0);   
   motorR.setSpeed(S4);     //Sharp Turn2, move Left
 }
 else if (D1==0 && D2==0 && D3==1 && D4==1 && D5==1) {
   motorL.setSpeed(S4);   
   motorR.setSpeed(S0);     //Sharp Turn2, move Right
 }
  else if (D1==1 && D2==1 && D3==1 && D4==1 && D5==1) {
   motorL.setSpeed(S4);   
   motorR.setSpeed(S4);     //Junction go Ahead      
 }
 
 else {
 }
}