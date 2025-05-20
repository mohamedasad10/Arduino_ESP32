/*
  📡 ESP32 + AHT20 Sensor (Temperature & Humidity)
  This sketch reads temperature and humidity data from a DFRobot AHT20 sensor and prints the results to the Serial Monitor.

  What it does:
  - Initializes the AHT20 sensor
  - Continuously reads:
    - Temperature in Celsius and Fahrenheit
    - Relative Humidity (%RH)
  - Outputs the values every 5 seconds

  Wiring (ESP32 <-> AHT20 via I2C):
  - VCC  -> 3.3V
  - GND  -> GND
  - SDA  -> GPIO 21 (default I2C SDA on ESP32)
  - SCL  -> GPIO 22 (default I2C SCL on ESP32)

  */

#include "DFRobot_AHT20.h"

DFRobot_AHT20 aht20;

void setup(){
  Serial.begin(115200);
  uint8_t status;
  while((status = aht20.begin()) != 0){
    Serial.print("AHT20 sensor initialization failed. error status : ");
    Serial.println(status);
    delay(1000);
  }
}

void loop(){
  if(aht20.startMeasurementReady(/* crcEn = */true)){
    Serial.print(aht20.getTemperature_C());
    Serial.print(" C, ");
    // Get temp in Fahrenheit (F)
    Serial.print(aht20.getTemperature_F());
    Serial.print(" F\t");
    Serial.print(aht20.getHumidity_RH());
    Serial.println(" %RH");
    delay(5000);
  }
}
