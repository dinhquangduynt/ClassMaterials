  #include <SoftwareSerial.h>
  #include <sim.h>
  #include <TinyGPS++.h>
  
  TinyGPSPlus GPS;
//  
//  #define TX_SIM  6
//  #define RX_SIM  5
  #define RXPin   11
  #define TXPin   10
  #define btn     12
  int count = 0;
  
  SoftwareSerial ss(RXPin, TXPin); // cau hinh chan gps
  
  String lati="",longi="",ggmap= "";
  
  String content = "";
  String phonenumber = "";
  String contact[3];   //mang chua cac so dien thoai
  void setup() {
    ss.begin(9600);
    Serial.begin(9600);
    Serial.println("Initializing.......");
    pinMode(btn, INPUT);

    contact[0] = "+84977694163";
    contact[1] = "+84335941792";
    contact[2] = "+84796295776";
    
    delay(5000);

    initSIM(9600);
    deleteAllSMS();
    Serial.println("Initialized.......");
    delay(500);
  }
  
  void loop()
  {   
            
             int btn_click = digitalRead(btn);
             Serial.println(btn_click);
             while(btn_click == HIGH)
             { 
              delay(100);
              ggmap = getGPS();
              sendSMSBtn(contact[0],ggmap);
              delay(500);
              btn_click = LOW;
              delay(100);
              break;
             }
          
            int messageIndex = isSMSunread();
            Serial.print("message index : ");
            Serial.println(messageIndex);
            if (messageIndex > 0) {
              handleMessage(messageIndex);
            }
  }

String getGPS() {
  unsigned long timestart = millis();
  while (true) {
    while (ss.available() > 0) {
      GPS.encode(ss.read());
      if (GPS.location.isUpdated()) {
         lati = String(GPS.location.lat(),6);
         longi = String(GPS.location.lng(),6);
         ggmap = "https://www.google.com/maps/?q="+lati+","+longi+"&t=m&z=36\n\r";
         return ggmap;
      }
    }
    if ((unsigned long)(millis()- timestart) > 2000)
      {
        return "Invalid";
      }
  }
}



  void handleMessage(int messageIndex) {
    Serial.println("Getting message...");
    if (readSMS(messageIndex, phonenumber, content)) {
      Serial.println("Message read!!!");
    }
    if (deleteAllSMS()) {
      Serial.println("Deleted all message");
    }
    sendCommand(content);
  }
  
  void sendCommand(String command) {
    command.toUpperCase();
    for (int i = 0; i < 3; i++) {
      if (phonenumber.equals(contact[i])) {     
        if (command.equals("CHECK")) {
            String gps = getGPS();
            Serial.println(gps);
            sendGPS(phonenumber, gps);
        }
      }
    }
  }
  
  void sendGPS(String phonenumber, String gps) {
    Serial.println("Sending message....");
    sendSMS(phonenumber, gps);
    Serial.println("Message sent!!!");
  }
