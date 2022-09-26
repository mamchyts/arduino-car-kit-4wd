#include "Car.h"
#include "stdint.h"
#include "Wheel.h"
#include <Arduino.h>

void setup()
{
    Serial.begin(115200);

    // for PWM frequency of 3921.16 Hz
    TCCR2B &= B11111000 | B00000010;
}

// init motors and car
Car car {
    Wheel {6, 7},
    Wheel {A4, A3},
    Wheel {8, 9},
    Wheel {A1, A2}
};

void loop()
{
    car.forward();
    delay(1000);

    car.stop();
    delay(5000);

    car.backward();
    delay(1000);

    // Serial.print("Distance: ");
    // Serial.println(ultrasonic.getDistance());
}
