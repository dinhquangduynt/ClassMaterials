#include "sim.h"
SoftwareSerial sim(6,5);

void initSIM(int baud)
{
    sim.begin(baud);
    send_cmd("AT\r\n");
    send_cmd("AT+CFUN=1\r\n");
    send_cmd("AT+CMGF=1\r\n");
}

void send_cmd(String cmd)
{
    clearBuffer();
    Serial.println(cmd);
    sim.println(cmd);
}

String wait_for_resp()
{
    String result = "";
    unsigned long timerStart, prevChar = 0;
    timerStart = millis();
    while (1)
    {
        if (check_readable())
        {
            char c = sim.read();
            prevChar = millis();
            result += c;
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

int check_readable()
{
    return sim.available();
}

bool check_with_cmd(String cmd, const String resp)
{
    send_cmd(cmd);
    String tmp = wait_for_resp();
    return tmp.indexOf(resp) != -1;
}


bool sendSMS(String number, String message)
{
    if (!check_with_cmd("AT+CMGS=\"" + number + "\"", ">"))
    {
        return false;
    }
    delay(1000);
    send_cmd(message);
    delay(500);
    sim.println((char)26);
    return wait_for_resp().indexOf("OK") != -1;
}

void sendSMSBtn(String number, String message)
{
    check_with_cmd("AT+CMGS=\"" + number + "\"", ">");
    delay(1000);
    send_cmd(" HELP ");
	delay(500);
	sim.println();
    send_cmd(message);
    delay(500);
    sim.println((char)26);
}


void clearBuffer()
{
    delay(300);
    while (check_readable())
    {
        sim.read();
    }
}

int isSMSunread()
{

    int index = 0;
    send_cmd("AT+CMGL=\"REC UNREAD\",1");
    String result = wait_for_resp();
    Serial.print("Result : ");
    Serial.println(result);
    if (result.indexOf("OK") == -1)
    {
        return -1;
    }
    else
    {
        index = result.indexOf("1");
        int temp = result.substring(index).lastIndexOf("+CMGL");
        if (temp == -1) return 0;
        index = result[result.lastIndexOf("+CMGL") + 7];
    }
    return  index - 48;
}

bool readSMS(int messageIndex, String &phonenumber, String &content)
{
    String cmd = String("AT+CMGR=") + messageIndex + ",1"; 
    send_cmd(cmd);
    String result = wait_for_resp();
    if (result.indexOf("+CMGR") == -1) return false;
    int first =  result.indexOf("UNREAD") + 9;
    int last = result.indexOf("\"",first);
    phonenumber = result.substring(first,last);
    first = result.lastIndexOf("\"");
    first = result.indexOf("\n",first);
    last = result.indexOf("\n",first+1);
    content = result.substring(first+1,last-1);
    return true;
}

bool deleteAllSMS() {
    String cmd = String("AT+CMGDA=\"DEL ALL\"");
	return check_with_cmd(cmd,"OK");	
}
