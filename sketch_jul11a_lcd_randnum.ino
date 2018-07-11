#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // (RS, E, DB4, DB5, DB6, DB7)

int randnum1, randnum2;

//My Functions
void printRandNum (int number, int pointer) {

  digitalWrite(LED_BUILTIN, HIGH);
  delay(750);
  digitalWrite(LED_BUILTIN, LOW);
  delay(750);
  
  lcd.setCursor(0, pointer);
  lcd.print("Random num: ");
  lcd.print(number);
  
};

void lcdText (String firstLine, String secondLine){

  delay(750);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(firstLine);
  lcd.setCursor(0, 1);
  lcd.print(secondLine);
  delay(750);
  lcd.clear();
  delay(750);

};
//Just for testing

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("Initialization successful");

  pinMode(LED_BUILTIN, OUTPUT);

  randomSeed(analogRead(0));

  lcd.begin(16, 2);
  lcd.blink();

}

void loop() {
  // put your main code here, to run repeatedly:

  lcdText("*RANDOM**NUMBER*", "***GENERATOR***");
  
  randnum1 = random(-999, 999);
  printRandNum(randnum1, 0);

  randnum2 = random(-999, 999);
  printRandNum(randnum2, 1);

  lcdText("*****SCREEN*****", "*****CLEARED****");

}
