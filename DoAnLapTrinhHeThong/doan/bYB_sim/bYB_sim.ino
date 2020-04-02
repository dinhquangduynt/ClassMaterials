#include <SoftwareSerial.h>
#include <string.h>
char command = 0; //Conditional Programming Variable changes with SMS content.
char incoming_char = 0;
SoftwareSerial cell(5, 4); //my shield uses these pins for software serial.

void setup()
{
 Serial.begin(9600);
 cell.begin(9600);
 delay(2000);
 Serial.print("Starting modem communication...");
 delay(12000);
 Serial.print("OK\nIntroduce your AT commands:\n"); 
}

void loop()

{
 if(cell.available() > 0)
 {
   incoming_char=cell.read();
   if((incoming_char >= ' ') && (incoming_char <= 'z'))
     Serial.print(incoming_char);
   if(incoming_char=='#'){
     Serial.println("SMS command mode:"); //If the SMS contains "#" the arduino looks for commands that follow.
     command=cell.read();
   }
   if (command == 'a'){  //If the next character in the SMS is "a", then do the following
     Serial.println("Commands would execute here and now.");
     command = 0;
   }

   else
   {
     Serial.print("%");
     Serial.print((int)incoming_char);
     Serial.print("%");
     if(incoming_char==10)
       Serial.println();

     //Serial.println(incoming_char);



   }
 }

 if(Serial.available() > 0)
 {
   incoming_char = Serial.read();
   cell.print(incoming_char);
 }
}
