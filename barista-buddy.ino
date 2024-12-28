// includes
#include "src/controller/controllerImpl.hpp"
#include "src/display/displayImpl.hpp"
#include "src/measurement/measurementImpl.hpp"
#include "src/relay/relayImpl.hpp"
#include "src/sensor/sensorImpl.hpp"

// display instance
babu::Display oDisplay;

// measurement instance
babu::Measurement oMeas;

// relay instance
babu::Relay oRelay;

// sensor instance
babu::Sensor oSensor;

// the controller instance
babu::Controller oController;

// module array
#define NUM_MODULES (sizeof(oModules) / sizeof(babu::BaseModule*))
babu::BaseModule* oModules[] = {
  &oDisplay,
  &oMeas,
  &oRelay,
  &oSensor,
  &oController,
};

/**
 * @brief Setup code that runs once during startup
 */
void setup() {
  // initialize serial and wait for port to open
  Serial.begin(115200);

  // wait for serial port to connect. needed for native USB port only
  while (!Serial);

  Serial.println("==================================================");
  Serial.println("                   Brew Barista                   ");
  Serial.println("==================================================");

  // set the LED pin mode
  pinMode(LED_BUILTIN, OUTPUT);

  // loop through all available modules
  for (int iIndex = 0; iIndex < NUM_MODULES ; iIndex++) {
    // initialize module
    if (!oModules[iIndex]->init()) {
      Serial.println("Failed to initialize \"" + oModules[iIndex]->getName() + "\" module!");
    }
  }
}

/**
 * @brief Code that runs cyclically
 */
void loop() {
  Serial.println("Running...");

  // loop through all available modules
  for (int iIndex = 0; iIndex < NUM_MODULES ; iIndex++) {
    // process module
    if (!oModules[iIndex]->process()) {
      Serial.println("Failed to process \"" + oModules[iIndex]->getName() + "\" module!");
    }
  }

  delay(1000);
}
