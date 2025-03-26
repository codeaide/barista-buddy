#include "Arduino.h"

void SerialStub::print(int intVal, int printFormat) {
  if (HEX == printFormat) {
    std::cout << std::hex << intVal;
  } else {
    std::cout << intVal;
  }
}

void SerialStub::print(std::string strMsg) {
  std::cout << strMsg;
}

void SerialStub::println() {
  println("");
}

void SerialStub::println(float& floatVal) {
  println(floatVal);
}

void SerialStub::println(std::string strMsg) {
  std::cout << strMsg << std::endl;
}

SerialStub Serial;
