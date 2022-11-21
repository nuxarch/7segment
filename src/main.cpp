#include <Arduino.h>
#include "seven_segment.h"
seven_segment mysegmen;
seven_segment mysegmen2;
#define PIN_D1 13
#define PIN_D0 12

int data = 15;

// number 00 sd 99 ex 19
void update(uint8_t number){
 // step 1  
  number = number /10;
  digitalWrite(PIN_D1, HIGH); // D1 on
  PORTD = mysegmen.number[number];
  delay(10);
  digitalWrite(PIN_D1, LOW); // D1 off

  digitalWrite(PIN_D0, HIGH); // D0 on
  PORTD = mysegmen.number[9];
  delay(10);
  digitalWrite(PIN_D0, LOW); // D0 off
}

void setup()
{
  mysegmen.begin(CC_SEGMENT);
  mysegmen2.begin(CA_SEGMENT);
  pinMode(PIN_D1, OUTPUT);
  pinMode(PIN_D0, OUTPUT);
}
void loop()
{
  update(45);
}