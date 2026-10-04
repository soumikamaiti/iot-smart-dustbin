# IoT-Based Smart Dustbin

## Project Overview

The IoT-Based Smart Dustbin is a smart waste-management system designed to reduce direct contact with the dustbin and make waste disposal more convenient. The system uses an ESP32 microcontroller, an ultrasonic sensor, and a servo motor.

The ultrasonic sensor detects objects near the dustbin. When a hand is detected within the specified distance, the ESP32 controls the servo motor to automatically open the lid. After a short delay, the lid closes automatically.

The ESP32 also provides Wi-Fi connectivity, making the system suitable for future IoT-based monitoring and smart waste-management applications.

## Objectives

- To design an automatic and contactless dustbin system.
- To detect objects using an ultrasonic sensor.
- To automatically open and close the dustbin lid.
- To use ESP32 as the main controller.
- To provide Wi-Fi connectivity for IoT-based applications.
- To explore the practical use of IoT in waste management.

## Hardware Used

- ESP32 Development Board
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- Dustbin Container
- Breadboard
- Jumper Wires
- USB Cable

## Software Used

- Arduino IDE
- C/C++
- ESP32 Board Support
- ESP32Servo Library

## Working Principle

1. The ultrasonic sensor continuously measures the distance of objects near the dustbin.
2. The ESP32 receives the distance value from the sensor.
3. If an object is detected within the defined range, the ESP32 activates the servo motor.
4. The servo motor rotates and opens the dustbin lid.
5. After a short delay, the servo motor returns to its original position.
6. The lid closes automatically.
7. The ESP32 can connect to Wi-Fi for future IoT monitoring and data communication.

## Pin Connections

| Component | Pin | ESP32 Pin |
|---|---|---|
| Ultrasonic Sensor | TRIG | GPIO 5 |
| Ultrasonic Sensor | ECHO | GPIO 18 |
| Ultrasonic Sensor | VCC | 5V |
| Ultrasonic Sensor | GND | GND |
| Servo Motor | Signal | GPIO 19 |
| Servo Motor | VCC | 5V |
| Servo Motor | GND | GND |

## Project Features

- Automatic lid operation
- Contactless waste disposal
- Ultrasonic distance detection
- ESP32-based control
- Wi-Fi connectivity
- Simple and low-cost design
- Suitable for smart waste-management applications

## Project Structure

```text
iot-smart-dustbin/
│
├── smart_dustbin.ino
│
└── README.md
