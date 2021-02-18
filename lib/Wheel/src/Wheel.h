#ifndef WHEEL_H
#define WHEEL_H


#include "stdint.h"


class Wheel
{
    private:
        uint8_t in1;
        uint8_t in2;

    public:
        Wheel(uint8_t in1, uint8_t in2);
        void forward();
        void backward();
        void stop();
};

#endif
