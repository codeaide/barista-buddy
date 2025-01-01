/**
 * @brief Frontend implementation header file
 */

#ifndef BABU_FRONTEND_IMPLEMENTATION_HEADER
#define BABU_FRONTEND_IMPLEMENTATION_HEADER

// includes
#include <LedControl.h>
#include "../../frontend.hpp"
#include "../../module.hpp"

namespace babu {

/**
 * @brief Frontend implementation
 */
class Frontend : public BaseModule, public IFrontend {
  public:
    /**
     * @brief Default constructor
     *
     * @param[in] pinDIN Pin connected to DIN
     * @param[in] pinCLK Pin connected to CLK
     * @param[in] pinCS Pin connected to CS
     * @param[in] nDevices Number of devices
     */
    Frontend(int pinDIN, int pinCLK, int pinCS, int nDevices);

    /**
     * @brief Method to initialize the module
     *
     * @return True when initialized successfully, False otherwise
     */
    bool init() override;

    /**
     * @brief Implementation of interface to display the temperature
     *
     * @param[in] tempValue Temperature value
     */
    void displayTemperature(float tempValue) override;

  private:
    // LED control object
    LedControl m_oLedCtrl;
};

} // namespace babu

#endif /* BABU_FRONTEND_IMPLEMENTATION_HEADER */
