#ifndef _LEDCONTROL_STUB_HEADER_
#define _LEDCONTROL_STUB_HEADER_

#include <iostream>

#include "Arduino.h"

typedef bool boolean;

class LedControl {
public:
  LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);

  int getDeviceCount();

  void shutdown(int addr, bool status);

  void setScanLimit(int addr, int limit);

  void setIntensity(int addr, int intensity);

  void clearDisplay(int addr);

  void setLed(int addr, int row, int col, boolean state);

  void setRow(int addr, int row, byte value);

  void setColumn(int addr, int col, byte value);

  void setDigit(int addr, int digit, byte value, boolean dp);

  void setChar(int addr, int digit, char value, boolean dp);
};

#endif /* _LEDCONTROL_STUB_HEADER_ */

