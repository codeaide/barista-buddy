/**
 * @brief Controller implementation header file
 */

#ifndef BABU_CONTROLLER_IMPLEMENTATION_HEADER
#define BABU_CONTROLLER_IMPLEMENTATION_HEADER

// includes
#include "../../module.hpp"
#include "../../controller.hpp"

namespace babu {

/**
 * @brief Controller implementation
 */
class Controller : public BaseModule, public IController {
  public:
    // default constructor
    Controller();

  private:
};

} // namespace babu

#endif /* BABU_CONTROLLER_IMPLEMENTATION_HEADER */
