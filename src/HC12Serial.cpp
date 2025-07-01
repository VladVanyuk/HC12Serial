#include "HC12Serial.h"

HC12Serial::HC12Serial(uint8_t rxPin, uint8_t txPin, uint8_t setPin) : 
    SoftwareSerial(rxPin, txPin),
    _setPin(setPin)
{
}

void HC12Serial::begin(int32_t baud)
{
    pinMode(_setPin, OUTPUT);
    setModeOff();
    SoftwareSerial::begin(baud);
}

void HC12Serial::setModeOff()
{
    digitalWrite(_setPin, HIGH);
}

void HC12Serial::setModeOn()
{
    digitalWrite(_setPin, LOW);
}

String HC12Serial::readPayload()
{
    String payload;
    char attributes[1000];

    if (this->available() > 0) {
        while (this->available() > 0) {
            payload = this->readString();
            payload.toCharArray(attributes, 1000);
            // Serial.print(attributes);
        }
    }
    return payload;
}