#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include <Arduino.h>

#define CC_SEGMENT 0
#define CA_SEGMENT 1

class seven_segment
{
private:
    /* data */
public:
    uint8_t number[10] =
        {
            0x03,
            0x9F,
            0x25,
            0x0D,
            0x99,
            0x49,
            0x41,
            0x1F,
            0x01,
            0x09};
    seven_segment(/* args */);
    ~seven_segment();
    // deklarasi fungsi
    void begin(uint8_t tipe);
    void count_up(uint8_t tipe);
    void count_down(uint8_t tipe);
};

seven_segment::seven_segment(/* args */)
{
}

seven_segment::~seven_segment()
{
}
// implementasi
void seven_segment::begin(uint8_t tipe)
{
    // atur semua port D sbgai output
    DDRD = 0xFF;
    //matikan segment
    if (tipe == CC_SEGMENT)
    {
        PORTD = ~(0xFF);
    }

    if (tipe == CA_SEGMENT)
    {
        PORTD = (0xFF);
    }
}

void seven_segment::count_up(uint8_t tipe)
{
    // count up
    for (int i = 0; i < 10; i++)
    {
        if (tipe == CA_SEGMENT)
        {
            PORTD = (number[i]);
        }
        if (tipe == CC_SEGMENT)
        {
            PORTD = ~(number[i]);
        }
        delay(200);
    }
}
void seven_segment::count_down(uint8_t tipe)
{
    // count up
    for (int i = 0; i < 10; i++)
    {
        if (tipe == CA_SEGMENT)
        {
            PORTD = (number[9-i]);
        }
        if (tipe == CC_SEGMENT)
        {
            PORTD = ~(number[9-i]);
        }
        delay(200);
    }
}

#endif