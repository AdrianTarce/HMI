#include "Nextion.h"

const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
NexText tState = NexText(0, 4, "tState"); 
NexButton bOn = NexButton(0, 2, "bOn");
NexButton bOff = NexButton(0, 3, "bOff");
NexButton bSlow = NexButton(0, 6, "bSlow");
NexButton bFast = NexButton(0, 7, "bFast");
NexSlider h0 = NexSlider(0, 5, "h0");
NexText tSlider = NexText(0, 6, "tSlider");

NexTouch *nex_listen_list[] = {
 &bOn,
 &bOff,
 &bFast,
 &bSlow,
 &h0,
 NULL
};

void bOnPopCallback(void *ptr) {
 tState.setText("State: on");
 digitalWrite(led1, HIGH);
}

void bOffPopCallback(void *ptr) {
 tState.setText("State: off");
 digitalWrite(led1, LOW);
}

void bSlowPopCallback(void *ptr) {
  // Aprinde LED-ul led2
  digitalWrite(led2, LOW);
  delay(500);
  digitalWrite(led2, HIGH);

  // Verifică starea butonului până când este eliberat
  while (digitalRead(led2) == LOW) {
    delay(10);
  }
}

void bFastPopCallback(void *ptr) {
  // Aprinde LED-ul led3
  digitalWrite(led3, LOW);
  delay(500);
  digitalWrite(led3, HIGH);
  // Verifică starea butonului până când este eliberat
  while (digitalRead(led3) == LOW) {
    delay(10);
  }
}



void setup(void) {
  nexInit();
  bOn.attachPop(bOnPopCallback, &bOn);
  bOff.attachPop(bOffPopCallback, &bOff);
  bSlow.attachPop(bSlowPopCallback, &bSlow);
  bFast.attachPop(bFastPopCallback, &bFast);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Aprinde LED-urile led2 și led3
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
}

void loop(void) { 
  // Check the state of the buttons and toggle the LEDs accordingly
 
  nexLoop(nex_listen_list);
}
