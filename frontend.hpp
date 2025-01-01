/**
 * @brief Display interface header file
 */
#ifndef BABU_DISPLAY_INTERFACE_HEADER
#define BABU_DISPLAY_INTERFACE_HEADER

namespace babu {

/**
 * @brief Display interface
 */
class IDisplay {
  public:
    /**
     * @brief Virtual destructor
     */
    virtual ~IDisplay() { }

    /**
     * @brief Interface to display the temperature
     *
     * @param[in] tempValue Temperature value
     */
    virtual void displayTemperature(float tempValue) = 0;
};

} // namespace babu

#endif /* BABU_DISPLAY_INTERFACE_HEADER */
