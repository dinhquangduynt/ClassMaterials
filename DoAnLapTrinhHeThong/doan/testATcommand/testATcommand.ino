#include <SoftwareSerial.h>
#include <kien800.h>
#include <TinyGPS++.h>
TinyGPSPlus GPS;



#define TX_SIM  6
#define RX_SIM  5
#define RXPin   10
#define TXPin   11
String lati="51.508131",longi="-0.128002",ggmap= "https://www.google.com/maps/?q="+lati+","+longi+"&t=m&z=36\n\r";


int count = 0;

SoftwareSerial  ss(RXPin, TXPin);
SoftwareSerial  sim(6, 5);

int relay = 7;

String phonenumber = "";
String content = "";
String contact[3];
void handleMessage();
void sendCommand();
void turnOffDevice();
void turnOnDevice();
void sendGPS(String , String );
String getGPS();
//bool initGPS();

void setup() {
  ss.begin(9600);
  sim.begin(9600);
  Serial.begin(9600);
  Serial.println("Initializing.......");
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  contact[0] = "+84977694163";
  contact[1] = "+84335941792";
  contact[2] = "+84796295776";
  delay(5000);
  while (!initSIM(TX_SIM, RX_SIM, 9600)) {
    Serial.println("Init error!");
    delay(1000);
  }
//  while(!initGPS()) {
//    Serial.println("Init GPS error!");
//  }
  //deleteAllSMS();
  sim.println("AT+CMGDA=\"DEL ALL\"");
  delay(100);
  Serial.println(">>>>>Deleted all message");
  delay(500);
  Serial.println("Initialized");
}

String getGPS() {
  Serial.print(F("Location: ")); 
  while (ss.available() > 0)
                {
              
                  if (GPS.encode(ss.read()))
                  {
                    if (GPS.location.isValid())
                    {
                      lati  = String((GPS.location.lat(), 6));
                      longi = String((GPS.location.lng(), 6));
                      ggmap= "https://www.google.com/maps/?q="+lati+","+longi+"&t=m&z=36\n\r";
                    }
                    else {
                      ggmap= "No GPS";
                    }
              
                  }
              
                }
                return ggmap;
  
}

void loop()
{
  int messageIndex = isSMSunread();
  Serial.print("message index : ");
  Serial.println(messageIndex);
  if (messageIndex > 0) {
    handleMessage(messageIndex);
  }
}

void handleMessage(int messageIndex) {
  Serial.println("Getting message...");
  if (readSMS(messageIndex, phonenumber, content)) {
    Serial.println(">>>>>Message read!!!");
  }
  sim.println("AT+CMGDA=\"DEL ALL\"");
  delay(1000);
  Serial.println(">>>>>Deleted all message");
  
//  if (deleteAllSMS()) {
//    Serial.println(">>>>>Deleted all message");
//  }
  sendCommand(content);
}

void sendCommand(String command) {
  command.toUpperCase();
  for (int i = 0; i < 3; i++) {
    if (phonenumber.equals(contact[i])) {
      if (command.equals("OFF")) {
        turnOffDevice();
      }
      if (command.equals("ON")) {
        turnOnDevice();
      }
      if (command.equals("GPS")) {
          String gpsCoordinate = getGPS();
          Serial.println(gpsCoordinate);
          sendGPS(phonenumber, gpsCoordinate);
      }
    }
  }
}

void sendGPS(String phonenumber, String coordinate) {
  Serial.println("Sending message....");
  sendSMS(phonenumber, coordinate);
  Serial.println("Message sent!!!");
}



void turnOffDevice() {
  Serial.println("Turning off device.....");
  digitalWrite(relay, LOW);
  Serial.println("Turn off....");
}

void turnOnDevice() {
  Serial.println("Turn on device.....");
  digitalWrite(relay, HIGH);
  Serial.println("Turn on.....");
}
