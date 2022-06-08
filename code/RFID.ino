
#include <SPI.h> 
#include <MFRC522.h>  
#include <Servo.h> 

RFID rfid(11, 6);       //D10:pin of tag reader SDA. D9:pin of tag reader RST wider
unsigned char status; 
unsigned char str[MAX_LEN]; //MAX_LEN is 16: size of the array 

String accessGranted [2] = {"09239884", "19612012715"};  //RFID serial numbers to grant access to
int accessGrantedSize = 2;                                //The number of serial numbers

Servo lockServo;                //Servo for locking mechanism
int lockPos = 15;               //Locked position limit
int unlockPos = 75;             //Unlocked position limit
boolean locked = true;

int redLEDPin = 3;
int greenLEDPin = 4;
int blueLEDPin = 5;

void setup() 
{ 
  Serial.begin(9600);     //Serial monitor is only required to get tag ID numbers and for troubleshooting
  lockServo.attach(2);
  SPI.begin();            //Start SPI communication with reader
  mfrc522.PCD_Init();  // Initialisiere MFRC522 Lesemodul
  pinMode(redLEDPin, OUTPUT);     //LED startup sequence
  pinMode(greenLEDPin, OUTPUT);
  digitalWrite(redLEDPin, HIGH);
  delay(200);
  digitalWrite(greenLEDPin, HIGH);
  delay(200);
  digitalWrite(redLEDPin, LOW);
  delay(200);
  digitalWrite(greenLEDPin, LOW);
  Serial.print("Place card/tag near reader...");
} 

void loop() 
{ 
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial() ) { 
    Serial.print("Card Found:");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
    } 
    Serial.println(); 
    checkAccess (temp);     //Check if the identified tag is an allowed to open tag
    } 
    mfrc522.PICC_HaltA(); //Lock card to prevent a redundant read, removing the line will make the sketch read cards continually
    delay(1000);
}

void checkAccess (String temp)    //Function to check if an identified tag is registered to allow access
{
  boolean granted = false;
  for (int i=0; i <= (accessGrantedSize-1); i++)    //Runs through all tag ID numbers registered in the array
  {
    if(accessGranted[i] == temp)            //If a tag is found then open/close the lock
    {
      Serial.println ("Access Granted");
      granted = true;
      if (locked == true)         //If the lock is closed then open it
      {
          lockServo.write(unlockPos);
          locked = false;
      }
      else if (locked == false)   //If the lock is open then close it
      {
          lockServo.write(lockPos);
          locked = true;
      }
      digitalWrite(greenLEDPin, HIGH);    //Green LED sequence
      delay(200);
      digitalWrite(greenLEDPin, LOW);
      delay(200);
      digitalWrite(greenLEDPin, HIGH);
      delay(200);
      digitalWrite(greenLEDPin, LOW);
      delay(200);
    }
  }
  if (granted == false)     //If the tag is not found
  {
    Serial.println ("Access Denied");
    digitalWrite(redLEDPin, HIGH);      //Red LED sequence
    delay(200);
    digitalWrite(redLEDPin, LOW);
    delay(200);
    digitalWrite(redLEDPin, HIGH);
    delay(200);
    digitalWrite(redLEDPin, LOW);
    delay(200);
  }
}