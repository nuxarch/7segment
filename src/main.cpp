#include <Arduino.h>

uint8_t number[10]={
0x03,
0x9F,
0x25,
0x0D,
0x99,
0x49,
0x41,
0x1F,
0x01,
0x09
};

void setup() {
  // atur semua port D sbgai output
  DDRD = 0xFF;
  //matikan segment
  PORTD = 0xFF;

}

void loop() {
  // count up
  for (int i = 0; i < 10; i++)
  {
    PORTD = number[i];delay(200);
  }
  
}