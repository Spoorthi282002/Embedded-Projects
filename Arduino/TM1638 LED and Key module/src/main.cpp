#include <Arduino.h>
#include <TM1638plus.h>

#define STB 8
#define CLK 9
#define DIO 10

TM1638plus tm(STB, CLK, DIO, true);

void setup()
{
    Serial.begin(9600);

    tm.displayBegin();
    tm.reset();

    Serial.println("TM1638 Test Started");
}

void loop()
{
    // -----------------------------
    // 1. Display 12345678
    // -----------------------------
    tm.displayText("12345678");
    delay(2000);

    // -----------------------------
    // 2. LED Running Effect
    // -----------------------------
    for (int i = 0; i < 8; i++)
    {
        tm.setLED(i, 1);
        delay(250);
        tm.setLED(i, 0);
    }

    // -----------------------------
    // 3. Blink All LEDs
    // -----------------------------
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 8; i++)
            tm.setLED(i, 1);

        delay(300);

        for (int i = 0; i < 8; i++)
            tm.setLED(i, 0);

        delay(300);
    }

    // -----------------------------
    // 4. Button Test
    // Press any button
    // -----------------------------
    tm.displayText("PRESS");

    while (true)
    {
        uint8_t buttons = tm.readButtons();

        if (buttons)
        {
            for (int i = 0; i < 8; i++)
            {
                if (buttons & (1 << i))
                {
                    Serial.print("Button ");
                    Serial.print(i + 1);
                    Serial.println(" Pressed");

                    // Display button number
                    tm.displayIntNum(i + 1);

                    // Turn ON corresponding LED
                    tm.setLED(i, 1);

                    delay(500);

                    tm.setLED(i, 0);
                    tm.displayText("PRESS");
                }
            }
        }
    }
}