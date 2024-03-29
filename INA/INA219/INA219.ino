#include <Wire.h>
#include <Adafruit_INA219.h>
const int INA_addr = 0x40;  // INA219 address
Adafruit_INA219 ina219(INA_addr);

float tegangan;
float arus; // diukur menggunakan MiliAmpere
float daya;

void setup(void) {
  Serial.begin(9600);
  ina219.begin();
}

void loop(void) {

  tegangan = ina219.getBusVoltage_V(); //command untuk pembacaan tegangan
  arus = ina219.getCurrent_mA(); //command untuk pembacaan arus
  daya = tegangan * (arus / 1000); //rumus untuk mendapatkan nilai watt

  Serial.print("Tegangan : ");
  Serial.print(tegangan);
  Serial.println(" Volt");
  Serial.print("Arus : ");
  Serial.print(arus);
  Serial.println(" mAmp");
  Serial.print("Daya : ");
  Serial.print(daya);
  Serial.println(" Watt");

  Serial.println("");
  delay(2000); 
}
