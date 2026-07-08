#include <Arduino.h>
#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    lcd.begin(16, 2);
    dht.begin();

    Serial.begin(9600);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DHT11 SENSOR");

    lcd.setCursor(0, 1);
    lcd.print("Initializing");

    delay(2000);
    lcd.clear();
}

void loop()
{
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity))
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sensor Error");

        Serial.println("DHT11 Read Failed");

        delay(2000);
        return;
    }

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.print(temperature, 1);
    lcd.print((char)223);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Hum :");
    lcd.print(humidity, 1);
    lcd.print("%");

    Serial.print("Temperature : ");
    Serial.print(temperature);
    Serial.print(" C    ");

    Serial.print("Humidity : ");
    Serial.print(humidity);
    Serial.println(" %");

    delay(2000);
}