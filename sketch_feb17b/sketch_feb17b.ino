#include <WiFi.h> // Usa el pin 15, no se puede usar para otra cosa
#include <WebServer.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include "ReleEsp32/ReleEsp32.h"
#include "WifiEsp32/WifiEsp32.h"
#include "ButtonEsp32/ButtonEsp32.h"
#include "CurrentSensorEsp32/CurrentSensorEsp32.h"
#include "LedEsp32/LedEsp32.h"

//WebServer server(80);
WifiEsp32 wifiEsp32;

#define GpioRele 13
ReleEsp32 rele(GpioRele, false);



#define GpioButton 22
int stateButton = 0;

ButtonEsp32 buttonFan(GpioButton);

//pines analogicos del 32 al 39
#define GpioCurrentSensor 35
CurrentSensorEsp32 currentSensorFan(GpioCurrentSensor, 12);

#define GpioPotentiometer 34

//Digital Analog Converter DAC, saladas analogicas puras canal1= 25, canal2= 26
#define GpioLed 25
LedEsp32 led(GpioLed, 0);


void setup()
{
  Serial.begin(115200);

  pinMode(2, OUTPUT);
  //wifiEsp32.init(server);
  wifiEsp32.init();
  rele.init(false);
  //wifiEsp32.getPassengers();
  // insertCountry();
}

void loop()
{
  /*
  digitalWrite(2, HIGH);
  delay(1000);*/

  wifiEsp32.listenClient();
  if (buttonFan.getWasPressured())
  {
    Serial.println("Boton precionado");
    if (!rele.getPreviousStatus())
    {
      rele.setState(true);
      float consumptionFan = currentSensorFan.getConsumption();
      wifiEsp32.sendNotification("dgchaarturo@gmail.com", "Ventilador prendido", "Consumo= " +String(consumptionFan)+"W" );
    }
    else
    {
      rele.setState(false);
      float consumptionFan = currentSensorFan.getConsumption();
      wifiEsp32.sendNotification("dgchaarturo@gmail.com", "Ventilador apagado", "Consumo= " +String(consumptionFan)+"W" );
    }
  }
  // digitalWrite(2, LOW);
  int valorPot = analogRead(GpioPotentiometer); // Lee el valor del potenciómetro
  valorPot = map(valorPot, 0, 4095, 0, 255);
  led.setStateDac(valorPot);
  delay(50);
}
