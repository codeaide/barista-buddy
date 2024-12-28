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
class Display : public BaseModule, IDisplay {
  public:
    /** Default constructor */
    Display();

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

  private:
    // LED control object
    LedControl m_oLedCtrl;
};

} // namespace babu

#endif /* BABU_DISPLAY_IMPLEMENTATION_HEADER */
