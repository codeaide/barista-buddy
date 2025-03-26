#include <gtest/gtest.h>

#include "DallasTemperature.h"

OneWire::OneWire(uint8_t pin) {
}

DallasTemperature::DallasTemperature(OneWire*) {
}

void DallasTemperature::begin(void) {
}

uint8_t DallasTemperature::getDeviceCount(void) {
}

bool DallasTemperature::getAddress(uint8_t*, uint8_t) {
}

uint8_t DallasTemperature::getResolution(const uint8_t*) {
}

bool DallasTemperature::setResolution(const uint8_t*, uint8_t, bool skipGlobalBitResolutionCalculation) {
}

DallasTemperature::request_t DallasTemperature::requestTemperatures(void) {
}

float DallasTemperature::getTempC(const uint8_t*, byte retryCount) {
}

int main(void) {
  return 0;
}
