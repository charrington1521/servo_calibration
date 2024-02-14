#include "mbed.h"
#include "arm_book_lib.h"

#define DUTY_FULL_SPEED_REVERSE 0.05
#define DUTY_STOPPED            0.075
#define DUTY_FULL_SPEED_FORWARD 0.10

#define RPM_FULL_FORWARD        >40
#define RPM_FULL_BACKWARDS      ~>40

#define PERIOD   0.020

#define DELAY_MS  5000

PwmOut servo(PF_9);

DigitalOut led(LED2);

// main() runs in its own thread in the OS
int main()
{
    servo.period(PERIOD);
    servo.write(DUTY_STOPPED);
    while (true) {
        led = ON;
        servo.write(DUTY_FULL_SPEED_FORWARD);
        delay(DELAY_MS);
        led = OFF;
        servo.write(DUTY_STOPPED);
        delay(DELAY_MS);
        // led = ON;
        // servo.write(DUTY_FULL_SPEED_REVERSE);
        // delay(DELAY_MS);
        // led = OFF;
        // servo.write(DUTY_STOPPED);
        // delay(DELAY_MS);
    }
}

