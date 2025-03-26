#ifndef _ARDUINO_STUB_HEADER_
#define _ARDUINO_STUB_HEADER_

#include <iostream>
#include <string>
#include <cstdint>

#define DEC 0
#define HEX 1

typedef std::string String;

typedef std::uint8_t byte;

class SerialStub {
public:
  void print(int intVal, int printFormat = 0);
  void print(std::string strMsg);
  void println();
  void println(float& floatVal);
  void println(std::string strMsg);
};

extern SerialStub Serial;

#endif /* _ARDUINO_STUB_HEADER_ */
