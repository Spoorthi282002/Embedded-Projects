#include <Arduino.h>
#include <TM1638plus.h>

#define STB 8
#define CLK 9
#define DIO 10

TM1638plus tm(STB, CLK, DIO, true);

int leftCounter = 0;
int rightCounter = 0;

uint8_t lastButtons = 0;

void updateDisplay()
{
    char left[4];
    char right[4];

    sprintf(left, "%03d", leftCounter);
    sprintf(right, "%03d", rightCounter);

    // Left Counter (Digits 0-2)
    tm.displayASCII(0, left[0], CommonData::DecPointOff);
    tm.displayASCII(1, left[1], CommonData::DecPointOff);
    tm.displayASCII(2, left[2], CommonData::DecPointOff);

    tm.display7Seg(3, 0x00);
    tm.display7Seg(4, 0x00);

    tm.displayASCII(5, right[0], CommonData::DecPointOff);
    tm.displayASCII(6, right[1], CommonData::DecPointOff);
    tm.displayASCII(7, right[2], CommonData::DecPointOff);
}

void setup()
{
    tm.displayBegin();
    tm.reset();
    updateDisplay();
}

void loop()
{
    uint8_t buttons = tm.readButtons();

    if (buttons != 0 && buttons != lastButtons)
    {
        // Left Counter
        if (buttons & 0x01)
        {
            if (leftCounter < 999)
                leftCounter++;
        }

        if (buttons & 0x02)
        {
            leftCounter += 2;
            if (leftCounter > 999)
                leftCounter = 999;
        }

        if (buttons & 0x04)
        {
            if (leftCounter > 0)
                leftCounter--;
        }

        if (buttons & 0x08)
        {
            if (leftCounter >= 2)
                leftCounter -= 2;
            else
                leftCounter = 0;
        }

        // Right Counter
        if (buttons & 0x10)
        {
            if (rightCounter < 999)
                rightCounter++;
        }

        if (buttons & 0x20)
        {
            rightCounter += 2;
            if (rightCounter > 999)
                rightCounter = 999;
        }

        if (buttons & 0x40)
        {
            if (rightCounter > 0)
                rightCounter--;
        }

        if (buttons & 0x80)
        {
            if (rightCounter >= 2)
                rightCounter -= 2;
            else
                rightCounter = 0;
        }

        updateDisplay();

        delay(200); // Debounce
    }

    lastButtons = buttons;
}