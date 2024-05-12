Introduction: 
Welcome to the "Smart Room" project, an initiative developed as part of the academic requirements of the Microprocessors class. The concept of a smart room arises with the aim of simplifying the daily activities of the inhabitants of the home, allowing them to control various functions from anywhere within the house. This project focuses on creating an automated and adaptive environment, incorporating technologies such as a 12V LED light, a temperature-controlled fan and a servo motor for opening and closing the window. In this introduction, we will explore the overall design of the system, present a flowchart to understand its operation, and discuss the coding used for its implementation. Through this comprehensive approach, we seek to improve the quality of life of users by simplifying daily tasks and providing greater comfort in the home.

 Design 
a)	Components 
1.	1 Arduino Uno
2.	2 resistors of 1k ohms 
3.	1 resistor of 12k ohms 
4.	1 Photocell
5.	1 DTH11 temperature sensor
6.	2 NPN transistors (PN2222)
7.	1 Diode Rectifier 
8.	1 Servomotor (SG90)
9.	1 DC Fan 12v 
10.	1 Led Light 12v 
11.	1 External 12v Power Supply 
12.	1 LCD Display 20x4 

Initial configuration:
Serial communication is established at 9600 baud.
Initialize the sensors and servo motor.
The LCD is configured to display temperature, humidity and light.
The input and output pins for the photoresistor and LED, respectively, are set.
Main loop:
A time of 2 seconds is waited before measurements are performed again.
The temperature and humidity values are read using the DHT11 sensor.
The light intensity is read through the photoresistor.
Check if the readings are valid (if they are not NaN, i.e. not invalid values).
Temperature, humidity and light values are displayed on the LCD and printed out through the serial port for debugging purposes.
The fan speed is controlled based on the temperature:
If the temperature is greater than or equal to the high threshold, the fan speed is set to the maximum (255).
If the temperature is between the low threshold and the high threshold, the fan speed is set to half its capacity (127).
If the temperature is lower than the low threshold, the fan is switched off (0).
The servo motor is controlled to open or close the window according to the temperature:
If the temperature is greater than or equal to the high threshold, the window is opened (position 180 degrees).
If the temperature is between the low threshold and the high threshold, the window closes (position 90 degrees).
If the readings are not valid, an error message is displayed on the LCD and a message is printed by the serial port.
The LED intensity is controlled based on the photoresistor reading:
If the light intensity is greater than 380, the LED is turned off.
If the light intensity is less than or equal to 380, the LED intensity is adjusted according to the value read from the photoresistor.






