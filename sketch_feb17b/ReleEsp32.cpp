#include "ReleEsp32/ReleEsp32.h"

void ReleEsp32::on()
{
    digitalWrite(pin, HIGH);
}

void ReleEsp32::off()
{
    digitalWrite(pin, LOW);
}

ReleEsp32::ReleEsp32(int pin, bool state)
{
    this->pin = pin;
    this->state = state;
    this->previousStatus = state;
    init(state);
}

//ReleEsp32::~ReleEsp32() {}

void ReleEsp32::init(bool state)
{
    pinMode(pin, OUTPUT);
    if(state == true){
        on();
    }
    else
    {
        off();
    }
    
}

bool ReleEsp32::getState()
{
    return this->state;
}

void ReleEsp32::setState(bool state)
{
    this->state = state;
    if(this->state == true){
        on();
    }
    else
    {
        off();
    }
}
bool ReleEsp32::getPreviousStatus()
{
    return previousStatus;
}
void ReleEsp32::setPreviousStatus(bool previousStatus)
{
    this->previousStatus = previousStatus;
}
