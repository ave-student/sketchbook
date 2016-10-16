/*
IOLib.h - библиотека-обертка операций ввода/вывода для Arduino...
*/

#ifndef IOLib_h
#define IOLib_h

#include "Arduino.h"
#include "DigitalInput.h"
#include "SDigitalOutput.h"

DigitalInput newDI(byte pin);    // создание цифрового входа
DigitalInput newDI(byte pin, long debounceTime);    //

SDigitalOutput newDO(byte pin);    // создание цифорового выхода
SDigitalOutput newDO(byte pin, byte initState);    //

#endif
