# About
This Repository contains Information of an Arduino MKR1010 (RFID Door Lock) school project. 
The Arduino is able to scan RFID cards in order to unlock a 3D printed door lock. 
Feel free to use the code for your projects. 

# Requirements
- [Arduino arduino mkr 1010](https://www.amazon.com/-/de/dp/B07FYFF5YZ/ref=sr_1_1?keywords=arduino+mkr+wifi+1010&qid=1656406329&sprefix=arduino+mkr%2Caps%2C153&sr=8-1)
- [RFID Reader & Badge](https://www.amazon.com/-/de/dp/B01CSTW0IA/ref=sr_1_2?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=1YQEUCWFZ2IZD&keywords=arduino+rfid&qid=1656406347&sprefix=arduino+rfi%2Caps%2C146&sr=8-2)
- [Servo](https://www.amazon.com/gp/product/B07MLR1498/ref=as_li_tl?ie=UTF8&camp=1789&creative=9325&creativeASIN=B07MLR1498&linkCode=as2&tag=mklements-20&linkId=63a97680f3787d087be345410cd59158)
- [RGB LED](https://www.amazon.com/-/de/dp/B077XGF3YR/ref=sr_1_1?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=2CYUPMETPM8GS&keywords=RGB%2Bled%2Barduino&qid=1656406421&sprefix=rgb%2Bled%2Barduino%2Caps%2C131&sr=8-1&th=1)
- Cables & Resistor

<b>Optional:</b>

- [3D Printer](https://www.amazon.com/-/de/dp/B094F65V3F/ref=sr_1_4?__mk_de_DE=%C3%85M%C3%85%C5%BD%C3%95%C3%91&crid=7Z6BSY639093&keywords=3d+printers+ender+3&qid=1656406451&sprefix=3d+printers+ender+%2Caps%2C196&sr=8-4)

- [Breadboard](https://www.amazon.com/-/de/dp/B073X7GZ1P/ref=sr_1_1?crid=2CL3V57MRGASD&keywords=arduino+breadboard&qid=1656406466&sprefix=arduino+bre%2Caps%2C157&sr=8-1) 
Organigramm_RFID.drawio

# SMART objectives 
1. The RGB led and the servo are going through startup sequence on startup
2. The Arduino can read UIDs of an RFID card
3. We can put the RFID Card UID in a string in order to give it to the CheckAcess function
4. We can put the RFID Card UIDs in an array, in order to store them
5. We can assign the UIDs to a person
6. If access granted, the servo opens the door and the LED blinks green
7. If access not granted, the servo closes the door and the LED blinks red
8. Any access attempt is protocoled in the serial monitor

<b> Non Functional objectives: </b>
- Endresult is not attached to real door, because its only a demonstration
- Endresult is not constructed and purposed to be deployed for security reasons, its only a functional demonstration


# RFID
RFID ID stands for "radio-frequency identification??? and refers to a technology where digital data encoded in RFID tags or smart labels are captured by a reader via radio waves. An advantage of RFID is that the RFID tag data can be read outside the line-of-sight, whereas barcodes must be aligned with an optical scanner. 

An RFID systems consist of three components: an RFID tag or smart label (badge), an RFID Reader and an antenna.  RFID tags contain an integrated circuit and an antenna, which are used to transmit data to the RFID reader. The reader then converts the radio waves to a more usable form of data (UIDs). Information collected from the tags is then transferred through a communications interface to a host computer system (in Our Example the Arduino), where the data can be stored in a database and analyzed at a later time.

# Arduino 
Before we start the project, we have to know what Arduino actually is. 
Arduino is an open-source platform used for building electronics, mostly for educational purpose. Arduino consists of both a physical programmable circuit board and a piece of software, or IDE that runs on your computer, used to write and upload code to the Arduino board. 

# Our Arduino RFID project 
Our Arduino RFID Doorlock Project is based on [MICHAEL KLEMENTS RFID Doorlock Tutorial](https://www.the-diy-life.com/arduino-based-rfid-door-lock-make-your-own/). We changed it a little bit and created a slightly different code, using the mfrc522 library instead of his RFID library. You can download the code from here: [RFID-Code](/code/RFID/RFID.ino)

## Circuit Tables
The pins on the RC-522 are sending SPI signals to our Arduino, this is the reason why we have to include the SPI.h library in our code. 

| RFID RC-522  Signal | RFID RC-522  PIN |  Arduino MKR1010 PIN |  Description |
| ------------- | ------------- |:-----------:| ----------------------:|
| Voltage       | 3.3V          | VCC         | operating voltage 3.3 V| 
| SPI RESET     | RST           | 6           |   Digital Port 6       |
| Ground        | GND           | GND         |    Ground              |
| SPI MISO      | MISO          | 10          |    Digital Port 10     |
| SPI MOSI      | MOSI          | 8           |    Digital Port 8      |
| SPI SCK       | SCK           | 9           |    Digital Port 9      |
| SPI SDA       | SDA           | 11          |    Digital Port 11     |

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

## Circuit scheme

![Circuit Scheme Grafical](/image/rfid-schema-v2.drawio.png "Circuit Scheme Colored")
![Circuit Scheme Monochrome](/image/RFID-Schematic_schwarz.drawio.png "Circuit Scheme monochrome")

## Lock mechanism
The lock mechanism is based on this [sliding lock design](https://www.thingiverse.com/thing:1596180) by Sagittario which was scaled down to 65% of the original size.

Download 3D Print Files: [3D Printfiles](/printfiles/3D-Print-Files.zip)

If you don't have a 3D Printer, you can use any standard bolt type sliding lock. 

## Code flowchart

![Organigram](/image/Organigramm_RFID.png "Organigram")

## Testcases 
We have made some Test-cases based on our smart objectives in order to test every component of our project. <br>
You can find the Test-cases here: [Testcases](/testcases/readme.md)

# Project reflection
The project was pretty fun and we have learned a lot of new things about the Arduino and how microcontroller and microprocessor works. We had some Issues with the code especially with the "for loop" that creates our UID for the RFID card. The problem was that we couldn't manage to put the UID into a variable in Order to check the string with the "checkAcess" function, but we managed to solve this problem with concat which joins the strings together in our variable. Another difficulty we had was designing our circuit scheme, because there were not many websites or tools which supported the MKR1010. Therefore, we had to draw it by ourself in draw.io which took us some hours to design everything. 


At the end we managed to create a cool project with our Arduino and we are really proud that everything works fine. At the beginning we were pretty desperate because we couldn't even manage to get the UID from the RFID Card and we didn't know what we are doing wrong, so we tried different codes, different cabling and different ways in the hope that we could get an UID, but fortunately our teacher helped us with one of his codes to get the UID from the scanner, so that we could adjust our script in order to get the UID. We have learned many things during this project not only in the technical way but also that there are many ways to get to the same result in coding and that only testing and experimenting will bring you to your goals. 
We think we've made a great effort to realize this project and we are happy that at the end everything worked perfectly.