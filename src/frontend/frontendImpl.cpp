/**
 * @brief Frontend implementation source file
 */

// includes
#include "frontendImpl.hpp"

// LED ON/OFF sequence for digits
const byte babu::Frontend::LED_SEQ_N0[8] = {B01111000,B11001100,B11011100,B11111100,B11101100,B11001100,B01111000,B00000000};
const byte babu::Frontend::LED_SEQ_N1[8] = {B00110000,B01110000,B00110000,B00110000,B00110000,B00110000,B11111100,B00000000};
const byte babu::Frontend::LED_SEQ_N2[8] = {B01111000,B11001100,B00001100,B00111000,B01100000,B11001100,B11111100,B00000000};
const byte babu::Frontend::LED_SEQ_N3[8] = {B01111000,B11001100,B00001100,B00111000,B00001100,B11001100,B01111000,B00000000};
const byte babu::Frontend::LED_SEQ_N4[8] = {B00011100,B00111100,B01101100,B11001100,B11111110,B00001100,B00011110,B00000000};
const byte babu::Frontend::LED_SEQ_N5[8] = {B11111100,B11000000,B11111000,B00001100,B00001100,B11001100,B01111000,B00000000};
const byte babu::Frontend::LED_SEQ_N6[8] = {B00111000,B01100000,B11000000,B11111000,B11001100,B11001100,B01111000,B00000000};
const byte babu::Frontend::LED_SEQ_N7[8] = {B11111100,B11001100,B00001100,B00011000,B00110000,B00110000,B00110000,B00000000};
const byte babu::Frontend::LED_SEQ_N8[8] = {B01111000,B11001100,B11001100,B01111000,B11001100,B11001100,B01111000,B00000000};
const byte babu::Frontend::LED_SEQ_N9[8] = {B01111000,B11001100,B11001100,B01111100,B00001100,B00011000,B01110000,B00000000};

// abstract array
const byte* babu::Frontend::LED_SEQUENCES[] = {
  babu::Frontend::LED_SEQ_N0,
  babu::Frontend::LED_SEQ_N1,
  babu::Frontend::LED_SEQ_N2,
  babu::Frontend::LED_SEQ_N3,
  babu::Frontend::LED_SEQ_N4,
  babu::Frontend::LED_SEQ_N5,
  babu::Frontend::LED_SEQ_N6,
  babu::Frontend::LED_SEQ_N7,
  babu::Frontend::LED_SEQ_N8,
  babu::Frontend::LED_SEQ_N9
};

// Default constructor
babu::Frontend::Frontend(int pinDIN, int pinCLK, int pinCS, int nDevices) : BaseModule("Frontend"),
                                                                            m_oLedCtrl(pinDIN, pinCLK, pinCS, nDevices) {
}

// Method to initialize the module
bool babu::Frontend::init() {
  // the MAX72XX is in power-saving mode on startup
  // we have to do a wakeup call

  // we have already set the number of devices
  // when we created the LedControl object
  int nDevices = m_oLedCtrl.getDeviceCount();

  // initialize all devices
  for(int iDevice=0;iDevice<nDevices;iDevice++)
  {
    // the MAX72XX is in power-saving mode on startup
    m_oLedCtrl.shutdown(iDevice,false);
    // set the brightness to a medium values
    m_oLedCtrl.setIntensity(iDevice, 1);
    // clear the display
    m_oLedCtrl.clearDisplay(iDevice);
  }

  return true;
}

// Implementation of interface to display the temperature
void babu::Frontend::displayTemperature(float tempValue) {
  int roundVal = -1;
  bool bDecimalAtEnd = false;

  // cast the value to integer that can be represented
  if(tempValue < 999.f) {
    roundVal = static_cast<int>(tempValue * 10.f);
  } else {
    roundVal = static_cast<int>(tempValue * 1.f);
    bDecimalAtEnd = true;
  }

  // setup the LED sequence to be displayed
  const byte* LED_SEQ_TEMP[4] = { nullptr, nullptr, nullptr, nullptr };

  int dividentVal = roundVal;
  int divisorVal = 1000;

  // extract parts one by one
  for (int iCount = 0; iCount < 4 ; iCount++) {
    // get the quotient anv remainder
    int quotientVal = dividentVal / divisorVal;
    //int remainderVal = dividentVal % divisorVal;

    // get the LED sequence for the current digit
    LED_SEQ_TEMP[iCount] = LED_SEQUENCES[quotientVal];

    // remove the digit from left
    dividentVal = dividentVal - (quotientVal * divisorVal);

    // update the divisor
    divisorVal /= 10;
  }

  // setup LED rows
  for (int iRow = 0;iRow < 8;iRow++) {
    m_oLedCtrl.setRow(3, iRow, LED_SEQ_TEMP[0][iRow]);
    m_oLedCtrl.setRow(2, iRow, LED_SEQ_TEMP[1][iRow]);
    m_oLedCtrl.setRow(1, iRow, LED_SEQ_TEMP[2][iRow]);
    m_oLedCtrl.setRow(0, iRow, LED_SEQ_TEMP[3][iRow]);
  }

  // show decimal point
  if (bDecimalAtEnd) {
    m_oLedCtrl.setLed(0, 7, 7, true);
  } else {
    m_oLedCtrl.setLed(1, 7, 7, true);
  }
}
