#ifndef __WifiEsp32_H__
#define __WifiEsp32_H__

#include <Arduino.h>
#include <WiFi.h> // Usa el pin 15, no se puede usar para otra cosa
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include "time.h"

class WifiEsp32
{
private:
    const char *ssid = "Jane2";
    const char *password = "hp5wna95";
    HTTPClient httpClient;
    const char *ntpServer = "pool.ntp.org";
    const long gmtOffset_sec = 0;
    const int daylightOffset_sec = 3600;

public:
    WifiEsp32();
    //~ReleEsp32();
    void init();
    void getPassengers();
    void insertCountry();
    void sendNotification(String gmail, String affair, String message);
    String getTime();
};

#endif