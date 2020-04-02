
#include <SoftwareSerial.h>
#include <Arduino.h>
void initSIM(int baud);
void send_cmd(String cmd);
String wait_for_resp();
bool check_with_cmd(String cmd, const String resp);
int check_readable();
bool sendSMS(String number, String message);
void sendSMSBtn(String number, String message);
void clearBuffer();
int isSMSunread();
bool readSMS(int messageIndex,String &phonenumber, String &content);
bool deleteAllSMS();
