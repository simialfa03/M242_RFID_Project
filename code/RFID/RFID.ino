
#include <SPI.h> // includes all needed packages
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN 6 // SPI Reset Pin
#define SS_PIN 11 // SPI Slave Select Pin (Arduino SDA Pin)

MFRC522 mfrc522(SS_PIN, RST_PIN); // Creates MFRC522 Instance

unsigned char status;

String accessGranted[2] = {"7b f9 37 1b", "05 80 e8 97 a1 f0 00"}; // RFID UID numbers to grant access to
int accessGrantedSize = 2;                                         // The number of UID numbers

Servo lockServo;    // Servo for locking mechanism
int lockPos = 15;   // Locked position limit
int unlockPos = 75; // Unlocked position limit
boolean locked = true; // sets locked to true

int redLEDPin = 3;  // LED Pins
int greenLEDPin = 4;
int blueLEDPin = 5;
 
void setup()
{
  Serial.begin(9600); // Serial monitor is only required to get tag ID numbers and for troubleshooting
  lockServo.attach(2);        // attaches Servo to PIN 2
  SPI.begin();                // Start SPI communication with reader
  mfrc522.PCD_Init();         // Initialize MFRC522 read module
  pinMode(redLEDPin, OUTPUT); // LED startup sequence
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
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) // Detects Card and Reads Serial Out
  {
    Serial.print("Card Found:");
    String temp = "";
    for (byte i = 0; i < mfrc522.uid.size; i++)                          // for loop to complete UID of Card
    {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");         // prints out UID
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      temp.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ")); // joins the strings togheter in the temp variable
      temp.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println();
    checkAccess(temp);  // Check if the identified tag is an allowed to open tag in checkAccess Function
  }
  mfrc522.PICC_HaltA(); // Lock card to prevent a redundant read, removing the line will make the sketch read cards continually
  delay(1000);          // waits 1000 ms
}

void checkAccess(String temp) // Function to check if an identified tag is registered to allow access
{
  boolean granted = false; // sets granted boolean to false 
  for (int i = 0; i <= (accessGrantedSize - 1); i++) // Runs through all tag ID numbers registered in the array
  {
    if (accessGranted[i] == temp.substring(1)) // If a tag is found then open/close the lock
    {
      Serial.println("Access Granted: ");
      granted = true;     // sets granted to true
      if (locked == true) // If the lock is closed then open it
      {
        lockServo.write(unlockPos); // opens servo
        locked = false; // fills locked to false = opens door
      }
      else if (locked == false) // If the lock is open then close it
      {
        lockServo.write(lockPos); // closes Servo
        locked = true; // fills locked to true = close door
      }
      if (temp.substring(1) == "7b f9 37 1b"){      // If my UID is scanned, it will Identify me
        Serial.println("Identified as: Simi");      
      }
      digitalWrite(greenLEDPin, HIGH); // Green LED sequence
      delay(200);
      digitalWrite(greenLEDPin, LOW);
      delay(200);
      digitalWrite(greenLEDPin, HIGH);
      delay(200);
      digitalWrite(greenLEDPin, LOW);
      delay(200);
    }
  }
  if (granted == false) // If the tag is not found
  {
    Serial.println("Access Denied");
    if (locked == false) // If the lock is open then close it
      {
        lockServo.write(lockPos); // closes Servo
        locked = true; // fills locked to true = close door
      }
    digitalWrite(redLEDPin, HIGH); // Red LED sequence
    delay(200);
    digitalWrite(redLEDPin, LOW);
    delay(200);
    digitalWrite(redLEDPin, HIGH);
    delay(200);
    digitalWrite(redLEDPin, LOW);
    delay(200);
  }
}
