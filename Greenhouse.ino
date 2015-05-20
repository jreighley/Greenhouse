#include <SPI.h>
#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
byte mac[]    = {  0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
byte server[] = { 192, 168, 1, 2 };
byte ip[]     = { 192, 168, 1, 223 };

//TMP36 Pin Variables
int tanksensorPin = 3; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
 
int outsideSensorPin=4;
int insideSensorPin=5;
long NextCycleOn;
long NextCycleoff;
long CycleTime=3600000;
long CycleOnTime=3600000/4;
/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
}
 
void loop()                     // run over and over again
{
 //read the sensors
float tanktemp=functionReadTherm(tanksensorPin);
float outsidetemp=functionReadTherm(outsideSensorPin);
float insidetemp=functionReadTherm(insideSensorPin);

//flip indicators


//toggle outputs


//publish message
 

 
 delay(1000);                                     //waiting a second
}

float functionReadTherm(int readPin){
  int reading = analogRead(readPin); 
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temperatureF = (((voltage - 0.5) * 100) * 9.0 / 5.0) + 32.0;
  return(temperatureF);
}
  
