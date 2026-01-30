# Smart-BCM: Automotive Window Control & Diagnostic System

## Executive Summary
This project features the development of a functional prototype for an **Automotive Body Control Module (BCM)**, specifically focused on a **Power Window System**. Utilizing an **ESP32** microcontroller, the system integrates mechatronic actuator control with a robust self-diagnostic algorithm and environmental monitoring.

The software architecture was designed under **Safety-Critical System** principles, prioritizing hardware safety and passenger integrity through proactive data bus failure detection.



---

## Technical Stack
* **Microcontroller:** ESP32 DevKit V1 (Dual-Core, 240MHz).
* **Language:** Embedded C++ (Object-Oriented Programming).
* **Sensors/Actuators:** * DHT22 (Cabin environment sensor).
    * Servo Motor (Torque actuator simulation for window movement).
    * 16x2 LCD (Human-Machine Interface / HMI).
* **Simulation:** Wokwi Embedded Systems Simulator.

---

## System Architecture & Logic
The system operates via a **Finite State Machine (FSM)** architecture to ensure deterministic behavior in vehicle operations:

1.  **Health Monitor Module:** Prior to any physical execution, the system validates the integrity of the DHT22 sensor signal. If a null value (`NaN`) is detected, the system enters a **Safety Lockout** state.
2.  **Comfort Module:** If internal cabin temperature exceeds **30.0°C**, the system automatically triggers the actuator for forced ventilation.
3.  **HMI Module:** Provides real-time reporting of window status and diagnostic alerts on the LCD screen.



---

## Safety & Diagnostics Matrix
To comply with automotive quality standards, the following event matrix was implemented:

| Detected Event | Fail-Safe Action | Visual Indicator |
| :--- | :--- | :--- |
| DHT22 Signal Loss | Mechatronic operation suspension | Red LED (D2) + LCD Alert |
| Temp > 30.0°C | Controlled window opening | Status: OPEN on LCD |
| System Integrity OK | Standard operation enabled | Green LED (D14) |

---

## Circuit Design (Pinout)
| Component | ESP32 Pin | Function |
| :--- | :--- | :--- |
| **Servo PWM** | D13 | Window position control |
| **DHT22 Data** | D15 | Environmental data bus |
| **Red LED** | D2 | Critical Failure Alert |
| **Green LED** | D14 | Status: System OK |
| **LCD RS/E** | D19 / D18 | Parallel data bus control |
| **LCD D4-D7** | D27, D26, D25, D33 | Interface data bus |



---

## How to Run
1.  Import the `sketch.ino` file into **Wokwi**.
2.  Install the required libraries via the Library Manager:
    * `LiquidCrystal`
    * `DHT sensor library`
    * `ESP32Servo`
3.  Run the simulation and manipulate the DHT22 sensor to observe the system's diagnostic response.

---
**Developed as a professional residency preparation project for the Automotive Sector.**
