int btn = 7;
int RedPin = 8;
int BluePin = 9;
int potpin = A0; //Định nghĩa chân quang trở chân 0
int potpin_check =0;
void setup() {
  // put your setup code here, to run once:
  pinMode(btn,INPUT);
  pinMode(RedPin,OUTPUT);
  pinMode(BluePin,OUTPUT);
  pinMode(potpin, INPUT);
  Serial.begin(9600);
}

void loop() {
   potpin_check = analogRead(potpin);
  Serial.println(potpin_check);
  delay(100);
  if(potpin_check < 1100){
    digitalWrite(BluePin,HIGH);
    digitalWrite(RedPin,HIGH);
  }
  else {
    digitalWrite(BluePin,LOW);
    digitalWrite(RedPin,LOW);
  }
  // put your main code here, to run repeatedly:

}
