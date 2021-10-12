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

String motorOn , motorOff  , turnOn , turnOff;
void dcMotorOn(){

//   digitalWrite(A1A , LOW);
//   digitalWrite(A1B , HIGH);
   dcMotorChecked = true;
  server.send(200 , "text/html" , motorOn);
  }
void dcMotorOff(){
  
//   digitalWrite(A1A , LOW);
//   digitalWrite(A1B , LOW);
   dcMotorChecked = false;
  server.send(200 , "text/html" , motorOff);
  }
void servoRight(){

//  servo.write(180);
  servoRight = true
  server.send(200 , "text/html" , turnOn);
  
  }
void servoLeft(){
  
//  servo.write(-180);
  servoLeft = true;
  server.send(200 , "text/html" , turnOn);
  }

void setup() {
//init wifi connection
Serial.begin(115200);
WiFi.mode(WIFI_STA);
WiFi.begin(ssid , password);

while(WiFi.status()!=WL_CONNECTED)delay(500);

Serial.println(WiFi.localIP());

server.on("/dcON" , dcMotorOn);
server.on("/dcOFF" , dcMotorOff);
server.on("/servoRightON" , servoRight);
server.on("/servoLeftON" , servoLeft);

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
  server.handleClient();
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
