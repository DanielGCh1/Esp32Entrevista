#ifndef __CurrentSensorEsp32_H__
#define __CurrentSensorEsp32_H__

#include <Arduino.h>

class CurrentSensorEsp32
{
private:
    int pin;
    int CURRENT_SENSOR_OFFSET;
    int sensorSensitivity;
    double  voltageWorked;

public:
    CurrentSensorEsp32(int pin, double  voltageWorked);
    //~CurrentSensorEsp32();
    double  getConsumption();
    double  getValue();
};

#endif