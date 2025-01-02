/**
 * @brief Controller implementation source file
 */

// includes
#include "controllerImpl.hpp"

// Default constructor
babu::Controller::Controller(ISensor& oSensor, IFrontend& oFrontend) : BaseModule("Controller"),
                                                                       m_oFrontend(oFrontend),
                                                                       m_oSensor(oSensor) {
}

// Method to initialize the module
bool babu::Controller::init() {
  return true;
}

// Method to process the module
bool babu::Controller::process() {
  float currTemp = m_oSensor.getTemperature();
  m_oFrontend.displayTemperature(currTemp);

  return true;
}
