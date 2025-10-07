#ifndef ODOMETER_H
#define ODOMETER_H

#include <Arduino.h>

#include "ITick.h"

class Odometer : ITick
{
public:
    explicit Odometer();
    void begin(
        float wheelDiameter,
        u_int8_t hallPin,
        unsigned int debounce,
        unsigned int reportsPerRevolution
    );
    void tick() override;

    float getDistance() const;
    void reset();

private:
    uint8_t _hallPin;
    float _wheelDiameter;
    unsigned int _debounce;
    unsigned int _reportsPerRevolution;

    int _previousState;
    int _lastReportAt;
    unsigned long _count;
};

#endif // ODOMETER_H
