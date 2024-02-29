#include "WifiEsp32/WifiEsp32.h"

WifiEsp32::WifiEsp32() {
    apiEndpoint = "http://192.168.1.105:3000";
}


// WifiEsp32::~WifiEsp32() {}

void WifiEsp32::init()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Conectando a WiFi...");
    }
    Serial.println("Conectado a la red WiFi");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.localIP());

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}
void WifiEsp32::listenClient(WebServer &ser)
{
    ser.handleClient();
}

void WifiEsp32::insertCountry()
{
    httpClient.begin(apiEndpoint + "/setCountry");

    String postData = "{\"pais_nombre\": \"Canada\"}";

    httpClient.addHeader("Content-Type", "application/json");

    int httpCode = httpClient.POST(postData);

    if (httpCode > 0)
    {
        String payload = httpClient.getString();
        Serial.println(payload);
    }
    else
    {
        Serial.println("Error en la petición POST");
    }

    httpClient.end();
}
/*
String WifiEsp32::getTime()
{
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("Error al obtener la hora");
        return;
    }

    char timeStringBuff[50];
    strftime(timeStringBuff, sizeof(timeStringBuff), "%A, %B %d %Y %H:%M:%S", &timeinfo);
    String timeStr = String(timeStringBuff);
    return timeStr;
}
*/

void WifiEsp32::sendNotification(String gmail, String affair, String message)
{
    httpClient.begin(apiEndpoint + "/sendEmail");

    String postData = "{";
    postData += "\"destinatarios\": \"" + gmail + "\", ";
    postData += "\"asunto\": \"" + affair + "\", ";
    postData += "\"mensaje\": \"" + message + "\"";
    postData += "}";

    httpClient.addHeader("Content-Type", "application/json");

    int httpCode = httpClient.POST(postData);

    if (httpCode > 0)
    {
        String payload = httpClient.getString();
        Serial.println(payload);
    }
    else
    {
        Serial.println("Error en la petición POST");
    }

    httpClient.end();
}
void WifiEsp32::getPassengers()
{
    httpClient.begin(apiEndpoint + "/getPassengers");

    int httpCode = httpClient.GET();

    String payload = "";

    Serial.println("httpCode: " + httpCode);
    if (httpCode > 0)
    {
        payload = httpClient.getString();
        JSONVar myObject = JSON.parse(payload);

        if (JSON.typeof(myObject) == "undefined")
        {
            Serial.println("Parsing input failed!");
            return;
        }

        for (int i = 0; i < myObject.length(); i++)
        {
            JSONVar item = myObject[i];
            Serial.println("Item " + String(i) + ":");
            Serial.println("ID: " + String((const char *)item["PASA_CEDULA"]));
            Serial.println("Passport: " + String((const char *)item["PASA_PASAPORTE"]));
            Serial.println("First Name: " + String((const char *)item["PASA_PRIMER-NOMBRE"]));
            Serial.println("Middle Name: " + String((const char *)item["PASA_SEGUNDO-NOMBRE"]));
            Serial.println("Last Name: " + String((const char *)item["PASA_PRIMER-APELLIDO"]));
            Serial.println("Other Name: " + String((const char *)item["PASA_SEGUNDO-APELLIDO"]));
            Serial.println("Country ID: " + String((int)item["PASA_FK-PAIS"]));
            Serial.println("Location: " + String((const char *)item["PASA_LUGAR-RESIDENCIA"]));
            Serial.println("Birthdate: " + String((const char *)item["PASA_FECHA-NACIMIENTO"]));
            Serial.println("Nationality: " + String((const char *)item["PASA_NACIONALIDAD"]));

            Serial.println();
        }
    }
    else
    {
        Serial.println("Error en la petición GET");
    }

    httpClient.end();
}
