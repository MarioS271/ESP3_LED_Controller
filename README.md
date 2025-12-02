# ESP32_LED_Controller

ESP32_LED_Controller is a lightweight LED controller firmware for the **ESP32-C3** microcontroller. It allows you to control a low-side switched LED strip using an **IRL3103 NMOS transistor** with multiple lighting modes.


## Features

* Multiple lighting modes:
  * Fade
  * Strobe
  * Fireplace
  * Police lights
  * Stranger Things effect
* Button-controlled mode switching with debounce
* Mode persistence using NVS (Non-Volatile Storage)
* Modular and extendable task-based architecture


## Hardware

* **Microcontroller:** ESP32-C3
* **LED Strip:** Low-side switched
* **Transistor:** IRL3103 NMOS for switching the LED strip
* **Button:** Input for mode selection


## Usage

* Power on the ESP32-C3 and the LED strip.
* Press the button to cycle through lighting modes.
* The current mode is saved in non-volatile storage, so it persists across resets.


## Code Structure

* `src` – Entry Point
* `lib` - Custom Libraries
* `types` – Custom Types
* `tasks` – Separate FreeRTOS tasks for each mode
* `include` – Includes (like constants)
* `helpers` – Helper Functions like delay, ...