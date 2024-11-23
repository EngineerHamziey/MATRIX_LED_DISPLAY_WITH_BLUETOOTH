#if 0

#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"

// Define the number of panels
#define noOfRow_panel 1
#define noOfColumn_panel 3

// Initialize the DMD object
DMD p10(noOfRow_panel, noOfColumn_panel);

// Function to scan the display
void p10scan() {
  p10.scanDisplayBySPI();
}

// Function to print a string on the panels
void printOnPanels(String inputString) {
  char message[200];
  inputString.toCharArray(message, 200); // Convert String to char array
  p10.clearScreen(true); // Clear the screen
  p10.selectFont(Arial_Black_16); // Set font
  p10.drawMarquee(message, strlen(message), (32 * noOfColumn_panel) - 1, 0); // Draw marquee

  long timer_start = millis();
  boolean flag = false;
  while (!flag) {
    if ((timer_start + 30) < millis()) {
      flag = p10.stepMarquee(-1, 0); // Scroll the marquee
      timer_start = millis();
    }
  }
}

void setup() {
  // Initialize timer and DMD
  Timer1.initialize(2000);
  Timer1.attachInterrupt(p10scan);
  p10.clearScreen(true);
  Serial.begin(115200); // For debugging or additional input
}

void loop() {
  String inputString = "WELCOME TO HAMZATRONICS TECHNOLOGIES"; // Your input string
  printOnPanels(inputString); // Print the input string
  delay(5000); // Wait for 5 seconds before repeating
}


#endif