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

/**
 * @brief Setup code that runs once during startup
 */
void setup() {
  // initialize serial and wait for port to open
  Serial.begin(115200);

  // wait for serial port to connect. needed for native USB port only
  while (!Serial);

  // set the LED pin mode
  pinMode(LED_BUILTIN, OUTPUT);

  // initialize display module
  if (!oDisplay.init())
  {
    Serial.println("Failed to initialize display module!");
  }

  // initialize measurement module
  if (!oMeas.init())
  {
    Serial.println("Failed to initialize measurement module!");
  }

  // initialize relay module
  if (!oRelay.init())
  {
    Serial.println("Failed to initialize relay module!");
  }

  // initialize sensor module
  if (!oSensor.init())
  {
    Serial.println("Failed to initialize sensor module!");
  }

  // finally initialize controller module
  if (!oController.init())
  {
    Serial.println("Failed to initialize controller module!");
  }

  Serial.println("==================================================");
  Serial.println("                   Brew Barista                   ");
  Serial.println("==================================================");
}

/**
 * @brief Code that runs cyclically
 */
void loop() {
  Serial.println("Running...");

  delay(1000);
}
