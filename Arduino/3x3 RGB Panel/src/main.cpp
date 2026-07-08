#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 7

#define MODULE_ROWS 3
#define MODULE_COLS 3
#define LEDS_PER_MODULE 64

#define TOTAL_LEDS (MODULE_ROWS * MODULE_COLS * LEDS_PER_MODULE)

Adafruit_NeoPixel panel(TOTAL_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
    panel.begin();
    panel.clear();
    panel.show();
}

void loop()
{
    // RED
    panel.fill(panel.Color(255, 0, 0));
    panel.show();
    delay(2000);

    // GREEN
    panel.fill(panel.Color(0, 255, 0));
    panel.show();
    delay(2000);

    // BLUE
    panel.fill(panel.Color(0, 0, 255));
    panel.show();
    delay(2000);

    // WHITE
    panel.fill(panel.Color(255, 255, 255));
    panel.show();
    delay(2000);

    // OFF
    panel.clear();
    panel.show();
    delay(1000);
}