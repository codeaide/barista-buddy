/**
 * @brief Controller implementation header file
 */

#ifndef BABU_CONTROLLER_IMPLEMENTATION_HEADER
#define BABU_CONTROLLER_IMPLEMENTATION_HEADER

// includes
#include "../../controller.hpp"
#include "../../frontend.hpp"
#include "../../module.hpp"
#include "../../sensor.hpp"

namespace babu {

/**
 * @brief Controller implementation
 */
class Controller : public BaseModule, public IController {
  public:
    /**
     * @brief Default constructor
     *
     * @param[in] oSensor Sensor module instance
     * @param[in] oDisplay Frontend module instance
     */
    Controller(ISensor& oSensor, IFrontend& oFrontend);

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
    // frontend module instance
    IFrontend& m_oFrontend;

    // sensor module instance
    ISensor& m_oSensor;
};

} // namespace babu

#endif /* BABU_CONTROLLER_IMPLEMENTATION_HEADER */
