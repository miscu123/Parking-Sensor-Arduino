# Parking-Sensor-Arduino 🚗🔊

This project implements a parking sensor system using an Arduino, an ultrasonic sensor, and LED indicators.
It’s designed to be installed in cars that don’t come with built-in parking sensors, providing a simple and effective way to detect obstacles while reversing.

## 📋 Features

Uses an ultrasonic sensor (HC-SR04) to measure distance.

Three LED indicators for distance feedback:

🟢 Green LED → Safe distance (> 30 cm)

🟡 Yellow LED → Caution (15 – 30 cm)

🔴 Red LED → Danger (< 15 cm)

Interrupt-based echo reading for accurate distance measurement.

Efficient trigger interval to avoid unnecessary sensor pings.

## 🛠️ Components Required

Arduino Uno / Nano / Mega

HC-SR04 Ultrasonic Sensor

3 LEDs (Green, Yellow, Red)

Resistors (220Ω for each LED)

Jumper wires & breadboard (or custom PCB for installation in a car)

## ⚡ Circuit Connections
Component	Arduino Pin
Ultrasonic Trig	D7
Ultrasonic Echo	D2 (Interrupt)
Green LED	D9
Yellow LED	D10
Red LED	D11

## 📜 How It Works

The Arduino triggers the ultrasonic sensor at set intervals.

The sensor sends out a pulse and waits for the echo.

The interrupt service routine (ISR) captures the time taken for the echo to return.

The distance is calculated in centimeters.

Depending on the measured distance, the system lights up the corresponding LED:

> 30 cm → Green LED ON

15–30 cm → Yellow LED ON

< 15 cm → Red LED ON

## 🚀 Getting Started
1. Clone this repository

2. Open in Arduino IDE

Open Distance_sensor.ino in Arduino IDE.

3. Select your board & port

Go to Tools > Board → Choose your Arduino model.

Go to Tools > Port → Select the correct COM port.

4. Upload the code

Click Upload and wait for it to compile & flash.

## 🔮 Possible Improvements

Add a buzzer for audible feedback.

Use PWM fading LEDs instead of ON/OFF.

Integrate with a car display for digital distance readout.

Make it weatherproof for permanent car installation.

## Demo video

Demo video available in Distance_sensor directory
