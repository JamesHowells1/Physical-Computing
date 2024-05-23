#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

// Create an instance of the Adafruit_SH1106 library for I2C communication
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// String to hold the message
String lockString = "Locked";

// Function to update the display with the current lockString
void updateDisplay() {
  // Clear the display buffer
  display.clearDisplay();
  
  // Set text properties
  display.setTextSize(2.5); // Set text size to 2.5
  display.setTextColor(SH110X_WHITE); // Draw white text
  
  // Calculate text width and height for centering
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(lockString.c_str(), 0, 0, &x1, &y1, &w, &h);
  
  // Calculate position to start the text to be centered
  int16_t x = (SCREEN_WIDTH - w) / 2;
  int16_t y = (SCREEN_HEIGHT - h) / 2;
  
  // Set cursor to calculated position and print the text
  display.setCursor(x, y);
  display.print(lockString);
  
  // Send the buffer content to the display
  display.display();
}

void setup() {
  // Initialize the display
  if (!display.begin(0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SH1106 allocation failed"));
    for(;;);
  }
  display.display(); // Show the display buffer on the screen
  delay(2000); // Pause for 2 seconds

  // Update the display with the initial message
  updateDisplay();
}

void loop() {
  // Example: Change the message after 5 seconds
  delay(5000);
  lockString = "Unlocked";
  updateDisplay();
  
  // Change the message back after another 5 seconds
  delay(5000);
  lockString = "Locked";
  updateDisplay();
}
