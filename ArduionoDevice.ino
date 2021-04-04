//Attendance record
//ArduionoDevice

#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
Servo myservo;

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc(SS_PIN, RST_PIN);

const int buzzer = 3;
const int gled = 2;
const int rled = 4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc.PCD_Init();
  myservo.attach(5);
  pinMode(buzzer, OUTPUT);
  pinMode(gled,OUTPUT);
  pinMode(rled,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!mfrc.PICC_IsNewCardPresent())
    return;
   if(!mfrc.PICC_ReadCardSerial())
    return;
    
  if(mfrc.uid.uidByte[0] == 39 &&
    mfrc.uid.uidByte[1] == 156 &&
    mfrc.uid.uidByte[2] == 243 &&
    mfrc.uid.uidByte[3] == 174)

  { 
    digitalWrite(buzzer,HIGH);
    delay(250);
    digitalWrite(buzzer,LOW);
    Serial.println("Kiwon.");
    digitalWrite(gled,HIGH);
    delay(750);
    digitalWrite(gled,LOW);
    delay(1000);
  }

  else
  {
     digitalWrite(rled,HIGH);
     delay(50);
     digitalWrite(rled,LOW);
     delay(50);
     digitalWrite(rled,HIGH);
     delay(50);
     digitalWrite(rled,LOW);
     delay(50);
     digitalWrite(rled,HIGH);
     delay(50);
     digitalWrite(rled,LOW);
     digitalWrite(buzzer,HIGH);
     delay(50);
     digitalWrite(buzzer,LOW);
     delay(50);
     digitalWrite(buzzer,HIGH);
     delay(50);
     digitalWrite(buzzer,LOW);
     Serial.println("Access denied");\
     delay(1000);

  }
}