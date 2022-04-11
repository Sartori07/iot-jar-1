#include <Arduino.h>
#include <LiquidCrystal.h>
// include the LCD library
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
// Set pins as 12,11,7,6,5,4. It might be different for your LCD, check the producer catalog
int potPin = A0; //input pin
int soil=0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
// lcd rows and columns
lcd.print("Humidity");
// title of sorts
}

void loop() {
  // map the values
int soil = analogRead(potPin) ;
soil = constrain(soil, 485, 1023);
soil = map(soil, 485, 1023, 100, 0);
lcd.setCursor(0, 1);
//display final numbers
lcd.print(soil);
//print the percent symbol at the end
lcd.print("%");
//wait 0.1 seconds
delay(75);
//wipe the extra characters
lcd.print(" ");
delay(1);
}