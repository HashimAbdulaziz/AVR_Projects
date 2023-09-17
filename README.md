# Temperature Sensor and DC Motor Control System

![smarthomegif](https://github.com/HashimAbdulaziz/AVR_Projects/assets/88584784/16332944-ebc7-4ca5-876f-ccf7796811a9)

![smarthome2gif](https://github.com/HashimAbdulaziz/AVR_Projects/assets/88584784/9318dac0-4921-4858-9f0a-768bee311ac7)

## Overview

This project is designed to create a temperature-controlled access system using an Atmega 32 microcontroller. It includes components such as a Temperature Sensor (LM35), DC Motor, Keypad, LCD, LEDs, and an Atmega 32 microcontroller. The system allows users to enter a password via the keypad, and upon successful login, they can control LEDs and monitor the temperature.

## Operation

### User Authentication:

1. When the user powers on the system, it displays the message on the LCD: "Please Enter Password."

2. The user enters a password through the keypad.

3. If the user enters the correct password, the system displays a successful login message, such as "Welcome Ahmed."

4. If the user enters an incorrect password, the system displays the message: "Wrong password, please try again."

5. The user has a maximum of 3 attempts to enter the correct password; after that, the system locks for 2 minutes.

### Post-Login:

6. After a successful login, the system displays the following options on the LCD:
   - Option 1: Turn LEDs ON
   - Option 2: Turn LEDs OFF
   - The user can choose to control LEDs using the keypad.

### Temperature Monitoring:

7. The system continuously monitors the temperature sensor (LM35).

8. Temperature Control:
   - If the temperature is less than or equal to 25°C, the DC motor remains off.
   - If the temperature is greater than 25°C but less than 30°C, the DC motor operates at half speed.
   - If the temperature is greater than or equal to 30°C, the DC motor operates at full speed.

## Code Details

### Code Structure:

The project code is organized into four main files, following a modular and structured approach for maintainability and readability:

1. `main.c`: The main program file that controls the system's overall operation.
2. `adc.c`: Contains functions to configure and read data from the ADC (Analog-to-Digital Converter) peripheral in Single Conversion Mode for reading the LM35 sensor.
3. `timer.c`: Includes functions to configure Timer0 in Fast PWM Mode for generating pulses and controlling the DC motor's speed.
4. `lcd.c`: Contains functions to control the LCD display in 8-bit mode to provide information to the user.

### Peripheral Usage:

- **ADC (Analog-to-Digital Converter):** The LM35 temperature sensor data is read using the ADC in Single Conversion Mode.

- **Timer0 (Fast PWM Mode):** Timer0 is used to generate pulses with specific duty cycles to control the DC motor's speed.

- **LCD:** The 8-bit mode of the LCD is utilized to display messages and options to the user.

- **Keypad:** The keypad is used to input the password from the user.

## Getting Started

To use this project, you will need the following components:

- Atmega 32 microcontroller.
- Temperature sensor (LM35).
- DC motor.
- Keypad.
- LCD display.
- LEDs.
- Appropriate power supply.

## Usage

1. Upload the project code to your Atmega 32 microcontroller using your preferred development environment (e.g., AVR Studio, Atmel Studio, etc.).

2. Connect the components as per the circuit diagram provided.

3. Power on the system and follow the on-screen instructions to control LEDs and monitor temperature based on the described operation.

## Contributors

- [Your Name]

## License

This project is licensed under the [License Name] License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

- Mention any libraries or references you used during the project development.


[Watch the Video](https://youtu.be/VYtzk74cG7g?si=wK7G9-axvKZvmHMZ)
