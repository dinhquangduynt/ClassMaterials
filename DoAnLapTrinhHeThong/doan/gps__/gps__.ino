#include <TinyGPS++.h>
#include <SoftwareSerial.h>
// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(11, 10);

void setup(){
  Serial.begin(9600);
  ss.begin(9600);
}

void loop(){
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
   // gps.encode(ss.read());
   if (gps.location.isValid()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
   }
   delay(500);
  }
}
