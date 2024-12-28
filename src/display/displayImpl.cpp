/**
 * @brief Display implementation source file
 */

// includes
#include "displayImpl.hpp"

/* LED data for the digits */
constexpr byte num0[8] = {B01111000,B11001100,B11011100,B11111100,B11101100,B11001100,B01111000,B00000000};
constexpr byte num1[8] = {B00110000,B01110000,B00110000,B00110000,B00110000,B00110000,B11111100,B00000000};
constexpr byte num2[8] = {B01111000,B11001100,B00001100,B00111000,B01100000,B11001100,B11111100,B00000000};
constexpr byte num3[8] = {B01111000,B11001100,B00001100,B00111000,B00001100,B11001100,B01111000,B00000000};
constexpr byte num4[8] = {B00011100,B00111100,B01101100,B11001100,B11111110,B00001100,B00011110,B00000000};
constexpr byte num5[8] = {B11111100,B11000000,B11111000,B00001100,B00001100,B11001100,B01111000,B00000000};
constexpr byte num6[8] = {B00111000,B01100000,B11000000,B11111000,B11001100,B11001100,B01111000,B00000000};
constexpr byte num7[8] = {B11111100,B11001100,B00001100,B00011000,B00110000,B00110000,B00110000,B00000000};
constexpr byte num8[8] = {B01111000,B11001100,B11001100,B01111000,B11001100,B11001100,B01111000,B00000000};
constexpr byte num9[8] = {B01111000,B11001100,B11001100,B01111100,B00001100,B00011000,B01110000,B00000000};

// Default constructor
babu::Display::Display(int pinDIN, int pinCLK, int pinCS, int nDevices) : BaseModule("Display"),
                                                                          m_oLedCtrl(pinDIN, pinCLK, pinCS, nDevices) {
}

// Method to initialize the module
bool babu::Display::init() {
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

// Method to process the module
bool babu::Display::process() {
  /* setup LED rows */
  for (int iRow = 0;iRow < 8;iRow++)
  {
    m_oLedCtrl.setRow(3,iRow,num1[iRow]);
    m_oLedCtrl.setRow(2,iRow,num2[iRow]);
    m_oLedCtrl.setRow(1,iRow,num3[iRow]);
    m_oLedCtrl.setRow(0,iRow,num4[iRow]);
  }
}
