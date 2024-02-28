#ifndef __LedEsp32_H__
#define __LedEsp32_H__

#include <Arduino.h>

class LedEsp32
{
private:
    int pin;
    int value;
    void onDac(int value);
    void offDac();

public:
    LedEsp32(int pin, int value);
    //~LedEsp32();
    void init(int value);
    bool getStateDac();
    void setStateDac(int value);
};

#endif