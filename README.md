# Smart LPG Gas Leak Detection & Cylinder Monitoring System

## Overview

This project is a smart LPG safety and monitoring system designed for homes and restaurant kitchens. It helps detect LPG gas leaks, automatically shut off the gas supply, and monitor the LPG cylinder weight to estimate when the cylinder may need to be refilled.

The system uses an ESP32 microcontroller to collect sensor data, control the gas valve, trigger local alarms, and send notifications through a connected cloud service.

## Key Features

- Real-time LPG gas leak detection using an MQ-6 gas sensor.
- Automatic gas supply shutoff using a motorized ball valve.
- LPG cylinder weight monitoring using a load cell and HX711 amplifier.
- Weight data filtering to provide stable readings.
- Low-gas alerts when the cylinder level becomes low.
- Local audio and visual alerts using a buzzer and LED.
- Wi-Fi connectivity for remote monitoring and notifications.
- Battery backup support for safer operation during power failures.

## Technology Stack

- **Microcontroller:** ESP32
- **Firmware:** Arduino C/C++
- **Gas Sensor:** MQ-6
- **Weight Sensor:** Load Cell
- **Load Cell Amplifier:** HX711
- **Gas Valve:** 12V Motorized Ball Valve
- **Alert:** Piezo Buzzer and LED
- **Connectivity:** Wi-Fi
- **Cloud/Notifications:** MQTT / Firebase / Notification API
- **Development:** Arduino IDE or PlatformIO

## How It Works

1. The MQ-6 sensor continuously monitors the surrounding area for LPG gas.
2. If the detected gas level exceeds the configured safety threshold, the ESP32 activates the alarm.
3. The motorized ball valve is triggered to stop the LPG supply.
4. The load cell continuously measures the cylinder weight through the HX711 module.
5. The ESP32 filters the weight readings to reduce sensor noise and drift.
6. When the LPG level becomes low, the system sends a notification to the user.
7. Sensor data can be sent to a cloud platform for remote monitoring.

## Basic System Flow

```text
MQ-6 Gas Sensor ──┐
                   │
Load Cell ── HX711 ├──> ESP32 ──> Wi-Fi ──> Cloud / Notifications
                   │
                   ├──> Buzzer / LED
                   │
                   └──> Motorized Ball Valve
```

## Project Goals

- Improve LPG safety in kitchens.
- Reduce the risk of fire or explosion caused by gas leaks.
- Automatically isolate the gas supply during dangerous conditions.
- Provide early warnings before an LPG cylinder becomes empty.
- Enable convenient remote monitoring and notifications.

## Future Improvements

- Mobile application for live monitoring.
- More accurate LPG consumption and depletion-date prediction.
- Advanced gas-sensor calibration and false-alarm filtering.
- Battery health monitoring.
- Data logging and usage analytics.
- Integration with smart-home platforms.

## Disclaimer

This project is intended as an educational/prototype system. LPG gas systems are safety-critical. Any real-world installation should use appropriately certified gas components, professional installation, and independent safety mechanisms.
