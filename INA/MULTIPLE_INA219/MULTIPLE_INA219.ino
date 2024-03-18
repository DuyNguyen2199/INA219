#include <Wire.h>
#include <Adafruit_INA219.h>
Adafruit_INA219 INA219_1 (0x40);//
Adafruit_INA219 INA219_2 (0x44);//

float tegangan_1, arus_1, daya_1;
float tegangan_2, arus_2, daya_2;

void setup(void) {
  Serial.begin(9600);
  INA219_1.begin();
  INA219_2.begin();
}

void loop(void) {

  tegangan_1 = INA219_1.getBusVoltage_V(); 
  arus_1 = INA219_1.getCurrent_mA(); 
  daya_1 = tegangan_1 * (arus_1 / 1000);

  tegangan_2 = INA219_2.getBusVoltage_V();
  arus_2 = INA219_2.getCurrent_mA(); 
  daya_2 = tegangan_2 * (arus_2 / 1000);

 // tegangan_3 = INA219_3.getBusVoltage_V(); 
 // arus_3 = INA219_3.getCurrent_mA(); 
 // daya_3 = tegangan_3 * (arus_3 / 1000);

  Serial.print("Tegangan 1 : ");  Serial.print(tegangan_1);  Serial.print(" Volt");
  Serial.print("\t\tArus 1 : ");  Serial.print(arus_1);      Serial.print(" mAmp");
  Serial.print("\t\tDaya 1 : ");  Serial.print(daya_1);      Serial.print(" Watt\n\n");

  Serial.print("Tegangan 2 : ");  Serial.print(tegangan_2);  Serial.print(" Volt");
  Serial.print("\t\tArus 2 : ");  Serial.print(arus_2);      Serial.print(" mAmp");
  Serial.print("\t\tDaya 2 : ");  Serial.print(daya_2);      Serial.print(" Watt\n\n");

 // Serial.print("Tegangan 3 : ");  Serial.print(tegangan_3);  Serial.print(" Volt");
 // Serial.print("\t\tArus 3 : ");  Serial.print(arus_3);      Serial.print(" mAmp");
 // Serial.print("\t\tDaya 3 : ");  Serial.print(daya_3);      Serial.print(" Watt\n\n");
  delay(2000); 
}
