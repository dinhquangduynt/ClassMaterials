#include <SoftwareSerial.h>
#include <kien800.h>
#include <TinyGPS++.h>
TinyGPSPlus GPS;



#define TX_SIM  6
#define RX_SIM  5
#define RXPin   11
#define TXPin   10
#define Btn     12

String lati="51.508131",longi="-0.128002",ggmap= "https://www.google.com/maps/?q="+lati+","+longi+"&t=m&z=36\n\r";
int count = 0;

SoftwareSerial ss(RXPin, TXPin);

//SoftwareSerial ModuleSerial(6, 5);

int relay = 7;

String phonenumber = "";
String content = "";
String contact[3];
void handleMessage();
void sendCommand();
void turnOffDevice();
void turnOnDevice();
void sendGPS(String , String);
String getGPS();
bool initGPS();

void setup() {
  ss.begin(9600);
  Serial.begin(9600);
  Serial.println("Initializing.......");
  pinMode(Btn, INPUT);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,LOW);
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

  deleteAllSMS();

  Serial.println("Initialized");
}

String getGPS() {
  Serial.print(F("Location: ")); 
  if (GPS.location.isValid())
  {
    //Serial.print(gps.location.lat(), 6);
    //Serial.print(F(","));
    //Serial.print(gps.location.lng(), 6);
    String location = "https://www.google.com/maps/place/" + String(GPS.location.lat(),6) + "+" + String(GPS.location.lng(),6);
    Serial.println(location);
    return location; 
  }
  else
  {
    Serial.print(F("INVALID"));
    return "Invalid";
  }
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
  if (deleteAllSMS()) {
    Serial.println(">>>>>Deleted all message");
  }
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
//        if (initGPS()) {
          String gpsCoordinate = getGPS();
          Serial.println(gpsCoordinate);
          sendGPS(phonenumber, gpsCoordinate);
//        } else {
          //sendGPS(phonenumber, "NOGPS");
      //  }
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

bool initGPS() {
 while (ss.available() > 0)
    if (GPS.encode(ss.read()))SoftwareSerial ss(RXPin, TXPin);

      return true;

  if (millis() > 5000 && GPS.charsProcessed() < 10)
  {    

    return false;
  }

}
