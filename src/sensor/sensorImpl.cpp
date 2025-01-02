/**
 * @brief Sensor implementation source file
 */

// includes
#include "sensorImpl.hpp"

babu::Sensor::Sensor(int ioPin) : BaseModule("Sensor"),
                                  m_oOneWire(ioPin),
                                  m_oSensors(&m_oOneWire),
                                  m_iDevices(-1) {
}

// Method to initialize the module
bool babu::Sensor::init() {
  // start up the library
  m_oSensors.begin();

  // locate devices on the bus
  Serial.print("Locating temperature sensors...");
  Serial.print("Found ");
  m_iDevices = m_oSensors.getDeviceCount();
  Serial.print(m_iDevices, DEC);
  Serial.println(" sensors.");

  Serial.print("Sensor 0 : ADDR ");
  if (!m_oSensors.getAddress(m_oDeviceAddr, 0)) {
    Serial.print("UNKNOWN ");
  } else {
    printAddress(m_oDeviceAddr);
    Serial.print(" ");
  }

  // set device resolution to 9, 10, 11, or 12 bits
  m_oSensors.setResolution(m_oDeviceAddr, 10);

  Serial.print("RES ");
  Serial.print(m_oSensors.getResolution(m_oDeviceAddr), DEC);
  Serial.println();

  return true;
}

// Method to initialize the module
bool babu::Sensor::process() {
  // issue command to all devices for reading temperature
  m_oSensors.requestTemperatures();

  return true;
}

// Implementation of interface to read the temperature
float babu::Sensor::getTemperature() {
  // get the temperature based on address
  float tempC = m_oSensors.getTempC(m_oDeviceAddr);

  // check if reading was successful
  if (tempC != DEVICE_DISCONNECTED_C) {
    Serial.print("Temperature for the device 1 (index 0) is: ");
    Serial.println(tempC);
  } else {
    Serial.println("Error: Could not read temperature data");
  }

  return tempC;
}

// Method to print the device address
void babu::Sensor::printAddress(DeviceAddress deviceAddress) {
  for (uint8_t iIndex = 0; iIndex < 8; iIndex++) {
    if (deviceAddress[iIndex] < 16) Serial.print("0");
    Serial.print(deviceAddress[iIndex], HEX);
  }
}
