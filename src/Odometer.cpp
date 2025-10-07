#include "Odometer.h"

Odometer::Odometer()
    : _hallPin(0), _wheelDiameter(0), _debounce(0), _reportsPerRevolution(0),
      _previousState(LOW), _lastReportAt(0), _count(0)
{
}

void Odometer::begin(
    float wheelDiameter,
    u_int8_t hallPin,
    unsigned int debounce,
    unsigned int reportsPerRevolution
)
{
    _reportsPerRevolution = reportsPerRevolution;
    _hallPin = hallPin;
    _wheelDiameter = wheelDiameter;
    _debounce = debounce;
    pinMode(hallPin, INPUT);
}

void Odometer::tick()
{
    const int currentState = digitalRead(_hallPin);
    auto ms = millis();
    if (currentState == HIGH && _previousState == LOW && (ms - _lastReportAt) > _debounce)
    {
        Serial.println("reporting!");
        _lastReportAt = ms;
        _count++;
    }
    _previousState = currentState;
}

float Odometer::getDistance() const
{
    float rounds = static_cast<float>(_count) / _reportsPerRevolution;;
    return rounds * _wheelDiameter * M_PI;
}

void Odometer::reset()
{
    _count = 0;
    _lastReportAt = 0;
    _previousState = LOW;
}