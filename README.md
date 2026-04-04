# Smart BCM: Automotive Window Control System 🚗⚙️

## Executive Summary

This project features the development of an embedded firmware architecture simulating an automotive **Body Control Module (BCM)** dedicated to smart window actuation. The system bridges digital logic with physical hardware, providing reliable, deterministic control over DC motors while prioritizing user interaction and safety.

Designed with automotive engineering principles in mind, the system implements a robust state machine to handle concurrent inputs, ensuring fluid operation across different window control modes (manual, auto-up, auto-down) and maintaining strict hardware safety tolerances.

## Technical Specifications

* **Core Logic Language:** [Insert Language, e.g., C / C++ / MicroPython]
* **Microcontroller Unit (MCU):** [Insert Hardware, e.g., ESP32 / STM32 / Arduino Uno]
* **Hardware Interfacing:** [Insert Actuators/Drivers, e.g., L298N Motor Driver / Relays / DC Motors]
* **Architecture:** Event-driven state machine with hardware interrupts and debounced input handling.

---

## System Architecture & Logic Flow

The BCM operates through a highly structured loop to ensure zero-latency response to user commands while monitoring hardware states:

1. **Input Acquisition Layer:** Reads digital signals from physical switches (Up/Down commands) utilizing software/hardware debouncing techniques to prevent phantom triggers.
2. **Control Logic Layer (The BCM):** Processes inputs through a deterministic state machine. It evaluates current window position, user commands, and active safety flags before authorizing motor movement.
3. **Actuation Layer:** Translates logic states into PWM (Pulse Width Modulation) or digital signals directed to the motor drivers, managing polarity for bidirectional motor control.

---

## Operational State Matrix

To mimic real-world automotive standards, the system's logic responds to the following interaction matrix:

| User Input / Event | System State | Hardware Action |
| :--- | :--- | :--- |
| **Short Press (Up/Down)** | Auto-Mode Triggered | Continuous motor actuation until end-stop is reached |
| **Long Press / Hold** | Manual Mode Active | Motor actuates only while the switch remains engaged |
| **Opposite Direction Pressed** | Interrupt & Halt | Motor stops immediately to prevent hardware damage |
| **[Optional: Current Spike]** | [Anti-Pinch Safety Flag] | [Motor reverses direction to prevent injury/obstruction] |

---

## Hardware Pinout & Wiring (Abstract)

*Modify this table according to your exact physical schematic:*

| Component | MCU Pin | Function |
| :--- | :--- | :--- |
| **Window Switch UP** | `[e.g., GPIO 4]` | Digital Input (Pulled High/Low) |
| **Window Switch DOWN** | `[e.g., GPIO 5]` | Digital Input (Pulled High/Low) |
| **Motor Driver IN1** | `[e.g., GPIO 18]` | Digital Output (Motor Forward/Up) |
| **Motor Driver IN2** | `[e.g., GPIO 19]` | Digital Output (Motor Reverse/Down) |

---

## How to Flash & Run

1. Clone the repository to your local environment:
   ```bash
   git clone [https://github.com/HJLeslye/Smart-BCM-Automotive-Window-Control.git](https://github.com/HJLeslye/Smart-BCM-Automotive-Window-Control.git)
   ```
2. **Hardware Setup:** Wire the MCU, motor drivers, and switches according to the schematic defined in the project files.
3. **Compilation & Flashing:** 
   * Open the project in your IDE (e.g., [Insert IDE, e.g., Arduino IDE / PlatformIO]).
   * Select the appropriate target MCU board and COM port.
   * Compile and upload the firmware.

---

## Contact Details

> **Leslye Hernández Jiménez**
> *Engineering in Information and Communication Technologies*
>
> **LinkedIn**: [View Profile](https://www.linkedin.com/in/leslye-hern%C3%A1ndez-jim%C3%A9nez-5559403a6/)
> **Email**: [hdezj.leslye@gmail.com](mailto:hdezj.leslye@gmail.com)

---
*Developed as an engineering prototype for automotive embedded systems.*
