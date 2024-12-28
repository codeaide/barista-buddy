/**
 * @brief Relay implementation header file
 */

#ifndef BABU_RELAY_IMPLEMENTATION_HEADER
#define BABU_RELAY_IMPLEMENTATION_HEADER

// includes
#include "../../module.hpp"
#include "../../relay.hpp"

namespace babu {

/**
 * @brief Relay implementation
 */
class Relay : public BaseModule, IRelay {
  public:
    /** Default constructor */
    Relay();

  private:
};

} // namespace babu

#endif /* BABU_RELAY_IMPLEMENTATION_HEADER */
