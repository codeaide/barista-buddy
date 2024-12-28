/**
 * @brief Display implementation source file
 */

// includes
#include "displayImpl.hpp"

// LED ON/OFF sequence for digits
constexpr byte LED_SEQ_N0[8] = {B01111000,B11001100,B11011100,B11111100,B11101100,B11001100,B01111000,B00000000};
constexpr byte LED_SEQ_N1[8] = {B00110000,B01110000,B00110000,B00110000,B00110000,B00110000,B11111100,B00000000};
constexpr byte LED_SEQ_N2[8] = {B01111000,B11001100,B00001100,B00111000,B01100000,B11001100,B11111100,B00000000};
constexpr byte LED_SEQ_N3[8] = {B01111000,B11001100,B00001100,B00111000,B00001100,B11001100,B01111000,B00000000};
constexpr byte LED_SEQ_N4[8] = {B00011100,B00111100,B01101100,B11001100,B11111110,B00001100,B00011110,B00000000};
constexpr byte LED_SEQ_N5[8] = {B11111100,B11000000,B11111000,B00001100,B00001100,B11001100,B01111000,B00000000};
constexpr byte LED_SEQ_N6[8] = {B00111000,B01100000,B11000000,B11111000,B11001100,B11001100,B01111000,B00000000};
constexpr byte LED_SEQ_N7[8] = {B11111100,B11001100,B00001100,B00011000,B00110000,B00110000,B00110000,B00000000};
constexpr byte LED_SEQ_N8[8] = {B01111000,B11001100,B11001100,B01111000,B11001100,B11001100,B01111000,B00000000};
constexpr byte LED_SEQ_N9[8] = {B01111000,B11001100,B11001100,B01111100,B00001100,B00011000,B01110000,B00000000};

// abstract array
constexpr byte* LED_SEQUENCES[] = {
  LED_SEQ_N0,
  LED_SEQ_N1,
  LED_SEQ_N2,
  LED_SEQ_N3,
  LED_SEQ_N4,
  LED_SEQ_N5,
  LED_SEQ_N6,
  LED_SEQ_N7,
  LED_SEQ_N8,
  LED_SEQ_N9,
};

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

// Implementation of interface to display the temperature
void babu::Display::displayTemperature(float tempValue) {
  int roundVal = -1;
  bool decimalAtEnd = false;

  // cast the value to integer that can be represented
  if(tempValue < 999.f) {
    roundVal = static_cast<int>(tempValue * 10.f);
  } else {
    roundVal = static_cast<int>(tempValue * 1.f);
    decimalAtEnd = true;
  }

  // setup the LED sequence to be displayed
  byte* LED_SEQ_TEMP[4] = { nullptr, nullptr, nullptr, nullptr };

  int dividentVal = roundVal;
  int divisorVal = 1000;

  // extract parts one by one
  for (int iCount = 0; iCount < 4 ; iCount++) {
    // get the quotient anv remainder
    int quotientVal = dividentVal / divisorVal;
    int remainderVal = dividentVal % divisorVal;

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
}
