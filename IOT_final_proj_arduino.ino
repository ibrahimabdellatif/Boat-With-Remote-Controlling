#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//create instance form ESP8266WebServer class 
ESP8266WebServer server(80); // 80 is port number

//init ssid & password for connecting
const char* ssid = "ibrahim";
const char* password = "aaa@@@AA0";

#include <Servo.h>

//create instance form servo class 
Servo servo;

//this for ultraSonic
int echoPin = D3;
int trigPin = D2;
long duration;
int distance;

//this for DC motor driver'controller'
int A1A = D6;
int A1B = D5;

//for condition
bool dcMotorChecked = false;
bool servoRight = false;
bool servoLeft = false;

void dcMotorOn(){

//   digitalWrite(A1A , LOW);
//   digitalWrite(A1B , HIGH);
   dcMotorChecked = true;
   //sending the status of requst 200 
  server.send(200 , "text/html" , "dc motor is on");
  }
void dcMotorOff(){
  
//   digitalWrite(A1A , LOW);
//   digitalWrite(A1B , LOW);
   dcMotorChecked = false;
  server.send(200 , "text/html" , "de motor is off");
  }
void servoRight(){

//  servo.write(180);
  servoRight = true
  server.send(200 , "text/html" , "servo right is on");
  
  }
void servoLeft(){
  
//  servo.write(-180);
  servoLeft = true;
  server.send(200 , "text/html" , "servo left is on");
  }

void handleNotFound(){
   // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request with 404: Not found message
  server.send(404, "text/html", "404: Not found");
}
void setup() {
//init wifi connection
Serial.begin(115200);
   //STA -> is the station while connecting the node with wifi router device or hotspot
WiFi.mode(WIFI_STA);
WiFi.begin(ssid , password);

   // below line is equal with this -> (WiFi.status() != WL_CONNECTED)
while(WiFi.status()!=WL_CONNECTED)delay(1000);

   //getting the ip of node that we needed when use android application
Serial.println(WiFi.localIP());

   //sending the methods with 4 functions 
server.on("/dcON" , dcMotorOn);
server.on("/dcOFF" , dcMotorOff);
server.on("/servoRightON" , servoRight);
server.on("/servoLeftON" , servoLeft);
   // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"
server.onNotFound(handleNotFound);

server.begin();
  // put your setup code here, to run once:
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);

  //setting motor drivers to outputs 
  pinMode(A1A , OUTPUT);
  pinMode(A1B , OUTPUT);
  //setup servo
  servo.attach(2); //D4
  servo.write(0);
}

void loop() {

  //for server connections
  server.handleClient();   // Listen for HTTP requests from clients
  delay(10);

  
//because it works on wise clock cycle  
  if(dcMotorChecked){
   digitalWrite(A1A , LOW);
   digitalWrite(A1B , HIGH);
  }else{
  digitalWrite(A1A , LOW);
  digitalWrite(A1B , LOW);
  }

  //servo conditions for left and right 
  if(servoRight){
    servo.write(180);
  }else{
    servo.write(0);
  }
   
   if(servoLeft){
    servo.write(-180);
  }else{
   servo.write(0);
  }
  
//init Ultra sonic chip
digitalWrite(trigPin , LOW);
delayMicroseconds(2);

digitalWrite(trigPin , HIGH);
delayMicroseconds(10);
digitalWrite(trigPin , LOW);

duration = pulseIn(echoPin , HIGH);
distance = duration * 0.034 / 2;

//ultra sonic condition
   //check for 30 CM
  if(distance >= 30){
  //turn off the DC motor
  
    dcMotorChecked = false;
  
  }else {
  
    deMotorChecked = true;
  
  }

}
