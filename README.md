# Simple Obstacle-Avoiding Car with L298N Motor Driver and Ultrasonic Sensor

This project implements an obstacle-avoiding Car using an Arduino Uno R3, L298N motor driver, and HC-SR04 ultrasonic sensor. The robot detects obstacles and automatically adjusts its movements by rotating or moving forward. It is powered by four AA batteries and controlled via a switch.

## Features

- Obstacle detection using the HC-SR04 ultrasonic sensor.

- Automatic rotation to avoid obstacles.

- Forward movement when the path is clear.

- Controlled via an on/off switch.

## Components

- **Arduino Uno R3**

- **L298N Motor Driver**

- **2 DC Motors**

- **4 AA Battery Holder**

- **4 AA Batteries**

- **Switch Button**

- **2WD Car Chassis**

- **HC-SR04 Ultrasonic Sensor**

## Circuit Diagram

Connect the components as follows:

### Motor Driver (L298N):

- **IN1** -> Arduino pin 3

- **IN2** -> Arduino pin 4

- **IN3** -> Arduino pin 5

- **IN4** -> Arduino pin 6

- **12V Input** -> Positive terminal of the battery pack

- **GND** -> Ground (common with Arduino)

### Ultrasonic Sensor (HC-SR04):

- **Trig Pin** -> Arduino pin 9

- **Echo Pin** -> Arduino pin 10

- **VCC** -> 5V (from Arduino)

- **GND** -> Ground

### Switch:

- Connect one terminal to **Arduino pin 8**.

- Connect the other terminal to **GND**.

## Installation

### Hardware Setup:

1. Assemble the 2WD chassis and attach the DC motors.

2. Connect the components as per the circuit diagram above.

3. Secure the battery holder and switch on the chassis.

4. Mount the ultrasonic sensor at the front of the chassis.

### Software Setup:

1. Install the Arduino IDE.

2. Add the **NewPing** library if not already installed:
   
   - Go to **Sketch > Include Library > Manage Libraries**.
   
   - Search for "NewPing" and click "Install".

3. Upload the provided code to your Arduino Uno.

## Usage

1. Power the Arduino and motor driver using the battery pack.

2. Turn on the switch to activate the robot.

3. The robot will:
   
   - Move forward if no obstacles are detected within a 20 cm range.
   
   - Rotate to avoid obstacles if detected within the 20 cm range.

## Code Overview

The code contains the following functions:

- `**setup()**`: Initializes pins and components.

- `**Rotate()**`: Activates motors for a 90-degree rotation.

- `**Forward()**`: Moves the robot forward.

- `**StopMotors()**`: Stops all motor activity.

- `**readPing()**`: Reads the distance measured by the ultrasonic sensor.

- `**loop()**`: Main logic for obstacle detection and movement control.

## Adjustments

- **Rotation Duration**: Modify `actionDuration` in milliseconds for fine-tuning the rotation angle.

- **Detection Range**: Adjust the `maximum_distance` and threshold in `loop()` for obstacle detection.

## Troubleshooting

- Ensure all connections are secure and components are powered.

- Verify that the **NewPing** library is installed.

- Check the serial monitor for debugging information.

## Future Improvements

- Add more sensors for better obstacle detection.

- Integrate Bluetooth or RF modules for remote control.

- Use a rechargeable battery pack for convenience.

## License

This project is open-source and available under the MIT License.

---

Happy building! Feel free to raise issues or contribute to this project.
