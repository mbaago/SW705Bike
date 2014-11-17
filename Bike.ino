#include "\Libaries\GSM-GPRS-GPS-Shield\SIM900.h"
#include "\Libaries\GSM-GPRS-GPS-Shield\inetGSM.h"
#include "SIM900.h"
#include "inetGSM.h"
#include <SoftwareSerial.h>

 
InetGSM inet;              
 
char msg[50];
int numdata;
char inSerial[50];
int i=0;
boolean started=false;
 
void setup()
{
  Serial.begin(9600);
  Serial.println("GSM Shield testing.");
  if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
    started=true; 
  }
  else Serial.println("\nstatus=IDLE");
 
  if(started){
    if (inet.attachGPRS("internet.wind","", ""))
      Serial.println("status=ATTACHED");
    else Serial.println("status=ERROR");
    delay(1000);
 
    gsm.SimpleWriteln("AT+CIFSR");
    delay(5000);
    gsm.WhileSimpleRead();
    numdata=inet.httpGET("www.google.com", 80, "/", msg, 50);
    Serial.println("\nNumero di byte ricevuti:");
    Serial.println(numdata); 
    Serial.println("\nData recived:");
    Serial.println(msg);
  }
};
void loop()
{
};