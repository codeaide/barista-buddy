/**
 * @brief Controller implementation source file
 */

// includes
#include "controllerImpl.hpp"

// Default constructor
babu::Controller::Controller(ISensor& oSensor, IDisplay& oDisplay) : BaseModule("Controller"),
                                                                     m_oSensor(oSensor),
                                                                     m_oDisplay(oDisplay) {
}

// Method to initialize the module
bool babu::Controller::init() {
}

// Method to process the module
bool babu::Controller::process() {
  float currTemp = m_oSensor.getTemperature();
  m_oDisplay.displayTemperature(currTemp);
}
