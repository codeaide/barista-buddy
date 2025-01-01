/**
 * @brief Frontend interface header file
 */
#ifndef BABU_FRONTEND_INTERFACE_HEADER
#define BABU_FRONTEND_INTERFACE_HEADER

namespace babu {

/**
 * @brief Frontend interface
 */
class IFrontend {
  public:
    /**
     * @brief Virtual destructor
     */
    virtual ~IFrontend() { }

    /**
     * @brief Interface to display the temperature
     *
     * @param[in] tempValue Temperature value
     */
    virtual void displayTemperature(float tempValue) = 0;
};

} // namespace babu

#endif /* BABU_FRONTEND_INTERFACE_HEADER */
