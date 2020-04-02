#include <SoftwareSerial.h>
#include <TinyGPS++.h>   
String latitude="1.123213", longitude="123.12312";
const int PWR_KEY = 8;
SoftwareSerial ModuleSerial(3,2); //A6 Tx & Rx is connected to Arduino #5 & #4

String tin_nhan="";
String linkmap = "https://www.google.com/maps/?q="+latitude+","+longitude;
void setup()
{
  pinMode(7, OUTPUT);
  ModuleSerial.begin(9600);
  Serial.begin(9600);
  delay(1000);
  ModuleSerial.println("AT+CMGF=1r");
  delay(1000);
  ModuleSerial.println("AT+CNMI=2,2,0,0,0r"); // Configuring TEXT mode
  delay(1000);
  sendSMS("123","ddd");
}

void loop()
{
  delay(1000);
  while(ModuleSerial.available()>0)
  {
        delay(100);
        char c = ModuleSerial.read();
        if(c=="#")
        {
          break;
        }
        delay(100);
        tin_nhan += c;
  }
  delay(100);
  if(tin_nhan.length() > 0)
  {
    Serial.println(tin_nhan);
    if(tin_nhan == "check#")
    {
      digitalWrite(7,HIGH);  
    }
    else if(tin_nhan == "low#")
    {
      digitalWrite(7,LOW);
    }
    tin_nhan = "";
  }
}
void sendSMS(String latitude, String longitude){
  ModuleSerial.println("AT");
  delay(1000);
  ModuleSerial.println("AT+CMGF=1");
  delay(100);
  ModuleSerial.println("AT+CMGS=\"+84977694163\"\r");
 delay(100);
  ModuleSerial.print(linkmap);
  delay(100);
  ModuleSerial.println((char)26);
  delay(100);
  Serial.println("send sms access");
  delay(1000);
}
//
//void readSMS(){ 
//  ModuleSerial.println("AT"); //Once the handshake test is successful, it will back to OK
// delay(1000);
//  ModuleSerial.println("AT+CMGF=1");
// delay(1000);
//  ModuleSerial.println("AT+CMGL=\"REC UNREAD\",1"); // Configuring TEXT mode
// delay(1000);
//  String tin_nhan = tinnhan();
//  Serial.print("result : = ");
//  //updateSerial();
//  Serial.println(tin_nhan);
//  updateSerial();
//  if(tin_nhan.indexOf("CMGR") == -1) return false;
//  int first = tin_nhan.indexOf("UNREAD") +9;
//  int last = tin_nhan.indexOf("\"",first); 
//
//return true;
//}

//void Gsm_Power_On()
//{
//  digitalWrite(PWR_KEY, HIGH);                // Du chan PWR_KEY len cao it nhat 1s 
//  delay(1500);                                            // o day ta de 1,5s
//  digitalWrite(PWR_KEY, LOW);                  // Du chan PWR_KEY xuong thap
//  delay(100);                                              // cac ban xem trong Hardware designed sim800C de hieu ro hon
//}

String tinnhan(){
  String result="check";
  unsigned long timerStart, prevChar = 0;
  timerStart = millis();
  while(1){
    if(ModuleSerial.available()){
    char c = ModuleSerial.read();
    delay(100);
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
