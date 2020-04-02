//#include <GSM.h>
//#include <GSM3CircularBuffer.h>
//#include <GSM3IO.h>
//#include <GSM3MobileAccessProvider.h>
//#include <GSM3MobileCellManagement.h>
//#include <GSM3MobileClientProvider.h>
//#include <GSM3MobileClientService.h>
//#include <GSM3MobileDataNetworkProvider.h>
//#include <GSM3MobileMockupProvider.h>
//#include <GSM3MobileNetworkProvider.h>
//#include <GSM3MobileNetworkRegistry.h>
//#include <GSM3MobileServerProvider.h>
//#include <GSM3MobileServerService.h>
//#include <GSM3MobileSMSProvider.h>
//#include <GSM3MobileVoiceProvider.h>
//#include <GSM3ShieldV1.h>
//#include <GSM3ShieldV1AccessProvider.h>
//#include <GSM3ShieldV1BandManagement.h>
//#include <GSM3ShieldV1BaseProvider.h>
//#include <GSM3ShieldV1CellManagement.h>
//#include <GSM3ShieldV1ClientProvider.h>
//#include <GSM3ShieldV1DataNetworkProvider.h>
//#include <GSM3ShieldV1DirectModemProvider.h>
//#include <GSM3ShieldV1ModemCore.h>
//#include <GSM3ShieldV1ModemVerification.h>
//#include <GSM3ShieldV1MultiClientProvider.h>
//#include <GSM3ShieldV1MultiServerProvider.h>
//#include <GSM3ShieldV1PinManagement.h>
//#include <GSM3ShieldV1ScanNetworks.h>
//#include <GSM3ShieldV1ServerProvider.h>
//#include <GSM3ShieldV1SMSProvider.h>
//#include <GSM3ShieldV1VoiceProvider.h>
//#include <GSM3SMSService.h>
//#include <GSM3SoftSerial.h>
//#include <GSM3VoiceCallService.h>


#include <TinyGPS++.h>                                 //thu viện GPS
//#include <LiquidCrystal.h>
#include <SoftwareSerial.h>                           // thư viện giả lập TX, RX - UART mềm.
SoftwareSerial mySerial(6, 5);                       //module sim : TX chân 10, RX chân 9 
SoftwareSerial ss(11, 10);                              // GPS: TX chân 4, RX chân 3
int btn = 10;                                          // khai báo chân cho button gps
int btn_led = 8;                                      // khai báo chân cho button den
int led=7;                                            // khai báo chân cho led
int check = 0;                                        // khai báo biến kiễm tra đèn sáng tắt
TinyGPSPlus gps;                                      // khai báo gối tượng gps
  static const double LONDON_LAT = 51.508131, LONDON_LON = -0.128002;  

  String result="";
 
void setup() {
  pinMode(btn, INPUT);                                // khai báo button input 
  //pinMode(btn_led, INPUT);                            // khai báo button input
  //pinMode(led, OUTPUT);                               // khai báo led output
  mySerial.begin(9600);                               // Set toc do baud module goi tu UNO qua module sim    
  ss.begin(9600);                                     // Set toc do baud module goi tu UNO qua gps
  Serial.begin(9600);                                 // toc do baud cua Serial.
  delay(100);
   String temp = String(gps.location.lat(),6);                               // lấy kinh độ
                String temp1 = String(gps.location.lng(),6);                              // lấy vĩ độ
                String linkmap = "https://www.google.com/maps/?q="+temp+","+temp1;        // tạo link google map trọ tới vị trí vs kinh độ và vĩ độ lấy được
                mySerial.println("AT+CMGF=1");                                            // set module ở chế độ text
                delay(1000);  
                mySerial.println("AT+CMGS=\"+84977694163\"\r");                          // lênh AT cho phép gởi tn tới sdt                      
                delay(1000);
                mySerial.println("HELP DUY");                                              // tin nhan gởi
                delay(100);
                mySerial.println(linkmap);                                                // tin nhan gởi
                delay(100);
                 mySerial.println((char)26);                                              // ma ASCII cua ctrl+z : kết thúc tin nhắn
                delay(1000);   



               
                
}

void loop() {
//                mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
//                
//                mySerial.println("AT+CMGF=1");
//               
//                mySerial.println("AT+CMGL=\"REC UNREAD\",1"); // Configuring TEXT mode
//                
//               
//                
//                    while(1){
//                      if(mySerial.available()){
//                      char c = mySerial.read();
//                      result+=c;
//                          }
//                        Serial.print("result : = ");
//                        Serial.println(result);
//                    }


               ////// mai huong
//    static const double LONDON_LAT = 51.508131, LONDON_LON = -0.128002;                   // khai báo vị trí mặc định cho gps
//    int btn_sangled= digitalRead(btn_led);                                                //Đọc trạng thái button  led
//    if(btn_sangled == HIGH){                                                              // nếu button led bị nhấn
//      if(check == 0) {                                                                    // nếu đèn đang tắt (check = 0)
//        digitalWrite(led, HIGH);                                                          // bật đèn
//        check = 1;                                                                        // gán biến check =1 (đèn sáng)
//      }else{                                                                              // ngược lại nếu đèn sáng
//        digitalWrite(led, LOW);                                                           // tắt đèn
//        check = 0;                                                                        // gán biến check =0 (đèn sáng)
//      }
//      delay(500);                                                                         
//    }
//    
//    int btn_help= digitalRead(btn);                                                       // đọc trạng thái button gps
//   if (btn_help== HIGH) {                                                                 // Nếu mà button bị nhấn
//        while(!gps.location.isValid()){                                                   // lặp khi chưa xác định được vị trí                                
//        }
//            if(gps.location.isValid())                                                    // nếu đã xd được tọa độ
//            {
//                String temp = String(gps.location.lat(),6);                               // lấy kinh độ
//                String temp1 = String(gps.location.lng(),6);                              // lấy vĩ độ
//                String linkmap = "https://www.google.com/maps/?q="+temp+","+temp1;        // tạo link google map trọ tới vị trí vs kinh độ và vĩ độ lấy được
//                mySerial.println("AT+CMGF=1");                                            // set module ở chế độ text
//                delay(1000);  
//                mySerial.println("AT+CMGS=\"+841639884299\"\r");                          // lênh AT cho phép gởi tn tới sdt                      
//                delay(1000);
//                mySerial.println("HELP ME");                                              // tin nhan gởi
//                delay(100);
//                mySerial.println(linkmap);                                                // tin nhan gởi
//                delay(100);
//                 mySerial.println((char)26);                                              // ma ASCII cua ctrl+z : kết thúc tin nhắn
//                delay(1000);               
//            }
//            smartDelay(1000);                                                             // gọi hàm delay
//          
//            if (millis() > 5000 && gps.charsProcessed() < 10)                             // kiểm ra vị trí tọa độ
//              Serial.println(F("No GPS data received: check wiring"));                    // không dduwwcj thì xuất thông báo
//   }

}
static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do 
  {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

static void printFloat(float val, bool valid, int len, int prec)
{
  if (!valid)
  {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print(' ');
  }
  smartDelay(0);
}
static void printInt(unsigned long val, bool valid, int len)
{
  char sz[32] = "*****************";
  if (valid)
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i=strlen(sz); i<len; ++i)
    sz[i] = ' ';
  if (len > 0) 
    sz[len-1] = ' ';
  Serial.print(sz);
  smartDelay(0);
}

static void printDateTime(TinyGPSDate &d, TinyGPSTime &t)
{
  if (!d.isValid())
  {
    Serial.print(F("********** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d ", d.month(), d.day(), d.year());
    Serial.print(sz);
  }
  
  if (!t.isValid())
  {
    Serial.print(F("******** "));
  }
  else
  {
    char sz[32];
    sprintf(sz, "%02d:%02d:%02d ", t.hour(), t.minute(), t.second());
    Serial.print(sz);
  }

  printInt(d.age(), d.isValid(), 5);
  smartDelay(0);
}

static void printStr(const char *str, int len)
{
  int slen = strlen(str);
  for (int i=0; i<len; ++i)
    Serial.print(i<slen ? str[i] : ' ');
  smartDelay(0);
}


String tinnhan(){
  String result="";
  unsigned long timerStart, prevChar = 0;
  timerStart = millis();
  while(1){
    if(mySerial.available()){
    char c = mySerial.read();
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
