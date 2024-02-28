#ifndef __ReleEsp32_H__
#define __ReleEsp32_H__

#include <Arduino.h>
#include "../WifiEsp32/WifiEsp32.h"

class ReleEsp32 : public WifiEsp32
{
private:
    int pin;
    bool state;
    bool previousStatus;
    void on();
    void off();

public:
    ReleEsp32(int pin, bool state);
    //~ReleEsp32();
    void init(bool state);
    bool getState();
    void setState(bool state);
    bool getPreviousStatus();
    void setPreviousStatus(bool previousStatus);
    void releOn();
    void releOff();
};

#endif