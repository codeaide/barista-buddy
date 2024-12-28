/**
 * @brief Sensor interface header file
 */
#ifndef BABU_SENSOR_INTERFACE_HEADER
#define BABU_SENSOR_INTERFACE_HEADER

namespace babu {

/**
 * @brief Sensor interface
 */
class ISensor {
  public:
    /**
     * @brief Virtual destructor
     */
    virtual ~ISensor() { }
};

} // namespace babu

#endif /* BABU_SENSOR_INTERFACE_HEADER */
