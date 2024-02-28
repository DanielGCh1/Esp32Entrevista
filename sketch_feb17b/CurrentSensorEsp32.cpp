#include "CurrentSensorEsp32/CurrentSensorEsp32.h"

CurrentSensorEsp32::CurrentSensorEsp32(int pin, double  voltageWorked)
{
    this->pin = pin;
    this->CURRENT_SENSOR_OFFSET = 2500;
    // this->CURRENT_SENSOR_SENSITIVITY = 185;
    this->sensorSensitivity = 0.066;
    this->voltageWorked = voltageWorked;
}

// CurrentSensorEsp32::~CurrentSensorEsp32() {}
double  CurrentSensorEsp32::getConsumption()
{
    double  total = 0;
    int count = 1000;
    for (int i = 0; i <= count; i++)
    {
        delay(1);
        /*float sensorValue = analogRead(pin);
        Serial.println("sensorValue " + String(sensorValue));
        float voltageSensor = sensorValue * (3.300 / 4095.000);
        Serial.println("voltageSensor " + String(voltageSensor));
        float current = (voltageSensor - 1.49) / sensorSensitivity;
        Serial.println("current " + String(current));*/
        double pin34 = (analogRead(34) * (3.3 / 4095.0))*1000;
        Serial.println("pin34 " + String(pin34));
        double  sensorValue = analogRead(pin);
        Serial.println("sensorValue " + String(sensorValue));
        double  voltageSensor = (sensorValue * (3.3 / 4095.0))*1000;
        Serial.println("voltageSensor " + String(voltageSensor));
        double  current = (voltageSensor - 1696.34) / 66;
        Serial.println("current " + String(current));
        total += current;
    }
    total = total/count;
    return voltageWorked * total;
}
double  CurrentSensorEsp32::getValue()
{
    double  sensorValue = analogRead(pin);
    return sensorValue;
}