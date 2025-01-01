# Display Module

## MAX7219 Dot Matrix LED Display

The MAX7219 includes an 8×8 dot matrix display and a MAX7219 LED display driver. MAX7219 communicates via the SPI interface and requires only 3 pins to connect to a microcontroller. In addition, the same 3 wires allows daisy-chaining multiple modules together for a larger display. The standard pins of the MAX7219 are described below.

| PIN | Description                             | Arduino PIN |
| --- | --------------------------------------- | ----------- |
| VCC | Connected to 5V                         |             |
| GND | Ground Pin                              |             |
| DIN | Data Pin                                | 11 (MOSI)   |
| CS  | Chip Select (sometimes labeled as LOAD) | 10 (SS)     |
| CLK | Clock Pin                               | 12 (MISO    |

Note - The dot matrix display draws a lot of current (up to 1A at maximum brightness). Therefore it’s best to use an external power supply instead of the Arduino’s 5V supply. Please keep the brightness below 25% to avoid overheating the voltage regulator if Arduino’s 5V supply is used.

## Dependencies

### LedControl

[LedControl](https://github.com/wayoda/LedControl) is used to interface the MAX7219 8x32 dot matrix display.
