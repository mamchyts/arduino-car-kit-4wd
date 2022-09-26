#include "stdint.h"
#include <Arduino.h>
#include "Car.h"
#include "Wheel.h"

Car::Car(Wheel wfl, Wheel wfr, Wheel wbl, Wheel wbr): wheelFrontLeft{wfl}, wheelFrontRight{wfr}, wheelBackLeft{wbl}, wheelBackRight{wbr}
{
    stop();
}

void Car::forward()
{
    wheelFrontLeft.forward();
    wheelFrontRight.forward();
    wheelBackLeft.forward();
    wheelBackRight.forward();
}

void Car::backward()
{
    wheelFrontLeft.backward();
    wheelFrontRight.backward();
    wheelBackLeft.backward();
    wheelBackRight.backward();
}

void Car::left()
{
    wheelFrontLeft.stop();
    wheelFrontRight.forward();
    wheelBackLeft.stop();
    wheelBackRight.forward();
}

void Car::right()
{
    wheelFrontLeft.forward();
    wheelFrontRight.stop();
    wheelBackLeft.forward();
    wheelBackRight.stop();
}

void Car::stop()
{
    wheelFrontLeft.stop();
    wheelFrontRight.stop();
    wheelBackLeft.stop();
    wheelBackRight.stop();
}
