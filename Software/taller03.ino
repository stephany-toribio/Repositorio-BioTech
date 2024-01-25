#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;

float temperature = 0;
float humidity = 0;

const int pirPin = A5;
bool motionDetected = false;
void setup()
{
    Serial.begin(9600);

    CARRIER_CASE = true;
    carrier.begin();
    pinMode(pirPin, INPUT);
}

void loop()
{
    temperature = carrier.Env.readTemperature();
    temperatureFh = carrier.Env.readTemperatureFh();
    temperatureKv = carrier.Env.readTemperatureKv();
    humidity = carrier.Env.readHumidity();

    motionDetected = digitalRead(pirPin) == HIGH;
    carrier.Buttons.update();

    if (carrier.Buttons.onTouchDown(TOUCH0))
    {
        printTemperature();
    }
    if (carrier.Buttons.onTouchDown(TOUCH1))
    {
        printHumidity();
    }
    if (carrier.Buttons.onTouchDown(TOUCH2))
    {
        printTemperatureFh();
        ;
    }
    if (carrier.Buttons.onTouchDown(TOUCH3))
    {
        printTemperatureKv();
    }

    if (motionDetected)
    {
        activateAlarm();
    }

    if (temperature > 30)
    {
        carrier.leds.setPixelColor(0, 255, 0, 0);
        carrier.leds.setPixelColor(1, 255, 0, 0);
        carrier.leds.setPixelColor(2, 255, 0, 0);
        carrier.leds.setPixelColor(3, 255, 0, 0);
        carrier.leds.setPixelColor(4, 255, 0, 0);
    }
    else
    {
        carrier.leds.setPixelColor(0, 0, 0, 255);
        carrier.leds.setPixelColor(1, 0, 0, 255);
        carrier.leds.setPixelColor(2, 0, 0, 255);
        carrier.leds.setPixelColor(3, 0, 0, 255);
        carrier.leds.setPixelColor(4, 0, 0, 255);
    }
    carrier.leds.show();
}

void printTemperature()
{

    carrier.display.fillScreen(ST77XX_RED);
    carrier.display.setTextColor(ST77XX_WHITE);
    carrier.display.setTextSize(6);

    carrier.display.setCursor(30, 55);
    carrier.display.print("Temp: ");
    carrier.display.setTextSize(4);
    carrier.display.setCursor(40, 120);
    carrier.display.print(temperature);
    carrier.display.print(" C");
}

void printTemperatureFh()
{
    temperatureFh = (9 / 5) * temperature + 32;
    carrier.display.fillScreen(ST77XX_RED);
    carrier.display.setTextColor(ST77XX_WHITE);
    carrier.display.setTextSize(6);

    carrier.display.setCursor(30, 50);
    carrier.display.print("Temp: ");
    carrier.display.setTextSize(4);
    carrier.display.setCursor(40, 120);
    carrier.display.print(temperatureFh);
    carrier.display.print(" °F");
}

void printTemperatureKv()
{
    temperatureKv = temperature + 273.15;
    carrier.display.fillScreen(ST77XX_RED);
    carrier.display.setTextColor(ST77XX_WHITE);
    carrier.display.setTextSize(6);

    carrier.display.setCursor(30, 50);
    carrier.display.print("Temp: ");
    carrier.display.setTextSize(4);
    carrier.display.setCursor(40, 120);
    carrier.display.print(temperatureKv);
    carrier.display.print(" °K");
}
void printHumidity()
{

    carrier.display.fillScreen(ST77XX_BLUE);
    carrier.display.setTextColor(ST77XX_WHITE);
    carrier.display.setTextSize(4);

    carrier.display.setCursor(20, 110);
    carrier.display.print("Humi: ");
    carrier.display.print(humidity);
    carrier.display.println(" %");
}

void activateAlarm()
{
    carrier.Buzzer.sound(500);
    delay(500);
    carrier.Buzzer.noSound();
    delay(500);
}
