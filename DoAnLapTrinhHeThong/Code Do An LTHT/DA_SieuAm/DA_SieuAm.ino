int Buzzer = 10;
int TRIG_PIN = 11;
int ECHO_PIN = 12;
int RedPin = 5;
int BluePin = 6;
int potpin=A0; //Định nghĩa chân quang trở chân 0
int val=0;// giá trị ban đầu
int thoigian,khoangcach;

void setup(){
Serial.begin(9600);
pinMode(TRIG_PIN, OUTPUT); //cong 11 la output, chan trig, phat ra tin hieu
pinMode(ECHO_PIN, INPUT); // cong 12 la input, chan echo, nhan lại thong tin phan hoi
pinMode(Buzzer, OUTPUT);
pinMode(RedPin, OUTPUT); //pinMode đèn đỏ là OUTPUT
pinMode(BluePin, OUTPUT); //pinMode đèn xanh là OUTPUT
}


void loop(){
//PHÁT XUNG TỪ CHÂN TRIG
digitalWrite(TRIG_PIN,LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN,HIGH);
delayMicroseconds(5);
digitalWrite(TRIG_PIN,LOW);
//ĐO KHOẢNG CÁCH
thoigian=pulseIn(ECHO_PIN,HIGH); //lay gia tri thoi gian tu chan echo
khoangcach=0.03432*(thoigian/2); //cong thuc tinh khoang cach, s=v*t
Serial.print(khoangcach);
Serial.println("cm");

//BẬT TẮT CÒI BÁO
if(khoangcach<150) {
  digitalWrite(Buzzer, HIGH);
  delay(80);  
  digitalWrite(Buzzer, LOW);
}
else {
  digitalWrite(Buzzer, LOW);
}

delay(50);
//Serial.println(val);
val=analogRead(potpin);
//Serial.println(val);
if(val>800){
            digitalWrite(BluePin, HIGH);
            if(khoangcach<150){
               digitalWrite(RedPin, HIGH);
               delay(80);
               digitalWrite(RedPin,LOW);
            }
}
else {
   digitalWrite(RedPin, LOW );
    digitalWrite(BluePin, LOW );
}

}
