#include "mbed.h"
#include "arm_book_lib.h"

#define DUTY_MIN 0.025
#define DUTY_MAX 0.125

#define PERIOD   0.020

#define DELAY_MS  1500

PwmOut servo(PF_9);

DigitalOut led(LED2);

// main() runs in its own thread in the OS
int main()
{
    servo.period(PERIOD);
    while (true) {
        led = ON;
        servo.write(DUTY_MIN);
        delay(DELAY_MS);
        led = OFF;
        servo.write(DUTY_MAX);
        delay(DELAY_MS);
    }
}

