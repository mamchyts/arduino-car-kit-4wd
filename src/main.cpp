#include "stdint.h"
#include <Arduino.h>
#include "Wheel.h"


const uint8_t PIN_IN_1_LEFT = 5;
const uint8_t PIN_IN_2_LEFT = 4;
const uint8_t PIN_IN_3_LEFT = 7;
const uint8_t PIN_IN_4_LEFT = 6;
const uint8_t PIN_IN_1_RIGHT = PIN_A4;
const uint8_t PIN_IN_2_RIGHT = PIN_A3;
const uint8_t PIN_IN_3_RIGHT = PIN_A1;
const uint8_t PIN_IN_4_RIGHT = PIN_A2;

void setup()
{
    Serial.begin(115200);

    // for PWM frequency of 3921.16 Hz
    TCCR2B &= B11111000 | B00000010;
}


// init motors
Wheel wheelLeftFront {PIN_IN_1_LEFT, PIN_IN_2_LEFT};
Wheel wheelLeftBack {PIN_IN_3_LEFT, PIN_IN_4_LEFT};
Wheel wheelRightFront {PIN_IN_1_RIGHT, PIN_IN_2_RIGHT};
Wheel wheelRightBack {PIN_IN_3_RIGHT, PIN_IN_4_RIGHT};

void loop()
{
    delay(1000);
    wheelLeftFront.forward();
    wheelLeftBack.forward();
    wheelRightFront.forward();
    wheelRightBack.forward();

    delay(1000);
    wheelLeftFront.stop();
    wheelLeftBack.stop();
    wheelRightFront.stop();
    wheelRightBack.stop();

    delay(1000);
    wheelLeftFront.backward();
    wheelLeftBack.backward();
    wheelRightFront.backward();
    wheelRightBack.backward();

    delay(1000);
    wheelLeftFront.stop();
    wheelLeftBack.stop();
    wheelRightFront.stop();
    wheelRightBack.stop();

    delay(1000);
    wheelLeftFront.backward();
    wheelLeftBack.backward();
    wheelRightFront.forward();
    wheelRightBack.forward();

    delay(1000);
    wheelLeftFront.stop();
    wheelLeftBack.stop();
    wheelRightFront.stop();
    wheelRightBack.stop();

    delay(1000);
    wheelLeftFront.forward();
    wheelLeftBack.forward();
    wheelRightFront.backward();
    wheelRightBack.backward();

    delay(1000);
    wheelLeftFront.stop();
    wheelLeftBack.stop();
    wheelRightFront.stop();
    wheelRightBack.stop();

    // Serial.print("Distance: ");
    // Serial.println(ultrasonic.getDistance());
}

