#include <TinyGPS++.h>
#include <SoftwareSerial.h>
int btn = 7;
int thoigian, khoangcach;
unsigned long times;


static const int RXGPS = 3, TXGPS = 2; // chan tx - 3, rx - 2
static const int pinRxA6 = 5;// chan tx - 5
static const int pinTxA6 = 4;// chan rx - 4
static const uint32_t Baud = 9600;
float latitude = 51.508131, longitude = -0.128002;


TinyGPSPlus gps;
SoftwareSerial GPSSerial(11, 10);
SoftwareSerial ModuleSerial(6, 5);

void setup() {
  ModuleSerial.begin(9600);
  Serial.begin(9600);
  GPSSerial.begin(Baud);
  times =millis();
  pinMode(btn,INPUT);
}

void loop() {
            while (GPSSerial.available() > 0)
            {
          
              if (gps.encode(GPSSerial.read()))
              {
                if (gps.location.isValid())
                {
                  Serial.print(gps.location.lat(), 6);
                  Serial.print(F(","));
                  Serial.print(gps.location.lng(), 6);
                  Serial.println();
                  if((unsigned long) (millis()- times) >10000){
                      latitude = gps.location.lat();
                      longitude = gps.location.lng();
                      //sendSMS(latitude, longitude);
                      times = millis();
                   }
                }
                else {
                  Serial.print(F("INVALID"));
                  Serial.println();
          
                }
          
              }
          
            }
           // sieuam();
}
void sendSMS(float latitude, float longitude) {
  ModuleSerial.println("AT");
  updateSerial();
  ModuleSerial.println("AT+CMGF=1");
  updateSerial();
  ModuleSerial.println("AT+CMGS=\"+84977694163\"");
  updateSerial();
  ModuleSerial.print("http://maps.google.com/maps?q=");
  ModuleSerial.print(latitude, 6);
  ModuleSerial.print(",");
  ModuleSerial.print(longitude, 6);
  ModuleSerial.print("&t=m&z=36\n\r");
  updateSerial();
  ModuleSerial.write(26);
  Serial.println("send sms access");
}

void readSMS() {
  ModuleSerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  ModuleSerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  ModuleSerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  ModuleSerial.println("AT+CNMI=2,2");
  updateSerial();
}

void updateSerial()
{
  delay(60);
  while (Serial.available())
  {
    ModuleSerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while (ModuleSerial.available())
  {
    Serial.write(ModuleSerial.read());//Forward what Software Serial received to Serial Port
  }
}
//
//void sieuam() {
//  digitalWrite(TRIG_PIN, LOW);
//  delayMicroseconds(2);
//  digitalWrite(TRIG_PIN, HIGH);
//  delayMicroseconds(5);
//  digitalWrite(TRIG_PIN, LOW);
//  //ĐO KHOẢNG CÁCH
//  thoigian = pulseIn(ECHO_PIN, HIGH); //lay gia tri thoi gian tu chan echo
//  khoangcach = 0.03432 * (thoigian / 2); //cong thuc tinh khoang cach, s=v*t
//  Serial.print(khoangcach);
//  Serial.println("cm");
//
//  //BẬT TẮT CÒI BÁO
//  if (khoangcach < 50) {
//    digitalWrite(Buzzer, HIGH);
//    delay(20);
//    digitalWrite(Buzzer, LOW);
//  }
//  else {
//    digitalWrite(Buzzer, LOW);
//  }
//
//  delay(50);

  // quang trở điều khiển đèn sáng
  //Serial.println(val);
  //val=analogRead(potpin);
  //if(val<100){
  //            digitalWrite(BluePin, HIGH);
  //            //digitalWrite(RedPin, HIGH);
  //            if(khoangcach<50){
  //               digitalWrite(RedPin, HIGH);
  //               delay(20);
  //               digitalWrite(RedPin,LOW);
  //            }
  //}
  //else {
  //   digitalWrite(RedPin, LOW );
  //    digitalWrite(BluePin, LOW );
  //}
//}
