#ifndef CAR_H
#define CAR_H

#include "stdint.h"
#include "Wheel.h"

class Car
{
    private:
        Wheel wheelFrontLeft;
        Wheel wheelFrontRight;
        Wheel wheelBackLeft;
        Wheel wheelBackRight;

    public:
        Car(Wheel wheelFrontLeft, Wheel wheelFrontRight, Wheel wheelBackLeft, Wheel wheelBackRight);
        void forward();
        void backward();
        void left();
        void right();
        void stop();
};

#endif
