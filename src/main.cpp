#include <Arduino.h>

#include "Odometer.h"

Odometer odometer;

void setup()
{
    odometer.begin(
        21.0, // wheel diameter in cm
        GPIO_NUM_15, // hall sensor pin
        50, // debounce in ms
        4 // reports per revolution
    );
    Serial.begin(9600);
    pinMode(GPIO_NUM_2, OUTPUT);
    pinMode(GPIO_NUM_15, INPUT);
}

void loop()
{
    // write your code here
    odometer.tick();
    auto dist = odometer.getDistance();
    Serial.println(dist);
    if (dist > 100)
    {
        // Serial.print(dist / 100.0);
        // Serial.println(" m");
        digitalWrite(GPIO_NUM_2, HIGH);
    }
    else
    {
        // Serial.print(dist);
        // Serial.println(" cm");
        digitalWrite(GPIO_NUM_2, LOW);
    }
}
