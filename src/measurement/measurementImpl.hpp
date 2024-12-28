/**
 * @brief Measurement implementation header file
 */

#ifndef BABU_MEASUREMENT_IMPLEMENTATION_HEADER
#define BABU_MEASUREMENT_IMPLEMENTATION_HEADER

// includes
#include "../../module.hpp"
#include "../../measurement.hpp"

namespace babu {

/**
 * @brief Measurement implementation
 */
class Measurement : public BaseModule, public IMeasurement {
  public:
    /** Default constructor */
    Measurement();

  private:
};

} // namespace babu

#endif /* BABU_MEASUREMENT_IMPLEMENTATION_HEADER */
