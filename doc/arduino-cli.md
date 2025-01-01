# Arduino CLI

Developers could use Arduino CLI tool to create, compile, and upload Arduino sketches and manage Arduino compatible boards from the command line. This is useful for build automation and release.

## Core Platforms And Fully Qualified Board Names

The Arduino CLI uses core platforms and fully qualified board names when working with your Arduino boards. Core platforms (libraries) provide the necessary resources to utilize a specific category of boards within the Arduino ecosystem. They typically represent the vendors and microcontroller architectures of supported boards and are the libraries listed within the Boards Manager of the Arduino IDE. They are installed in the packages directory within the local user’s Arduino library or data folder for the following operating systems.

- Windows: C:\Users\\&lt;username>\AppData\Local\Arduino15\packages
- macOS: /Users/&lt;username>/Library/Arduino15/packages
- Linux: /home/&lt;username>/.arduino15/packages

Fully Qualified Board Names (FQBN) are board identifiers used for specifying individual boards with the Arduino CLI tool. The format for an FQBN is _&lt;package>:&lt;architecture>:&lt;board>_, where:

- &lt;package> is the vendor identifier, typically **arduino**
- &lt;architecture> is the microcontroller architecture, e.g., **avr**, **megaavr**, **renesas_uno**, **samd**, etc.
- &lt;board> is the board name defined by the core platform, e.g., **uno**, **uno2018**, **unor4wifi**, **nano**, etc.

The following are some example FQBN identifiers for popular UNO boards.

- arduino:avr:uno (Arduino UNO R3)
- arduino:megaavr:uno2018 (Arduino UNO WiFi Rev2)
- arduino:renesas_uno:unor4wifi (Arduino UNO R4 Wifi)

## Installing

On Ubuntu 24.04 (Noble Numbat), the Arduino CLI tool could be installed directly from SNAP.

```
sudo snap install arduino-cli
```

## Commands

### Version Check

```
$ arduino-cli version
```

### Managing Core Platforms

Issue the command below to manually check for updates and upgrades of core platforms and libraries.

```
$ arduino-cli update
```

Once the indexes have been updated, we can show and upgrade the outdated cores and libraries with the following commands.

```
$ arduino-cli outdated
$ arduino-cli upgrade
```

The following command lists the platform cores that have been installed on your system.

```
$ arduino-cli core list
```

Platform cores can also be searched and installed using the CLI tool.

```
$ arduino-cli core search uno
$ arduino-cli core install arduino:renesas_uno
```

Version of platform core can be explicitly specified as shown below.

```
$ arduino-cli core install arduino:avr@1.8.6
```

The command below lists all Arduino boards connected to the computer.

```
$ arduino-cli board list
```

### Managing Libraries

The following command lists the installed libraries.

```
$ arduino-cli lib list
```

Libraries can be searched and installed using the CLI tool.

```
$ arduino-cli lib search LedControl
$ arduino-cli lib install LedControl
```

Specific library versions can also be installed using the CLI tool.

```
$ arduino-cli lib install LedControl@1.0.6
```

### Compiling Sketches

From the sketch directory, issue the following command to build it,  replacing the &lt;fqbn> placeholder with the appropriate one for your board.

```
$ arduino-cli compile --fqbn <fqbn>
```

For example the command below is used for Arduino UNO R4 Wifi.

```
$ arduino-cli compile --fqbn arduino:renesas_uno:unor4wifi
```

### Running Sketches

Compiled sketch can be uploaded to the board using the command below.

```
$ arduino-cli upload --fqbn <fqbn> --port <port>
```

The below command uploads the sketch to the Arduino UNO R3 over /dev/ttyACM0.

```
$ arduino-cli upload --fqbn arduino:avr:uno --port /dev/ttyACM0
```

### Monitoring Serial Output

The serial output can be monitored using the command below. The default baudrate is 9600.

```
$ arduino-cli monitor --port <port> --config baudrate=115200
```