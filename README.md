# Barista Buddy

Barista Buddy is an Arduino based project for controlling the temperature of SBDU (Single Boiler Dual Use) espresso machines without PID. This is not yet another Arduino based PID controller but a simple companion to monitor the temperature and configure it using a smartphone without any physical buttons, displays or knobs.

Please check out my [motivation](doc/motivation.md) for this project.

## Working Principle

Barista Buddy is simple and straightforward. A temperature sensor mounted externally on the boiler measures the surface temperature and supplies it to the controller. The controller compares the current boiler temperature to a set temperature and control a relay, which in turn activate/deactivate the heating element.

The control mechanism does not employ a PID logic but a simple [Bang-bang Control](https://en.wikipedia.org/wiki/Bang%E2%80%93bang_control) logic. Few reasons for chosing this logic are listed below.

1. **Simplicity** - PIDs requires parameter calibration in a proper setting whereas Bang-bang control simply switches between two states.
1. **Speed** - Bang-bang control will always try to reach the setpoint as fast as possible making use of maximum power.
1. **Error Margin** - Bang-bang control will heat up fast at the cost of accuracy. It might be an issue for industrial application but faster sensing and processing could reduce this error to make it acceptable for home applications.
1. **Stress Factor** - PIDs apply slow switching compared to Bang-bang. When switching slow, components have time to heat up and cool down on each cycle, which causes thermal expansion and contraction cycles and mechanical stress. Switching much faster keeps components at a constant (average) temperature and avoids thermal cycling.
