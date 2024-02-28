#include "LedEsp32/LedEsp32.h"

void LedEsp32::onDac(int value)
{
    dacWrite(pin, value);
}

void LedEsp32::offDac()
{
    dacWrite(pin, 0);
}

LedEsp32::LedEsp32(int pin, int value)
{
    this->pin = pin;
    init(value);
}

//LedEsp32::~LedEsp32() {}

void LedEsp32::init(int value)
{
    if(value > 0){
        this->value = value;
        onDac(value);
    }
    else
    {
        this->value = 0;
        offDac();
    }
    
}

bool LedEsp32::getStateDac()
{
    return this->value;
}

void LedEsp32::setStateDac(int value)
{
    if(value > 0){
        this->value = value;
        onDac(value);
    }
    else
    {
        this->value = 0;
        offDac();
    }
}
