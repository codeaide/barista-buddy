/**
 * @brief Display implementation header file
 */

#ifndef BABU_DISPLAY_IMPLEMENTATION_HEADER
#define BABU_DISPLAY_IMPLEMENTATION_HEADER

// includes
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

  private:
};

} // namespace babu

#endif /* BABU_DISPLAY_IMPLEMENTATION_HEADER */
