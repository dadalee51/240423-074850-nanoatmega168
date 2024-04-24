/* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

The range readings are in units of mm. */
#include <Arduino.h>
#include <Wire.h>
#include <VL53L0X.h>
//#include <MemoryUsage.h>
VL53L0X sensor;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous(100);
  // MEMORY_PRINT_START
  // MEMORY_PRINT_HEAPSTART
  // MEMORY_PRINT_HEAPEND
  // MEMORY_PRINT_STACKSTART
  // MEMORY_PRINT_END
  // MEMORY_PRINT_HEAPSIZE
  // FREERAM_PRINT;

}

void loop()
{
  Serial.print(sensor.readRangeContinuousMillimeters());
  if (sensor.timeoutOccurred()) Serial.print(" TIMEOUT");
  Serial.println();
 

}
