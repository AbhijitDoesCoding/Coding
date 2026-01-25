#include <Wire.h> // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h> // Include the LiquidCrystal_I2C library for 16x2 LED matrix display
// Define sensor pin numbers
const int sensorPin = 2; // Assuming the sensor is connected to digital pin 2
// Define indication pin numbers
const int indicationPin = 3; // Assuming the indication (buzzer, LED, etc.) is connected to digital pin 3
// Define I2C address and LCD size
const int lcdColumns = 16;
const int lcdRows = 2;
const int lcdAddress = 0x27; // I2C address of the LCD module
// Initialize the LCD object
LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);
// Variable to count bottles
int bottleCount = 0;
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  // Set sensor pin as input
  pinMode(sensorPin, INPUT);
  // Set indication pin as output
  pinMode(indicationPin, OUTPUT);
  // Initialize LCD display
  lcd.init();
  lcd.backlight(); // Turn on backlight
  lcd.clear(); // Clear the display
}
void loop() {
  // Read sensor value
  int sensorValue = digitalRead(sensorPin);
  // If bottle is detected
  if (sensorValue == HIGH) {
    // Increment bottle count
    bottleCount++;
    // Print bottle count to LCD display
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Bottle count:");
    lcd.setCursor(0, 1);
    lcd.print(bottleCount);
    // If 6 bottles are detected, trigger indication and reset counter
    if (bottleCount == 6) {
      digitalWrite(indicationPin, HIGH); // Activate indication
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Carton Full"); // Display message on LCD
      delay(1000); // Indication duration
      digitalWrite(indicationPin, LOW); // Deactivate indication
      bottleCount = 0; // Reset bottle count for the next carton
    }
  }
  // Add a delay to avoid reading the sensor too quickly
  delay(100);
}