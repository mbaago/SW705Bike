#include "SIM900.h"
 
#include <SoftwareSerial.h>
 
#include "gps.h"              
 
GPSGSM gps;                   
 
char lon[10];   
char lat[10];   
char alt[10];   
char time[15];  
char vel[10];   
char stat;      
boolean started=false;
 
void setup()
{
  //Serial connection.
 Serial.begin(9600);
 
  Serial.println("GSM GPRS GPS Shield");
 
  if (gsm.begin(2400)){
 
    Serial.println("\nstatus=READY");
    gsm.forceON();              
    started=true; 
  }
  else Serial.println("\nstatus=IDLE");
 
  if(started){
    if (gps.attachGPS())
      Serial.println("status=GPSON");
    else Serial.println("status=ERROR");
 
    delay(20000);              
 
    stat=gps.getStat();        
 
              if(stat==1)
                            Serial.println("NOT FIXED");
              else if(stat==0)
                            Serial.println("GPS OFF");
              else if(stat==2)
                            Serial.println("2D FIXED");
              else if(stat==3)
                            Serial.println("3D FIXED");
              delay(5000);
 
              gps.getPar(lon,lat,alt,time,vel);
              Serial.println(lon);
              Serial.println(lat);
              Serial.println(alt);
              Serial.println(time);
              Serial.println(vel);
  }
};
 
void loop()
 
{
 
};