# About
This Repository contains Information of a Arduino (RFID Door Lock) school project. 
The Arduino is able to scan RFID cards in order to unlock a 3D printed doorlock. 
Feel free to use the code for your projects. 

## Requirements



# RFID
RFID id stands for "radio-frequency identification” and refers to a technology where digital data encoded in RFID tags or smart labels are captured by a reader via radio waves. An advantages of RFID is that the RFID tag data can be read outside the line-of-sight, whereas barcodes must be aligned with an optical scanner. 

A RFID systems consist of three comoponents: an RFID tag or smart label (badge), an RFID Reader and an antenna.  RFID tags contain an integrated circuit and an antenna, which are used to transmit data to the RFID reader. The reader then converts the radio waves to a more usable form of data (UIDs). Information collected from the tags is then transferred through a communications interface to a host computer system (in Our Example the Arduino), where the data can be stored in a database and analyzed at a later time.

# Arduino 
Before we start the project, we have to know what Arduino actually is. 
Arduino is a open-source platform used for building electronics, mostly for educational purpose. Arduino consists of both a physical programmable circuit board and a piece of software, or IDE that runs on your computer, used to write and upload code to the arduino board. 

## Our Arduino RFID project 


### Circuit

| RFID RC-522  PIN |  Arduino MKR1010 PIN |  Description |
| ------------- |:-------------:| -----:|
|  3.3V         | VCC           | operating voltage 3.3 V| 
| RST           | 6             |   Digital Port 6       |
| GND           | GND           |    Ground              |
| MISO          | 10            |    Digital Port 10     |
| MOSI          | 8             |    Digital Port 8      |
| SCK           | 9             |    Digital Port 9      |
| SCA           | 11            |    Digital Port 11     |

## Lock mechanism
