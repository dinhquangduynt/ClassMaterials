#include <SoftwareSerial.h>
#include <kien800.h>
#include <TinyGPS++.h>
TinyGPSPlus GPS;



#define TX_SIM  8
#define RX_SIM  9
#define RXPin   4
#define TXPin   3


int count = 0;

SoftwareSerial ss(RXPin, TXPin);

int relay = 13;

String phonenumber = "";
String content = "";
String contact[3];
void handleMessage();
void sendCommand();
void turnOffDevice();
void turnOnDevice();
void sendGPS(String , String );
String getGPS();
bool initGPS();

void setup() {
  ss.begin(9600);
  Serial.begin(9600);
  Serial.println("Initializing.......");
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  contact[0] = "+84868788245";
  contact[1] = "+84329381641";
  contact[2] = "+84333472998";
  delay(5000);
  while (!initSIM(TX_SIM, RX_SIM, 9600)) {
    Serial.println("Init error!");
    delay(1000);
  }
  while(!initGPS()) {
    Serial.println("Init GPS error!");
  }
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
      if (command.equals("CHECK BALANCE")) {
        String balance = "So tien trong tai khoan la: ";
        balance += getBalance();
        sendSMS(contact[i], balance);
      }
      if (command.equals("GPS")) {
        if (initGPS()) {
          String gpsCoordinate = getGPS();
          Serial.println(gpsCoordinate);
          sendGPS(phonenumber, gpsCoordinate);
        } else {
          sendGPS(phonenumber, "Không thể định vị!");
        }
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
