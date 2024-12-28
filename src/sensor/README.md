# Sensor Module

## DS18B20

DS18B20 is a 1-Wire® temperature sensor manufactured by Dallas Semiconductor (acquired by Maxim Integrated). Being a 1-wire device, it only needs one digital pin to communicate with the microcontroller. The DS18B20 has a temperature range of -55°C to +125°C and an accuracy of ±0.5°C. The temperature sensor’s resolution can be set to 9, 10, 11, or 12 bits. By default the resolution is set to 12-bit during power-up (i.e., 0.0625°C precision).

| PIN | Description      | Arduino PIN |
| --- | ---------------- | ----------- |
| VDD | Connected to 5V  |             |
| GND | Ground Pin       |             |
| DQ  | 1-Wire Data Bus  | 2           |

Note: To keep the data transfer stable, a 4.7k pull-up resistor is needed between the signal and power pins. Internal pull-ups on the Arduino won't work.

## Dependencies

### DallasTemperature

[DallasTemperature](https://docs.arduino.cc/libraries/dallastemperature/) library for talking to DS18B20 temperature sensor. It is a hardware-specific library that handles lower-level functions. The library abstracts communication complexity exposing simple commands to obtain temperature readings from the sensor.

### OneWire

[OneWire](https://github.com/PaulStoffregen/OneWire) provides access to 1-wire devices made by Maxim/Dallas.
