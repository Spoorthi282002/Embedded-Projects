#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN     7
#define RELAY_PIN   8

#define TOTAL_LEDS 384

Adafruit_NeoPixel panel(TOTAL_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
    pinMode(RELAY_PIN, OUTPUT);

    digitalWrite(RELAY_PIN, LOW);

    panel.begin();
    panel.clear();
    panel.show();
}

void loop()
{
    // RED
    digitalWrite(RELAY_PIN, HIGH);
    delay(200);

    panel.fill(panel.Color(255, 0, 0));
    panel.show();
    delay(2000);

    panel.clear();
    panel.show();
    digitalWrite(RELAY_PIN, LOW);
    delay(1000);

    // GREEN
    digitalWrite(RELAY_PIN, HIGH);
    delay(200);

    panel.fill(panel.Color(0, 255, 0));
    panel.show();
    delay(2000);

    panel.clear();
    panel.show();
    digitalWrite(RELAY_PIN, LOW);
    delay(1000);

    // BLUE
    digitalWrite(RELAY_PIN, HIGH);
    delay(200);

    panel.fill(panel.Color(0, 0, 255));
    panel.show();
    delay(2000);

    panel.clear();
    panel.show();
    digitalWrite(RELAY_PIN, LOW);
    delay(1000);

    // WHITE
    digitalWrite(RELAY_PIN, HIGH);
    delay(200);

    panel.fill(panel.Color(255, 255, 255));
    panel.show();
    delay(2000);

    panel.clear();
    panel.show();
    digitalWrite(RELAY_PIN, LOW);
    delay(1000);
}