/**
 * @brief Measurement interface header file
 */
#ifndef BABU_MEASUREMENT_INTERFACE_HEADER
#define BABU_MEASUREMENT_INTERFACE_HEADER

namespace babu {

/**
 * @brief Measurement interface
 */
class IMeasurement {
  public:
    /**
     * @brief Virtual destructor
     */
    virtual ~IMeasurement() { }
};

} // namespace babu

#endif /* BABU_MEASUREMENT_INTERFACE_HEADER */
