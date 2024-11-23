#if 0

#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"
#include "Arial_black_16.h"
#define noOfRow_panel 1
#define noOfColumn_panel 3

DMD p10(noOfRow_panel, noOfColumn_panel);

char message[200];
char char_read;
byte pos_index = 0;
int i;
char welcome_screen[] = "WELCOME TO HAMZATRONICS TECHNOLOGIES";
// char welcome_screen[] = "WELCOME TO COMPUTER SCIENCE DEPARTMENT";

void p10scan() {
  p10.scanDisplayBySPI();
}

void setup() {
  Timer1.initialize(2000);
  Timer1.attachInterrupt(p10scan);
  p10.clearScreen(true);
  Serial.begin(115200);
  strcpy(message, welcome_screen);
  // strcpy(message, welcome_screen, sizeof(message) - 1); //gpt recommendation

}

void loop() {

  if (Serial.available()) {
    for (i = 0; i < 199; i++) {
      message[i] = '\0';
      Serial.print(message[i]);
    }
    pos_index = 0;
  }

  // CLEAR SCREEN IF NEW TEXT ARIVE
  while (Serial.available() > 0) {
    p10.clearScreen(true);
    if (pos_index < (199)) {
      char_read = Serial.read();
      message[pos_index] = char_read;
      pos_index++;
    }
  }

  p10.selectFont(Arial_Black_16);
  p10.drawMarquee(message, 200, (32 * noOfRow_panel) - 1, 0);
  long start = millis();
  long timer_start = start;
  boolean flag = false;
  while (!flag) {
    if ((timer_start + 30) < millis()) {
      flag = p10.stepMarquee(-1, 0);
      timer_start = millis();
    }
  }
}

#endif