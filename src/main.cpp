#include "Car.h"
#include "stdint.h"
#include "Wheel.h"
#include <Arduino.h>
#include <RF24.h>
#include <SPI.h>
#include "printf.h"

// init motors and car
Car car {
    Wheel {7, 6},
    Wheel {A3, A4},
    Wheel {8, 9},
    Wheel {A1, A2}
};

RF24 radio(2, 3); // CE, CSN
uint32_t address = 1234566789;
uint8_t payload[10] = {0};

const int8_t PIN_LASER = 4;

void setup()
{
    // laser
    pinMode(PIN_LASER, OUTPUT);

    // init RF24
    radio.begin();
    radio.setChannel(60);
    radio.setAutoAck(false);
    radio.setPALevel(RF24_PA_LOW);
    radio.openReadingPipe(1, address);
    radio.setPayloadSize(sizeof(payload));
    radio.startListening();
}

void loop()
{
    uint8_t pipe = 0;
    if (radio.available(&pipe)) {
        radio.read(&payload, radio.getPayloadSize());

        // parse btn(s)
        uint8_t a = payload[0];
        if (a == 1) {
            digitalWrite(PIN_LASER, HIGH);
        } else {
            digitalWrite(PIN_LASER, LOW);
        }

        // parse joy X/Y positions
        uint8_t x = payload[4];
        uint8_t y = payload[5];

        if (x < 50) {
            car.left();
        } else if (x > 200) {
            car.right();
        } else if (y < 50) {
            car.backward();
        } else if (y > 200) {
            car.forward();
        } else {
            car.stop();
        }
    }
}