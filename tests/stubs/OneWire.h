#ifndef _ONEWIRE_STUB_HEADER_
#define _ONEWIRE_STUB_HEADER_

#include <iostream>

#include "Arduino.h"


class OneWire {
public:
  OneWire();
  OneWire(uint8_t pin);
};

#endif /* _ONEWIRE_STUB_HEADER_ */

