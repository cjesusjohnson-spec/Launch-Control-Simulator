#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int ledPin1 = A5;
int ledPin2 = A4;
int ledPin3 = A3;
int ledPin4 = A2;
int ledPin5 = A1;
int buttonBrake = 2;
int buttonThrottle = 3;
int buttonStart = 4;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(buttonBrake, INPUT_PULLUP);
  pinMode(buttonThrottle, INPUT_PULLUP);
  pinMode(buttonStart, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("IDLE");
}

void loop() {

int startState = digitalRead(buttonStart);
int brakeState = digitalRead(buttonBrake);
int throttleState = digitalRead(buttonThrottle);

  digitalWrite(ledPin1, HIGH);

if (startState == LOW) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PRECONDITIONING");
  
    digitalWrite(ledPin2, HIGH);
    delay(1050);
    digitalWrite(ledPin2, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PEAK PERFORMANCE");
    digitalWrite(ledPin3, HIGH);
    delay(1050);
    digitalWrite(ledPin3, LOW);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CHEETAH STANCE");

    digitalWrite(ledPin4, HIGH);
    delay(1050);
    digitalWrite(ledPin4, LOW);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("READY FOR LAUNCH");
for (int i = 0; i < 5; i ++) {
    digitalWrite(ledPin5, HIGH);
    delay(100);
    digitalWrite(ledPin5, LOW);
    delay(100);
    digitalWrite(ledPin5, HIGH);
    delay(100);
    digitalWrite(ledPin5, LOW);
    delay(100);
     digitalWrite(ledPin5, HIGH);
    delay(100);
    digitalWrite(ledPin5, LOW);
    delay(100);
}
}
 if (brakeState == LOW && throttleState == LOW) {
    
    digitalWrite(ledPin5, HIGH);
    delay(10);
    digitalWrite(ledPin3, HIGH);
    delay(10);
    digitalWrite(ledPin3, LOW);

      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LAUNCHING");
 
 }

if (brakeState == HIGH && throttleState == LOW) {
      lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LAUNCHED");

for (int i = 0; i < 5; i ++) {
    digitalWrite(ledPin5, HIGH);
    delay(100);
    digitalWrite(ledPin5, LOW);
    delay(100);
    digitalWrite(ledPin5, HIGH);
    delay(100);
    digitalWrite(ledPin5, LOW);
    delay(100);
     digitalWrite(ledPin5, HIGH);
    delay(100);
    digitalWrite(ledPin5, LOW);
    delay(100);
  

  digitalWrite(ledPin5, LOW);
}
}
}



