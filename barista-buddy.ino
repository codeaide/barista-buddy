void setup() {
  // initialize serial and wait for port to open
  Serial.begin(115200);

  // wait for serial port to connect. needed for native USB port only
  while (!Serial);

  // set the LED pin mode
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println("==================================================");
  Serial.println("                   Brew Barista                   ");
  Serial.println("==================================================");
}

void loop() {
  Serial.println("Running...");

  delay(1000);
}
