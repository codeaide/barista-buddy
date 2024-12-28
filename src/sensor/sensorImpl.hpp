/**
 * @brief Sensor implementation header file
 */

#ifndef BABU_SENSOR_IMPLEMENTATION_HEADER
#define BABU_SENSOR_IMPLEMENTATION_HEADER

// includes
#include "../../module.hpp"
#include "../../sensor.hpp"

namespace babu {

/**
 * @brief Sensor implementation
 */
class Sensor : public BaseModule, public ISensor {
  public:
    /** Default constructor */
    Sensor();

  private:
};

} // namespace babu

#endif /* BABU_SENSOR_IMPLEMENTATION_HEADER */
