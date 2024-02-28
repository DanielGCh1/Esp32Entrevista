#include "ButtonEsp32/ButtonEsp32.h"

// Boton es pull up, cuando es precionado marca LOW, solo se niega !

ButtonEsp32::ButtonEsp32(int pin)
{
    this->pin = pin;
    this->wasPressured = false;
    init();
}

//ButtonEsp32::~ButtonEsp32() {}

void ButtonEsp32::init()
{
    pinMode(pin, INPUT);   
}
void ButtonEsp32::setWasPressured(bool wasPressured){
    this->wasPressured = wasPressured;
}
bool ButtonEsp32::getState()
{
    bool pressed = !digitalRead(pin);
    if(pressed){
        setWasPressured(pressed);
    } 
    return pressed;
}
bool ButtonEsp32::getWasPressured(){
    getState();
    if(!getState() && this->wasPressured){
        setWasPressured(false);
        return true;
    }
    return false;
}

