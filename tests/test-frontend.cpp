#include <gtest/gtest.h>

#include "LedControl.h"

LedControl::LedControl(int dataPin, int clkPin, int csPin, int numDevices) {
}

int LedControl::getDeviceCount() {
}

void LedControl::shutdown(int addr, bool status) {
}

void LedControl::setIntensity(int addr, int intensity) {
}

void LedControl::clearDisplay(int addr) {
}

void LedControl::setLed(int addr, int row, int col, boolean state) {
}

void LedControl::setRow(int addr, int row, byte value) {
}

int main(void) {
  return 0;
}
