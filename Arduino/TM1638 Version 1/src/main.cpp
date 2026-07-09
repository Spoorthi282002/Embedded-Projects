#include <Arduino.h>
#include <TM1638plus.h>

#define STB 8
#define CLK 9
#define DIO 10

TM1638plus tm(STB, CLK, DIO, true);

int counter = 0;
uint8_t lastButtons = 0;

void displayCounter()
{
    char buffer[9];
    sprintf(buffer, "%03d", counter);   // Display 000,001,002...
    tm.displayText(buffer);
}

void setup()
{
    tm.displayBegin();
    tm.reset();

    displayCounter();
}

void loop()
{
    uint8_t buttons = tm.readButtons();

    // Detect new button press
    if (buttons != 0 && buttons != lastButtons)
    {
        // S1 -> +1
        if (buttons & 0x01)
        {
            counter++;
        }

        // S2 -> +2
        if (buttons & 0x02)
        {
            counter += 2;
        }

        // S3 -> -1
        if (buttons & 0x04)
        {
            if (counter > 0)
                counter--;
        }

        // S4 -> -2
        if (buttons & 0x08)
        {
            if (counter >= 2)
                counter -= 2;
            else
                counter = 0;
        }

        displayCounter();

        delay(200);      // Simple debounce
    }

    lastButtons = buttons;
}