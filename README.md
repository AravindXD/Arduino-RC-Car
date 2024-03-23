# Android App Controlled Arduino Uno Based Remote Controlled Car
A simple Arduino-UNO based Remote-controlled car that uses Bluetooth communication for control and features obstacle detection using an Ultrasonic sensor.

![Alt text](https://github.com/AravindXD/Arduino-RC-Car/blob/main/images/NW.jpeg)
## Getting Started

### Hardware Components Required
- [Arduino UNO with PC Connector Cable](https://github.com/AravindXD/Arduino-RC-Car/blob/main/images/Arduino-Uno-Pinout.jpeg)
- [A Chasis with a Front Ball bearing for the Car with Two Wheels at the back](https://github.com/AravindXD/Arduino-RC-Car/blob/main/images/chasis.jpeg)
- [L293D Motor driver IC](https://github.com/AravindXD/Arduino-RC-Car/blob/main/images/L293D-Motor-Driver-IC.jpg) (can also use L298N)
- [HC-05 Bluetooth module](https://github.com/AravindXD/Arduino-RC-Car/blob/main/images/hc051.jpg)
- [Ultrasonic sensor (HC-SR04)](https://github.com/AravindXD/Arduino-RC-Car/blob/main/images/Ultrasonic.png)
- Two [Battery Operated (BO) DC motors](https://www.techtonics.in/image/cache/catalog/images022023/300-rpm-bo-motor-straight-tech8603-7061-1100x1100.webp)
- [Buzzer](https://github.com/AravindXD/Arduino-RC-Car/blob/main/images/buzz.jpeg) to detect Obstacle
- Breadboard for making connections
- A red LED and a green LED to indicating permission for movement
- Jumper Wires and Miscellaneous

### Software Needed
- [Arduino IDE](https://www.arduino.cc/en/software)

  ![Alt text](https://content.arduino.cc/assets/arduino_logo_1200x630-01.png)
  
- [Android Application for Bluetooth Control](https://github.com/AravindXD/Arduino-RC-Car/blob/main/braulio.calle.bluetoothRCcontroller.apk)

  [![Alt text](https://github.com/AravindXD/Arduino-RC-Car/blob/main/images/bluetooth-rc-car-screenshot.png.jpeg)](https://github.com/AravindXD/Arduino-RC-Car/blob/main/braulio.calle.bluetoothRCcontroller.apk)


## Procedure for Implementation
- Connect the hardware components as per the circuit diagram. Click on the image for TinkerCAD file.
  
    [![Alt text](https://github.com/AravindXD/Arduino-RC-Car/blob/main/images/Ard.png)](https://www.tinkercad.com/things/9ShJCWHxFjW-2wheelcar)
  
> [!NOTE]  
> The attached TinkerCAD File does not contain Bluetooth HC-05 Module Connections as TinkerCAD does not support this module

- Upload the [Code](https://github.com/AravindXD/Arduino-RC-Car/blob/main/AACRCC.ino) to the Arduino UNO from your PC
  
- Pair your Android device with the Bluetooth module.
> [!TIP]
> Turn on Bluetooth on your Android Device and Connect to **'HC-05'**. The Default password is usually **1234**.
  
- Open the Android app and connect to the Bluetooth module.

  [![Alt text](https://github.com/AravindXD/Arduino-RC-Car/blob/main/images/bluetooth-rc-car-screenshot_2.jpeg)](https://github.com/AravindXD/Arduino-RC-Car/blob/main/braulio.calle.bluetoothRCcontroller.apk)
  
- Use the app to control the car's movement.
  
  ![Alt text](https://github.com/AravindXD/Arduino-RC-Car/blob/main/images/bluetooth-rc-car-screenshot_4.jpeg)

## Features

- Achieves 2<sup>°</sup> of freedom (X,Y)
- Obstacle detection using the ultrasonic sensor.
- Buzzer alarm on obstacle detection and Red LED Blinks.
  
## Future Scope of the Work

- Implementing speed control for the motors.
- Adding a camera for remote live video streaming.
- Can add IR sensors to achieve line following.
- Using a Multi-Core microcontroller to implement Blinkers , Reverse Sounds , ADAS-testing and much more.

>[!CAUTION]
>- This Project was initially done with L298N but it had more power consumption when compared to L293D. Hence , L293D got an edge in this case.
>- While Uploading the Code to Arduino, if the TX and RX Pin is Connected to the Bluetooth Module, the upload might fail.
>- There is a minumum and maximum range of working for the Ultrasonic Sensor. 

## Credits
- [Android Application](https://bluetooth-rc-car.en.softonic.com/android?ex=RAMP-1768.2)
