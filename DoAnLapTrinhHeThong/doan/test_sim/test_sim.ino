#include <SoftwareSerial.h>
#include <TinyGPS++.h>   
#include <kien800.h>
float latitude=1.123213, longitude=123.12312;
const int PWR_KEY = 8;
SoftwareSerial ModuleSerial(6,5); //A6 Tx & Rx is connected to Arduino #5 & #4

String tin_nhan="";

void setup()
{
   pinMode(7, OUTPUT);
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor) 
  //Begin serial communication with Arduino and A6
  digitalWrite(7,HIGH);
  ModuleSerial.begin(9600);
  Serial.begin(9600);
  Serial.println("Initializing..."); 
  delay(1000);
  //sendSMS(latitude,longitude);
  //ModuleSerial.println("AT+CMGDA=\"DEL ALL\"");
  //delay(1000);
//  ModuleSerial.println("AT+CMGF=1r"); //Lệnh này đưa tin nhắn về dạng text, phải có lệnh này mới đọc, gửi tin nhắn dạng text đc nhé :)
//  delay(1000);
//  ModuleSerial.println("AT+CNMI=2,1,0,0,0r"); //Hiển thị ngay nếu tin nhắn gửi đến
//  delay(1000);
//   while (!initSIM(6, 5, 9600)) {
//        Serial.println("Init error!");
//        delay(1000);
//      }
//
//  ModuleSerial.println("AT+CMGDA=\"DEL ALL\"");
//  delay(500);
  Serial.println("Initialized");
  ModuleSerial.println("AT");
  delay(1000);
  ModuleSerial.println("AT+CMGF=1");
  delay(200);
  ModuleSerial.println("AT+CMGS=\"+84977694163\"\r");
  delay(200);
  ModuleSerial.print(latitude,6);
  delay(100);
  ModuleSerial.print(",");
  delay(100);
  ModuleSerial.print(longitude,6);
  delay(200);
  ModuleSerial.println((char)26);
  delay(200);
  //Serial.println("send sms access");
  delay(1000);
  
}

void loop()
{
// String tin_nhan =   wait_for_resp();
//  Serial.print("Result : ");
//  Serial.print(tin_nhan);
  if (tin_nhan.length() > 0) {
      Serial.println(tin_nhan);
      if (tin_nhan == "chec") {
          digitalWrite(7,LOW);
      }
      tin_nhan = "";
  }

  
}


//String wait_for_resp()
//{
//    String result = "";
//    unsigned long timerStart, prevChar = 0;
//    timerStart = millis();
//    while (1)
//    {
//        if (ModuleSerial.available())
//        {
//            char c = ModuleSerial.read();
//            prevChar = millis();
//            result += c;
//        }
//        if ((unsigned long)(millis() - timerStart) > 1 * 5000UL)
//        {
//            break;
//        }
//        if (((unsigned long)(millis() - prevChar) > 3000) && (prevChar != 0))
//        {
//            return false;
//        }
//    }
//    return result;
//}
void sendSMS(float latitude, float longitude){
  ModuleSerial.println("AT");
  delay(1000);
  ModuleSerial.println("AT+CMGF=1");
  delay(200);
  ModuleSerial.println("AT+CMGS=\"+84977694163\"\r");
  delay(200);
  ModuleSerial.print(latitude,6);
  delay(100);
  ModuleSerial.print(",");
  delay(100);
  ModuleSerial.print(longitude,6);
  delay(200);
  ModuleSerial.println((char)26);
  delay(200);
  Serial.println("send sms access");
  delay(1000);
}

void readSMS(){ 
  ModuleSerial.println("AT"); //Once the handshake test is successful, it will back to OK
 // updateSerial(); 
  ModuleSerial.println("AT+CMGF=1");
 // updateSerial();
  ModuleSerial.println("AT+CMGL=\"REC UNREAD\",1"); // Configuring TEXT mode
 // updateSerial();
  String tin_nhan = tinnhan();
  Serial.print("result : = ");
  //updateSerial();
  Serial.println(tin_nhan);
//  updateSerial();
//  if(tin_nhan.indexOf("CMGR") == -1) return false;
//  int first = tin_nhan.indexOf("UNREAD") +9;
//  int last = tin_nhan.indexOf("\"",first); 
//
//return true;
}

//void updateSerial()
//{
//  delay(500);
//  while (Serial.available()) 
//  {
//    ModuleSerial.write(Serial.read());//Forward what Serial received to Software Serial Port
//  }
//  while(ModuleSerial.available()) 
//  {
//    Serial.write(ModuleSerial.read());//Forward what Software Serial received to Serial Port
//  }
//}

void Gsm_Power_On()
{
  digitalWrite(PWR_KEY, HIGH);                // Du chan PWR_KEY len cao it nhat 1s 
  delay(1500);                                            // o day ta de 1,5s
  digitalWrite(PWR_KEY, LOW);                  // Du chan PWR_KEY xuong thap
  delay(100);                                              // cac ban xem trong Hardware designed sim800C de hieu ro hon
}

String tinnhan(){
  String result="check";
  unsigned long timerStart, prevChar = 0;
  timerStart = millis();
  while(1){
    if(ModuleSerial.available()){
    char c = ModuleSerial.read();
    result+=c;
        }
     if ((unsigned long)(millis() - timerStart) > 1 * 1000UL)
          {
              break;
          }
      if (((unsigned long)(millis() - prevChar) > 500) && (prevChar != 0))
      {
          return false;
      }
  }
  return result;
}
