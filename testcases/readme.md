# Testcases
##  Testcase #1 

<b>Tester:</b> simialfa03
<b>Date:</b> 05.06.22
<b>Description:</b> 
Testing LED / Servo Sequence and Cabling on Startup

<b>Expected result:</b>
LED & servo are going trough their startup sequence, when Arduino is plugged in.

``` c++ 
Servo lockServo;    
int lockPos = 15;   
int unlockPos = 75;
boolean locked = true;
int redLEDPin = 3;   
int greenLEDPin = 4;  
int blueLEDPin = 5;   

void setup(){  
    pinMode(redLEDPin, OUTPUT);  
    pinMode(greenLEDPin, OUTPUT);  
    digitalWrite(redLEDPin, HIGH);   
    delay(200);   
    digitalWrite(greenLEDPin, HIGH);   
    delay(200);   
    digitalWrite(redLEDPin, LOW);   
    delay(200);   
    digitalWrite(greenLEDPin, LOW);  
    }
``` 

<b>Result: <span style="color:green">Successful</span></b><br>
LED & servo are going trough their startup sequence, when Arduino is plugged in.


##  Testcase #2 

<b>Tester:</b> simialfa03
<b>Date:</b> 05.06.22
<b>Description:</b> 
Testing if mfrc522 can read out UID of RFID card and prints it out to serial monitor. 

<b>Expected result:</b>
The UID of the RFID-Card should be printed in the serial-monitor.

``` c++ 
void loop(){
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())<>
  {
    String temp = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) 
    {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "); 
      Serial.print(mfrc522.uid.uidByte[i], HEX);
       } 
  }
  mfrc522.PICC_HaltA(); 
  delay(1000);          
}

``` 
<b>Result: <span style="color:green">Successful</span></b><br>
The UID of the RFID-Card is be printed in the serial-monitor.

##  Testcase #3

<b>Tester:</b> simialfa03
<b>Date:</b> 05.06.22
<b>Description:</b> 
Testing if concat works

<b>Expected result:</b>
Concat should join the string into the temp variable and should print it. 

``` c++ 
void loop(){
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial())<>
  {

    String temp = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) 
    {
      temp.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      temp.concat(String(mfrc522.uid.uidByte[i], HEX));
       } 
  }
  Serial.println(temp);
  mfrc522.PICC_HaltA(); 
  delay(1000);          
}
``` 
<b>Result: <span style="color:green">Successful</span></b><br>
Concat joins the string into the temp variable and prints it. 


##  Testcase #4

<b>Tester:</b> simialfa03
<b>Date:</b> 05.06.22
<b>Description:</b> 
Check if the for-loop goes trought every string in the array and checks for matches.

<b>Expected result:</b>
The for-loop goes trough every string in the array and the if-loop checks for matches, if it matches it prints "Access granted".

``` c++ 
String accessGranted[2] = {"7b f9 37 1b", "04 47 06 fa 9f 59 80"}; 
int accessGrantedSize = 2;                            
void checkAccess(String temp) {
  boolean granted = false;
  for (int i = 0; i <= (accessGrantedSize - 1); i++)
  {
    if (accessGranted[i] == temp.substring(1)) 
    {
      Serial.println("Access Granted: ");
      // Access Granted code
    }
  }
}
```

<b>Result: <span style="color:green">Successful</span></b><br>
The for-loop goes trough every string in the array and the if-loop checks for matches, when it matches it prints "Access granted".

##  Testcase #5

<b>Tester:</b> simialfa03
<b>Date:</b> 05.06.22
<b>Description:</b> 
If UID in the temp variable matches string with UID, it will print out the owner. 

<b>Expected result:</b>
If the UID in the temp variable matches "7b f9 37 1b", it will print "Identified as: Simi".

``` c++ 
void checkAccess(String temp) {
      ....
 if (temp.substring(1) == "7b f9 37 1b"){   
        Serial.println("Identified as: Simi");      
      }
      ....
}
```

<b>Result: <span style="color:green">Successful</span></b><br>
The UID in the temp variable matches "7b f9 37 1b", it prints in the Serialmonitor "Identified as: Simi".


##  Testcase #6

<b>Tester:</b> simialfa03
<b>Date:</b> 05.06.22
<b>Description:</b> 
Checking if Servo opens and green LED sequence starts, when access is granted. 

<b>Expected result:</b>
If access is granted, the servo goes to his open state and LED starts green sequence. 

``` c++ 
Servo lockServo;   
int lockPos = 15;   
int unlockPos = 75; 
boolean locked = true; 

int redLEDPin = 3;  
int greenLEDPin = 4;
int blueLEDPin = 5;

 if (locked == true) 
      {
        lockServo.write(unlockPos); 
        locked = false; 
      }
      else if (locked == false) 
      {
        lockServo.write(lockPos);
        locked = true;
      }
      digitalWrite(greenLEDPin, HIGH);
      delay(200);
      digitalWrite(greenLEDPin, LOW);
      delay(200);
      digitalWrite(greenLEDPin, HIGH);
      delay(200);
      digitalWrite(greenLEDPin, LOW);
      delay(200);
```

<b>Result: <span style="color:green">Successful</span></b><br>
Access is granted, the servo goes to his open state and LED starts green sequence. 

##  Testcase #7

<b>Tester:</b> simialfa03
<b>Date:</b> 05.06.22
<b>Description:</b> 
Checking if Servo closes and red LED sequence starts, when access is denied. 

<b>Expected result:</b>
If access is denied, the servo goes to his open state and LED starts red sequence. 

``` c++ 
Servo lockServo;   
int lockPos = 15;   
int unlockPos = 75; 
boolean locked = true; 

int redLEDPin = 3;  
int greenLEDPin = 4;
int blueLEDPin = 5;

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
```

<b>Result: <span style="color:green">Successful</span></b><br>
Access denied, the servo closes and the LED start red sequence. 

##  Testcase #8

<b>Tester:</b> simialfa03
<b>Date:</b> 05.06.22
<b>Description:</b> 
Checking if every access attempt is protocoled. 

<b>Expected result:</b>
Any Access is protocoled in the serial monitor. 

``` c++ 
  if (accessGranted[i] == temp.substring(1)) 
    {
      Serial.println("Access Granted: ");
    }
      ...
      if (temp.substring(1) == "7b f9 37 1b"){ 
      Serial.println("Identified as: Simi");      
      }
      ...
    if (granted == false) // If the tag is not found
  {
    Serial.println("Access Denied");
  }
```

<b>Result: <span style="color:green">Successful</span></b><br>
Any access gets protocoled in the serial monitor, where you can also see the timestamp. 