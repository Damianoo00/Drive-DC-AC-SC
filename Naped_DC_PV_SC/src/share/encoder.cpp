#include <Arduino.h>
#include <RotaryEncoder.h>
#include <stdint.h>

int get_speed_from_encoder(RotaryEncoder encoder)
{
    uint32_t time;
    uint16_t dx, dt, newPos;
    static uint16_t pos = 0;

    encoder.tick();
    time = millis();
    newPos = encoder.getPosition();
    if (pos != newPos)
    {
        dx = newPos - pos;
        dt = millis() - time;
        pos = newPos;
    }
    return dx / dt;
}