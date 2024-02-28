#include "ReleEsp32/ReleEsp32.h"

void ReleEsp32::on()
{
    digitalWrite(pin, HIGH);
    sendNotification("dgchaarturo@gmail.com", "Ventilador prendido", "Consumo= 0W");
}

void ReleEsp32::off()
{
    digitalWrite(pin, LOW);
    sendNotification("dgchaarturo@gmail.com", "Ventilador apagado", "Consumo= 0W");
}

ReleEsp32::ReleEsp32(int pin, bool state) {
    this->pin = pin;
    this->state = state;
    this->previousStatus = state;
}


// ReleEsp32::~ReleEsp32() {}

void ReleEsp32::init(bool state)
{
    pinMode(pin, OUTPUT);
    if (state)
    {
        on();
    }
    else
    {
        off();
    }
    server.on("/releOn", [this]() { releOn(); });
    server.on("/releOff", [this]() { releOff(); });
}

void ReleEsp32::releOn()
{
    setState(true);
    server.send(200, "text/html", "Rele On");
}

void ReleEsp32::releOff()
{
    setState(false);
    server.send(200, "text/html", "Rele OFF");
}
bool ReleEsp32::getState()
{
    return this->state;
}

void ReleEsp32::setState(bool state)
{
    this->state = state;
    if (this->state)
    {
        setPreviousStatus(true);
        on();
    }
    else
    {
        setPreviousStatus(false);
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
