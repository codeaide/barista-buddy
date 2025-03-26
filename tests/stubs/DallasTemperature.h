#ifndef _DALLAS_TEMPERATURE_STUB_HEADER_
#define _DALLAS_TEMPERATURE_STUB_HEADER_

#include <iostream>

#include "Arduino.h"
#include "OneWire.h"

// Error Codes
#define DEVICE_DISCONNECTED_C -127
#define DEVICE_DISCONNECTED_F -196.6
#define DEVICE_DISCONNECTED_RAW -7040

#define DEVICE_FAULT_OPEN_C -254
#define DEVICE_FAULT_OPEN_F -425.199982
#define DEVICE_FAULT_OPEN_RAW -32512

#define DEVICE_FAULT_SHORTGND_C -253
#define DEVICE_FAULT_SHORTGND_F -423.399994
#define DEVICE_FAULT_SHORTGND_RAW -32384

#define DEVICE_FAULT_SHORTVDD_C -252
#define DEVICE_FAULT_SHORTVDD_F -421.599976
#define DEVICE_FAULT_SHORTVDD_RAW -32256

typedef std::uint8_t DeviceAddress[8];

class DallasTemperature {
public:
  struct request_t {
    bool result;
    unsigned long timestamp;
    operator bool() {
      return result;
    }
  };

  DallasTemperature();
  DallasTemperature(OneWire*);
  DallasTemperature(OneWire*, uint8_t);

   void begin(void);

   uint8_t getDeviceCount(void);

   bool getAddress(uint8_t*, uint8_t);

   bool setResolution(const uint8_t*, uint8_t, bool skipGlobalBitResolutionCalculation = false);

   uint8_t getResolution(const uint8_t*);

   request_t requestTemperatures(void);

   float getTempC(const uint8_t*, byte retryCount = 0);
};

#endif /* _DALLAS_TEMPERATURE_STUB_HEADER_ */

