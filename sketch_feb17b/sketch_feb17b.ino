#include <WiFi.h> // Usa el pin 15, no se puede usar para otra cosa
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include "ReleEsp32/ReleEsp32.h"
#include "WifiEsp32/WifiEsp32.h"

#define GpioRele 13
ReleEsp32 rele(GpioRele, false);
WifiEsp32 wifiEsp32;

#define GpioButton 22
int stateButton = 0;

void setup()
{
  Serial.begin(115200);
  wifiEsp32.init();

  pinMode(GpioButton, INPUT);
  pinMode(2, OUTPUT);

  wifiEsp32.getPassengers();
  //insertCountry();
}

void loop()
{
  /*
  digitalWrite(2, HIGH);
  delay(1000);*/
  stateButton = digitalRead(GpioButton);

  if (!stateButton == HIGH && !stateButton != rele.getPreviousStatus())
  {
    rele.setState(true);
    rele.setPreviousStatus(true);
    wifiEsp32.sendNotification("dgchaarturo@gmail.com", "Ventilador prendido", "Consumo= 0mA");
  }
  if(!stateButton == LOW && !stateButton != rele.getPreviousStatus())
  {
    rele.setState(false);
    rele.setPreviousStatus(false);
    wifiEsp32.sendNotification("dgchaarturo@gmail.com", "Ventilador apagado", "Consumo= 0mA");
  }
  //digitalWrite(2, LOW);
  delay(100);
}
