/**
 * @brief Display implementation header file
 */

#ifndef BABU_DISPLAY_IMPLEMENTATION_HEADER
#define BABU_DISPLAY_IMPLEMENTATION_HEADER

// includes
#include <LedControl.h>
#include "../../module.hpp"
#include "../../display.hpp"

namespace babu {

/**
 * @brief Display implementation
 */
class Display : public BaseModule, public IDisplay {
  public:
    /**
     * @brief Default constructor
     *
     * @param[in] pinDIN Pin connected to DIN
     * @param[in] pinCLK Pin connected to CLK
     * @param[in] pinCS Pin connected to CS
     * @param[in] nDevices Number of devices
     */
    Display(int pinDIN, int pinCLK, int pinCS, int nDevices);

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

#endif /* BABU_DISPLAY_IMPLEMENTATION_HEADER */
