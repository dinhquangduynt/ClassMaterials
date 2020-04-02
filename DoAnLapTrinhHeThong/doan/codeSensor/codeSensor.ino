#include <EEPROM.h>
const int trig = 5;                                     //chân trig của HC-SR04
const int echo = 11;                                    //chân echo của HC-SR04
const int buzzer = 8;

unsigned long duration;                                // biến đo tời gian
int khoang_cach;                                        // biến lưu khoảng cách
int time_x = 0;
byte loa1 = 0;
byte loa2 = 0;
byte tay = 6;
unsigned long pe_loa1 = 0;
unsigned long pe_loa2 = 0;

void setup()
{
    Serial.begin(9600);                                 // giao tiếp Serial với baudrate 9600;
    pinMode(trig, OUTPUT);                              // khai báo chân trig sẽ phát tín hiệu
    pinMode(echo, INPUT);                               // khai báo chân echo sẽ nhận tín hiệu
    pinMode(buzzer  ,OUTPUT);                           // khia báo output cho còi
    pinMode(A5,INPUT);
  }

void loop()
{
        unsigned long thoi_gian = 0;                    // biến đo thời gian - Time variable
        int khoang_cach;                                // biến lưu khoảng cách - Distance variable
 
        /* Phát xung từ chân trig */
        delay(50);                                      //delay để tránh nhiễu sóng siêu âm
        digitalWrite(trig, 0);                          // tắt chân trig
        delayMicroseconds(2);
        digitalWrite(trig, 1);                          // phát xung từ chân trig
        delayMicroseconds(5);                           // xung có độ dài 5 microSeconds
        digitalWrite(trig, 0);                          // tắt chân trig
 
        /* Tính toán thời gian */
        duration = pulseIn(echo, HIGH);                //Hàm pulseIn() được dùng để đo độ rộng của xung
 
        // Tính khoảng cách đến vật.
        khoang_cach = int(duration / 2 / 29.412);      //Thời gian sóng truyền từ cảm biến đến vật sẽ bằng duration/2, sau đó ta chia tiếp cho 29,412 để tính khoảng cách.
        
        //để kiểm tra xem thời gian hiện tại là bao nhiêu ta dùng hàm millis()
        // khoang cách từ vị trí vật cản đến gậy
        if (khoang_cach <= 150) {
               time_x = (2 * khoang_cach) + (khoang_cach / 2);
                if ((loa1 == 0) && (millis() - pe_loa2 >= time_x)) {
                    pe_loa1 = millis();
                    digitalWrite(buzzer, HIGH);           //lớn
                    loa1 = 1;
                    loa2 = 0;
                }
                if((loa2 == 0) && (millis() - pe_loa1 >= 50)) {
                    pe_loa2 = millis();
                    digitalWrite(buzzer, LOW);            //nhỏ
                    loa2 = 1;
                    loa1 = 0;
                }
        }
            else {
                if (millis() - pe_loa1 >= 20) {
                    digitalWrite(buzzer, LOW);          //nhỏ
                }
            }
}

