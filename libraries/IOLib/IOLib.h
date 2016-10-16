/*
IOLib.h - библиотека-обертка операций ввода/вывода для Arduino...
*/

#ifndef IOLib_h
#define IOLib_h

#include "Arduino.h"
#include "DigitalInput.h"
#include "DigitalOutput.h"

DigitalInput newDI(byte pin);    // создание цифрового входа
DigitalInput newDI(byte pin, long debounceTime);    //

#endif
