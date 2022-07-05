# About
This Repository contains Information of a Arduino (RFID Door Lock) school project. 
The Arduino is able to scan RFID cards in order to unlock a 3D printed doorlock. 
Feel free to use the code for your projects. 

## Requirements
- [Arduino arduino mkr 1010](https://www.amazon.com/-/de/dp/B07FYFF5YZ/ref=sr_1_1?keywords=arduino+mkr+wifi+1010&qid=1656406329&sprefix=arduino+mkr%2Caps%2C153&sr=8-1)
- [RFID Reader & Badge](https://www.amazon.com/-/de/dp/B01CSTW0IA/ref=sr_1_2?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1YQEUCWFZ2IZD&keywords=arduino+rfid&qid=1656406347&sprefix=arduino+rfi%2Caps%2C146&sr=8-2)
- [Servo](https://www.amazon.com/gp/product/B07MLR1498/ref=as_li_tl?ie=UTF8&camp=1789&creative=9325&creativeASIN=B07MLR1498&linkCode=as2&tag=mklements-20&linkId=63a97680f3787d087be345410cd59158)
- [RGB LED](https://www.amazon.com/-/de/dp/B077XGF3YR/ref=sr_1_1?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2CYUPMETPM8GS&keywords=RGB%2Bled%2Barduino&qid=1656406421&sprefix=rgb%2Bled%2Barduino%2Caps%2C131&sr=8-1&th=1)
- Cables & Resistor

<b>Optional:</b>

- [3D Printer](https://www.amazon.com/-/de/dp/B094F65V3F/ref=sr_1_4?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=7Z6BSY639093&keywords=3d+printers+ender+3&qid=1656406451&sprefix=3d+printers+ender+%2Caps%2C196&sr=8-4)

- [Breadboard](https://www.amazon.com/-/de/dp/B073X7GZ1P/ref=sr_1_1?crid=2CL3V57MRGASD&keywords=arduino+breadboard&qid=1656406466&sprefix=arduino+bre%2Caps%2C157&sr=8-1) 
Organigramm_RFID.drawio

## SMART objectives 
- The Arduino can read UIDs of a RFID card
- The RGB led glows green when access granted
- The RGB led glows red when access not granted
- We can put the RFID Card UIDs in a array
- We can assign the UIDs to a person
- The servo opens door if access granted
- The servo closes door if access not granted
- The RGD led and the servo are going through startup sequence on startup
- Any access attempt is protocoled in the serial monitor, also the result
- Servo is attached to lock mechanism

<b> Non Functional objectives: </b>
- Endresult is not attached to real door, because its only a demonstration
- Endresult is not constructed and purposed to be deployed for security reasons, its only a functional demonstration


# RFID
RFID id stands for "radio-frequency identification” and refers to a technology where digital data encoded in RFID tags or smart labels are captured by a reader via radio waves. An advantages of RFID is that the RFID tag data can be read outside the line-of-sight, whereas barcodes must be aligned with an optical scanner. 

A RFID systems consist of three comoponents: an RFID tag or smart label (badge), an RFID Reader and an antenna.  RFID tags contain an integrated circuit and an antenna, which are used to transmit data to the RFID reader. The reader then converts the radio waves to a more usable form of data (UIDs). Information collected from the tags is then transferred through a communications interface to a host computer system (in Our Example the Arduino), where the data can be stored in a database and analyzed at a later time.

# Arduino 
Before we start the project, we have to know what Arduino actually is. 
Arduino is a open-source platform used for building electronics, mostly for educational purpose. Arduino consists of both a physical programmable circuit board and a piece of software, or IDE that runs on your computer, used to write and upload code to the arduino board. 

## Our Arduino RFID project 
Our Arduino RFID Doorlock Project is based on [MICHAEL KLEMENTS RFID Doorlock Tutorial](https://www.the-diy-life.com/arduino-based-rfid-door-lock-make-your-own/). We changed it a little bit and created a slightly different code, using the mfrc522 library instead of his RFID library. 

### Circuit Tables


| RFID RC-522  PIN |  Arduino MKR1010 PIN |  Description |
| ------------- |:-------------:| -----:|
| 3.3V         | VCC            | operating voltage 3.3 V| 
| RST           | 6             |   Digital Port 6       |
| GND           | GND           |    Ground              |
| MISO          | 10            |    Digital Port 10     |
| MOSI          | 8             |    Digital Port 8      |
| SCK           | 9             |    Digital Port 9      |
| SCA           | 11            |    Digital Port 11     |

| RGB LED       |  Arduino MKR1010 PIN |  Description |
| ------------- |:-------------:| -----:|
| RED           | 3             |   RED LED              | 
| Green         | 4             |   Green LED            |
| Blue          | 5             |   Blue LED             |
| GND           | GND           |   Ground               | 

| Servo         |  Arduino MKR1010 PIN |  Description |
| ------------- |:-------------:| -----:|
| 5V | RED      | 5V            | operating voltage 5 V| 
| GND| Black    | GND           |   Ground             |
| Orange        | 2             | Digital Port 2       |  

### Circuit scheme


## Lock mechanism
The lock mechanism is based on this [sliding lock design](https://www.thingiverse.com/thing:1596180) by Sagittario which was scaled down to 65% of the original size.

Download 3D Print Files: [3D Printfiles](/printfiles/3D-Print-Files.zip)

If you don't have a 3D Printer, you can use any standard bolt type sliding lock. 

## Code flowchart

![Organigram](/image/Organigramm_RFID.png "Organigram")

## Testcases 
| Testcase      | Description   |   Result             |
| ------------- |:-------------:| --------------------:|
| LED Sequence  | Testing Cabling of LED and Sequence:  ``` int redLEDPin = 3;  int greenLEDPin = 4;  int blueLEDPin = 5;   void setup(){  pinMode(redLEDPin, OUTPUT);  pinMode(greenLEDPin, OUTPUT);  digitalWrite(redLEDPin, HIGH);   delay(200);   digitalWrite(greenLEDPin, HIGH);   delay(200);   digitalWrite(redLEDPin, LOW);   delay(200);   digitalWrite(greenLEDPin, LOW);  }  ``` | Works good
| Servo | Testing Servo movements:  <code> Servo lockServo;  int lockPos = 15;  int unlockPos  = 75;  boolean locked = true; </code>

## Project reflection
The project was pretty fun and we have learned a lot of new things about the arduino and how microcontroller and microprocessor works. 
We had some Issues with the code and the cabling, but we managed to solve them together with our teacher. The most difficult one was the for-loop where the UID of the RFID-Card is printed. We could not manage to put the UID string into the variable temp, but at the end we managed to resolve this by using concat to join the string together in the variable. 
