#include "stdint.h"
#include <Arduino.h>
#include "Wheel.h"

Wheel::Wheel(uint8_t pinIn1, uint8_t pinIn2): in1{pinIn1}, in2{pinIn2}
{
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    // turn off motors by default
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}

void Wheel::forward()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
}

void Wheel::backward()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
}

void Wheel::stop()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}
