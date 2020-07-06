#include <ESP8266WiFi.h>
const char* ssid = "Poor quality";                                  //fill in your wifi name
const char* password = "12345678";                              //fill in your wifi password


WiFiClient client;

int sensorPin = A0;    // input for LDR and rain sensor
int enable2 = 13;      // enable reading Rain sensor
int sensorValue2 = 0;  // variable to store the value coming from sensor Rain sensor


//--------------------------setup-------------------------
void setup() {

// declare the enable and ledPin as an OUTPUT:
pinMode(enable2, OUTPUT);

  
Serial.begin(115200);
delay(10);


WiFi.begin(ssid, password);

Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
Serial.print("..........");
Serial.println();
WiFi.begin(ssid, password);

while (WiFi.status() != WL_CONNECTED) {
delay(500);

}
Serial.println("WiFi connected");
Serial.println();

}


void loop() {



//--------------------------Rain Sensor-------------------------



delay(500);
sensorValue2 = analogRead(sensorPin);
sensorValue2 = constrain(sensorValue2, 150, 440); 
sensorValue2 = map(sensorValue2, 150, 440, 1023, 0); 
if (sensorValue2>= 20)
{
  Serial.print("rain is detected");
  
digitalWrite(enable2, HIGH);
  }
  else
  
{
  Serial.print("rain not detected");
  digitalWrite(enable2, LOW); 
  }
//Serial.print("Rain value:       ");
//Serial.println(sensorValue2);
Serial.println();
delay(100);



}
