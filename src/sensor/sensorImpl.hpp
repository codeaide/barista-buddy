/**
 * @brief Sensor implementation header file
 */

#ifndef BABU_SENSOR_IMPLEMENTATION_HEADER
#define BABU_SENSOR_IMPLEMENTATION_HEADER

// includes
#include <OneWire.h>
#include <DallasTemperature.h>
#include "../../module.hpp"
#include "../../sensor.hpp"

namespace babu {

/**
 * @brief Sensor implementation
 */
class Sensor : public BaseModule, public ISensor {
  public:
    /**
     * @brief Default constructor
     *
     * @param[in] ioPin Digital pin to which the sensors are connected
     */
    Sensor(int ioPin);

    /**
     * @brief Method to initialize the module
     *
     * @return True when initialized successfully, False otherwise
     */
    bool init() override;

    /**
     * @brief Method to process the module
     *
     * @return True when processed successfully, False otherwise
     */
    bool process() override;

    /**
     * @brief Implementation of interface to read the temperature
     */
    float getTemperature() override;

  private:
    // OneWire device instance
    OneWire m_oOneWire;

    // DallasTemperature library instance
    DallasTemperature m_oSensors;

    // address of the temperature sensor
    DeviceAddress m_oDeviceAddr;

    // number of devices
    int m_iDevices;

    /**
     * @brief Method to print the device address
     */
    void printAddress(DeviceAddress deviceAddress);
};

} // namespace babu

#endif /* BABU_SENSOR_IMPLEMENTATION_HEADER */
