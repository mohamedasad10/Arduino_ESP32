/****
Description:
  This sketch reads the ambient light level using a light-dependent resistor (LDR) connected 
  to GPIO 36 on the ESP32. The analog values are printed to the Serial Monitor to show 
  how light intensity changes over time.
****/

const int sensorPin = 36;
 
void setup()
{
  Serial.begin(115200);
}
 
void loop()
{
    int analogVal = analogRead(sensorPin);
     
    Serial.println(analogVal);
    delay(200);
}
