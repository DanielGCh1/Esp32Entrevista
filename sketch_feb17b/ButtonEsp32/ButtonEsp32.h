#ifndef __ButtonEsp32_H__
#define __ButtonEsp32_H__

#include <Arduino.h>

class ButtonEsp32
{
private:
    int pin;
    bool wasPressured;

public:
    ButtonEsp32(int pin);
    //~ButtonEsp32();
    void init();
    bool getState();
    bool getWasPressured();
    void setWasPressured(bool wasPressured);
};

#endif