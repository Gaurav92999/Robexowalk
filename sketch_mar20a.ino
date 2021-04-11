#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

void setup()

{

  mySerial.begin(9600);   // Setting the baud rate of GSM Module 

  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)

  delay(100);

}

void loop()

{

  if (Serial.available()>0)

   switch(Serial.read())

  {

    case 's':

      SendMessage();

      break;

    case 'd':

      DialCall();

      break;

  }

 if (mySerial.available()>0)

   Serial.write(mySerial.read());

}

 void SendMessage()


{

  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode

  delay(1000);  // Delay of 1 second

  mySerial.println("AT+CMGS=\"+9325833333\"\r"); //  mobile number

  delay(1000);

  mySerial.println("ALERT! (user name) might be in need of your help");// The SMS text you recieve after detection of a mishap

  delay(100);

  mySerial.println((char)26);// ASCII code of CTRL+Z

  delay(1000);

}
