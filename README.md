# About
This Repository contains Information of a Arduino (RFID Door Lock) school project. 
The Arduino is able to scan RFID cards in order to unlock a 3D printed doorlock. 
Feel free to use the code for your projects. 

## Requirements
- [Arduino arduino mkr 1010]()
- [RFID Reader & Badge]()
- [Servo]()
- [RGB LED]()
- Cables & Resistor
<br>Optional:</br>
- [3D Printer]()
- []() 

# RFID
RFID id stands for "radio-frequency identification” and refers to a technology where digital data encoded in RFID tags or smart labels are captured by a reader via radio waves. An advantages of RFID is that the RFID tag data can be read outside the line-of-sight, whereas barcodes must be aligned with an optical scanner. 

A RFID systems consist of three comoponents: an RFID tag or smart label (badge), an RFID Reader and an antenna.  RFID tags contain an integrated circuit and an antenna, which are used to transmit data to the RFID reader. The reader then converts the radio waves to a more usable form of data (UIDs). Information collected from the tags is then transferred through a communications interface to a host computer system (in Our Example the Arduino), where the data can be stored in a database and analyzed at a later time.

# Arduino 
Before we start the project, we have to know what Arduino actually is. 
Arduino is a open-source platform used for building electronics, mostly for educational purpose. Arduino consists of both a physical programmable circuit board and a piece of software, or IDE that runs on your computer, used to write and upload code to the arduino board. 

## Our Arduino RFID project 
Our Arduino RFID Doorlock Project is based on [MICHAEL KLEMENTS RFID Doorlock Tutorial](https://www.the-diy-life.com/arduino-based-rfid-door-lock-make-your-own/). We changed it a little bit and created a slightly different code. 

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


## Lock mechanism
The lock mechanism is based on this [sliding lock design](https://www.thingiverse.com/thing:1596180) by Sagittario which was scaled down to 65% of the original size.

Download 3D Print Files: [3D Printfiles](/printfiles/3D-Print-Files.zip)

If you don't have a 3D Printer, you can use any standard bolt type sliding lock. 

## Code 