
BRAC UNIVERSITY
CSE461: Introduction to Robotics
Lab Project Report 
Title: [Home Security & Automation System ]
by

[Section-02]
Group Members: 
Name
ID
[A. K. M Foyshal Sarkar ]
[22201686 ]

Department of Computer Science and Engineering
BRAC University
[8-9-2025]
Abstract

This project aims to create a multifunctional home security system and automation system  to improve the safety and also energy efficiency.In this robotic system we have used Arduino Uno and ESP32 controllers with different sensors including RFID,PIR,Raindrop sensor,temperature sensor,flame sensor. RFID based door system  enhance the home security,Flame sensor detect fire and send alert ,PIR sensor reduce energy wastes by controlling fan,raindrop sensors active servo motor to retrieve cloths from being wet.The methodology enclose a modular architecture,the system is programmed in C++ via Arduino IDE and the assimilation of IOT for remote alert system.Final result establish a promising autonomous operation of all main functionalities including proving a effective security,sending fire alert and promote to sustainable use of energy. .This home automation system robots impact mainly lies in cost effectiveness,scalable architecture ,and high potential to improve safety systems in smart homes.
Keywords
[3 - 5 keywords, “microcontroller, automation, IoT, sustainability, Iot,Security System ,sustainability ”]
1. Introduction:
The increasing requirements for home security and sustainable energy consumption has facilitated the implementation of home security systems.This project is motivated by the need for affordable home security with simple integrated hardware and software systems.The primary objective of the project is to create a home security system that integrates different actuators with multiple sensors to enhance the security , environmental monitoring ,automated appliance control.In this system the scope comprise interfacing sensors and actuators with microcontrollers.A fundamental principle of robotics and computer interfacing is to create an intelligent system that is able to solve real problems by taking sensory inputs from the environment

2. Related Work/ Inspiration:
Home automation system is a common robotic system now a days but most often is it works in specific aspects like security door system These are typically designed in specific domain like climate or security or lighting .Combining Smart door with camera module in commercial and control climate or lightning creates complex expensive product which is  not affordable for middle class people that  motivates me to work in this project and make this system in affordable price with more functionalities  by combining fire detection,rain sensing,energy efficient human detection and light \fan controlling with less cost.
From existing projects our system is different in holistic integration and multi functional cohesion .Instead of using separated devices for multiple functions we have merged the system with diverse tasks in a synchronous way  . By using Cross functional logic the system is able to make decision depending on the sensors combining the functionalities of specific sensors like  PIR sensor works for both  light control and fan activation instead of only light control and the speed of the fan can be controlled by the temperature sensor.Unlike fragmented solution our project creates a single integrated system that perform  multiple tasks at a time

3. Technical Approach
System Architecture: .


Workflow (Functionality 2,4,5)



Workflow(Functionality 1 and 3)





Components Used:

Hardware
Arduino Uno: Arduino Uno is the main microcontroller of our project that is used to control the actuators and the sensor.It works based on the input signals and after processing the output signals send to the motors
ESP32 cam Module:Another controller that is working on wifi and camera for the alert system,sending pictures to the mobile  through the wifi protocols   when fire is detected and an unauthorized person wants to enter.
Servo Motor: Servo motor works on PWM method,It is  used to rotate in an angle.It Controls door lock & cloth rod movement.
DC Motor: DC motor mainly converts electrical energy  into mechanical rotation which is used in the fan system, It activates the fan from getting the signal from PIR  and temperature sensors.Here DC motor is controlled by motor driver L298N
 RFID Sensor: Used for door access authentication.It is used radio frequency.
PIR Sensor:Used to detect human movement by infrared radiation  emitted from human body and control fan light activation system
Flame Sensor: Detects fire hazards and IR light increase and turns the buzzer on and triggers ESP alert .
Temperature Sensor: Measure room temperature and convert them into electrical signals,Arduino compares the input signal with the threshold  and activates the fan .
Raindrop Sensor: sense the  rainfall and take steps for  cloth protection.
LDR Sensor: Measures ambient light ,In dark places, the resistance is high which creates low output voltage and in bright the resistance is low, which creates the high output voltage for smart lighting.
Buzzer: Arduino controls the buzzer by sending high signal to activate the alerts on unauthorized access and fire.
Breadboard, Jumper Wires, Resistors, Battery,multimeter etc are the some basic components of the projects.


Software
Embedded C / Arduino C++: Programming language.
ESP32 cam  Libraries (Wi-Fi,  Blynk): For notification 
system.
Tinkercad: For circuit design & simulation.


Circuit/Schematic: Provide diagrams.





Functionality:
In our home security system project ,we are working on 5 functionality.The working procedure is given below.
Step 1:The RFID sensor scans the RFID card and if the card is authenticated the servo motor will open the door for the person .If not ,an alert will be sent to the owner of the house and if the owner wants to enter the person ,the owner will send “open door” message and servo will open the door .
Step2: After entering the house ,the PIR sensor detect the human and turn the fan on  by using servo motor and if the person leave the place the fan will again turn off
Step3-If any unwanted fire occurs in the house,flame sensor detects the fire and buzzer will be activated and also a message will be sent to the registered number  by esp module.
Step4-When rainfall starts,the rain sensor detects the rain and the servo motor rotates the cloth stick and protects the cloth from getting  wet.
Step5-By using LDR sensors ambient light level is observed and when it's dark the system turns on the light and also if a human is detected the brightness of the light will increase.
Challenges:We have faced different types of challenges to make this project
Technical Challenges:
1.Component Change- We decided to use an ESP32 cam but it does not have enough ports so we decided to shift to ESP32.
2.Sensors Regulation-Different sensors has different sensitivity,it was difficult to merge them after testing
3.Power supply Issue-Arduino operates in 5V but ESP32 operates in 3.3v.These different voltage ranges also created issues.
Integration challenges:
1.Power failure-TThe charge of the 9v  battery was finished multiple times which creates issue when using Dc motor
2.Temperature sensor fluctuation-It was very difficult to have a proper signal from the temperature  sensor because of circuit noise.
Budget Limitation:We are supposed to do an impactful robotic system at minimum cost.So we had to minimize many components like extra batteries,motors,breadboard etc.



4. Sustainability & Impact

Sustainability:The  project focus on energy efficiency by automatically control the fan and light when no human available in the room that save electricity.Using of dc motor efficient than using AC fan.In this project multiple components is used which are useable 
Impact:This project has strong impact on users for increasing the safety and immediate alert after detecting fire which make user more reliable on this system.Moreover automating tasks helps the elder people  .Finally its affordable price make people achieve this system without hampering their daily life
Future Work:This project can be more functional in future by including mobile app for control,solar power integration,adding more sensors and include machine learning models on sensor to predict behavior
Limitations:The short range of RFID,setup of Arduino Uno which has some restriction in adding components,limited wifi range of ESP32 are some limitations of this system were observed despite the successful implementation of the project
5. Results & Discussion


Testing outcomes:
1 RFID sensor
Test


Expected Outcome
Actual Outcome
Result
1.Authorized card
Servo open the door
Door open Successfully
Correct
2.Unauthorized card
RFID send alert
Send alert successfully
-Remaining the door close(No message form the owner)
Correct


3,Unauthorized card
RFID send alert
Send alert successfully
-Open the door(If “Open Door” message is send from the owner)
Correct
3. NO card
No action
No action
Correct


2.Flame sensor


Test
Expected outcome
Actual outcome
duration
1.Flame present
Flame detect and send alert
Flame detect and send alert 
5s
2.No flame
No response
No response





3.Rain sensor 
Test
Expected outcome 
Actual Outcome
Result
1.Rain
Servo rotates
Servo rotates
Protect cloth
2.No rain
No response
No response
Keep as it is


4.PIR sensor 

Test
Expected output 
Actual output
Motion detect
Servo control fan
Servo response
No motion detect
No response
No reason


Result  : All the functionalities performed perfectly.Unauthorized card is detected and send alert,fire alert is send , fan control is working, light automation is controlled,and rain drop sensor is also responding.Overall the project is reliable for people and it takes vary less time to response  .The efficiency of this project is high for giving appropriate result for every sensors .     
Discussion:  The home security and automation system  merged multiple sensors and actuators for creating  a smart home.This system confirms the authorized locked system,fire alert system,light and fan control and responsive to the weather.The fast response, make the project more effective.The overall system ensure to use less energy.

6. Conclusion
This project prosperously implemented a cost effective,energy efficient, integrated Home security and	 automation system.The key achievements of this project is accumulation of different actuators with multiple sensors for establishing a system that manages access control,risk detection,climate control etc.This system proves a small computer can be used to create a safe home using energy efficient tools with less cost.The outcomes ensures that it is a economical, practical ,efficient,effective embedded system that protects dwelling,save energy ,enrich daily activities .   

References

1.RFID RC522 Interfacing with ESP32 | ESP32. (n.d.). © 2018 ElectronicWings. https://www.electronicwings.com/esp32/rfid-rc522-interfacing-with-esp32?fbclid=IwY2xjawMr7ZZleHRuA2FlbQIxMQABHhgN4a6Z2TXRY5CQAImGIvFgqk2lGX0NRIZES-0pdi7F6k74btUQ1O9TZcOR_aem_Fcv42Mme44w3pCtSKLPLXw

2.Upload Ideas With Itamar. (2024, August 3). ESP32 + RFID RC522 Tutorial with LCD Screen (BEGINNER-FRIENDLY) [Video]. YouTube. https://www.youtube.com/watch?v=tDQD2e2tLls

3.Theinfoflux. (2023, November 18). ESP32 CAM send Imges to the Telegram [Video]. YouTube. https://www.youtube.com/watch?v=4YLIVAnBdJk
4.Arduino - Rain sensor - Servo motor | Arduino getting started. (n.d.). Arduino Getting Started. https://arduinogetstarted.com/tutorials/arduino-rain-sensor-servo-motor?fbclid=IwY2xjawMr7u1leHRuA2FlbQIxMQABHpFMpfp8HxwrceyYef1PmdtG2HC5TlBIFYsL2c1KQ4v0UNyTBLwGX6tIMUsQ_aem_Szbn9hsUytHZxcu9lquf4w
5.ESP32 - RFID - Servo Motor | ESP32 Tutorial. (n.d.). ESP32 Tutorial. https://esp32io.com/tutorials/esp32-rfid-servo-motor?fbclid=IwY2xjawMr7x9leHRuA2FlbQIxMQABHqQetIF3VBLKaDgg_Y0nh354k4gkk1AqVDVHaCsOIAm550IRnoYn1lZm1XaE_aem_vZWsQ6mh6z7qzuUaQZE6aw



