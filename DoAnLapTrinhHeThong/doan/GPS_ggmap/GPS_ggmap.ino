#include <SoftwareSerial.h>
#include <TinyGPS++.h>   
const int btn = 12;

//static const int RXGPS = 11, TXGPS = 10; // chan tx - 3, rx - 2
//static const int pinRxA6 = 6;// chan tx - 5
//static const int pinTxA6 = 5;// chan rx - 4
float latitude = 51.508131, longitude = -0.128002;
//Create software serial object to communicate with A6

TinyGPSPlus gps;
SoftwareSerial GPSSerial(11, 10);
SoftwareSerial ModuleSerial(6,5); //A6 Tx & Rx is connected to Arduino #5 & #4


String lati="51.508131",longi="-0.128002",ggmap= "https://www.google.com/maps/?q="+lati+","+longi+"&t=m&z=36\n\r";

void setup() {

      pinMode(btn,INPUT);
           
      ModuleSerial.begin(9600);
      GPSSerial.begin(9600);
      Serial.begin(9600);
        if (gps.location.isValid()){
          delay(1000);
          latitude  = gps.location.lat();
          longitude = gps.location.lng();
          delay(1000);
          ModuleSerial.println("AT");
          delay(1000);
          ModuleSerial.println("AT+CMGF=1");
          delay(500);
          ModuleSerial.println("AT+CMGS=\"+84977694163\"\r");
          delay(500);
          ModuleSerial.print("https://www.google.com/maps/?q=");
          delay(500);
          ModuleSerial.print(latitude,6);
          delay(500);
          ModuleSerial.print(",");
          delay(500);
          ModuleSerial.print(longitude,6);
          delay(500);
           ModuleSerial.print("&t=m&z=36\n\r");
           delay(500);
          ModuleSerial.println((char)26);
          delay(500);
          Serial.println("send sms access");
          delay(1000);
        }
      
}

void loop() {
//           int btn_click = digitalRead(btn);
//           Serial.println(btn_click);
//  A:
//           if(btn_click == HIGH)
//           { 
//            delay(500);
                while (GPSSerial.available() > 0)
                {
                  delay(100);
                  if (gps.encode(GPSSerial.read()))
                  {
                    if (gps.location.isValid())
                    {
                      lati  = String((gps.location.lat(), 6));
                      longi = String((gps.location.lng(), 6));
                      ggmap= "https://www.google.com/maps/?q="+lati+","+longi+"&t=m&z=36\n\r";
                      Serial.println(ggmap);

//                      latitude  = gps.location.lat();
//                      longitude = gps.location.lng();
//                      delay(1000);
//                      ModuleSerial.println("AT");
//                      delay(1000);
//                      ModuleSerial.println("AT+CMGF=1");
//                      delay(500);
//                      ModuleSerial.println("AT+CMGS=\"+84977694163\"\r");
//                      delay(500);
//                      ModuleSerial.print("https://www.google.com/maps/?q=");
//                      delay(500);
//                      ModuleSerial.print(latitude,6);
//                      delay(500);
//                      ModuleSerial.print(",");
//                      delay(500);
//                      ModuleSerial.print(longitude,6);
//                      delay(500);
//                       ModuleSerial.print("&t=m&z=36\n\r");
//                       delay(500);
//                      ModuleSerial.println((char)26);
//                      delay(500);
//                      //Serial.println("send sms access");
//                      delay(1000);
//                      btn_click = LOW;
//                      goto A;
                    }
                    else {
                      
//                       delay(1000);
//                        ModuleSerial.println("AT");
//                        delay(1000);
//                        ModuleSerial.println("AT+CMGF=1");
//                        delay(500);
//                        ModuleSerial.println("AT+CMGS=\"+84977694163\"\r");
//                        delay(500);
//                        ModuleSerial.println("NO GPS");
//                        delay(500);
//                        ModuleSerial.println((char)26);
//                        delay(1000);
//                        btn_click = LOW;
                     // Serial.print(F("INVALID"));
                     // Serial.println();
                      //goto A;
                      Serial.println("no gps");
                    }
              
                  }
              
                }
           //}

}

void sendSMS(String latitude, String longitude){
  ModuleSerial.println("AT");
  delay(1000);
  ModuleSerial.println("AT+CMGF=1");
  delay(100);
  ModuleSerial.println("AT+CMGS=\"+84977694163\"");
  delay(100);
  ModuleSerial.println(ggmap);
  delay(100);
  ModuleSerial.println((char)26);
  delay(1000);
}

void readSMS() {
  ModuleSerial.println("AT"); //Once the handshake test is successful, it will back to OK
//  updateSerial();
  ModuleSerial.println("AT+CMGF=1"); // Configuring TEXT mode
  //updateSerial();
  //ModuleSerial.println("AT+CMGL=REC UNREAD");
  ModuleSerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
 // ModuleSerial.println("AT+CNMI=2,2");
 // updateSerial();
}
