#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd (0x27, 16, 2);
const int buttonPin = 14;     // the number of the pushbutton pin
const int ledPin =  0;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int firstoccupied = 0;
int firsttotalSpaces = 10;
char firstintersection[] = "Jane and Finch";


int seconoccupied = 5;
int secontotalSpaces = 10;
char seconintersection[] = "Queen & Gerard";

void setup() {
  Serial.begin(9600); 
  // initialize the LED pin as an output:

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  lcd.backlight();
lcd.begin();
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if(firstoccupied < firsttotalSpaces){
    firstoccupied++;}
    delay(150);
  } 
  if(firstoccupied < firsttotalSpaces)
  {
    lcd.setCursor(0, 0);
    lcd.print(firstoccupied);
    lcd.print("/");
    lcd.print(firsttotalSpaces);
    lcd.print(" spaces");
    lcd.setCursor(1, 4);
    lcd.print("occupied");
  }
  else if(firstoccupied == firsttotalSpaces)
  {
    //hghjj
    lcd.print("All the spaces");
    lcd.setCursor(1, 4);
    lcd.print("occupied");
    delay(3000);
    lcd.clear();
   // lcd.setCursor(0, 0);
    lcd.print(seconoccupied);
    lcd.print("/");
    lcd.print(secontotalSpaces);
    lcd.print(" occupied");
    lcd.setCursor(0, 1);
    lcd.print("@ ");
    lcd.print(seconintersection);
    delay(3000);
  }
  delay(500);
  lcd.clear();
}
