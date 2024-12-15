// Define the L298N A & B Mortors setup 
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6

// Variable to track the rotation time and compare it with the action duration variable
unsigned long rotateStartTime = 0;

// Track rotation duration
unsigned long actionDuration = 0;  

// Import library to efficiently get the right distance detected by the HC-SR04 ultasonic sensor
#include <NewPing.h>

// Define switch button pin for ON/OFF actions
#define Switch_Button 8

// Define trigger and echo pins for the US sensor
#define Trig_Pin 9
#define Echo_Pin 10

// Define the maximun distance for the sensor to not surpass it (just for convintion)
#define maximum_distance 200

// Declare initial distance
int distance = 150;

 // Track the current action state
bool isRotating = false; 

// Declaring the sensor variable
NewPing sonar(Trig_Pin, Echo_Pin, maximum_distance);

void setup() {
  //Starting serial monitor tool for debugging (Sometimes needed)
  Serial.begin(9600);

  // Declare Motor A pins as OUTPUTS
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Declare Motor A pins as OUTPUTS
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initiate the 2 motors to be stopped by default
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  // Declare the switch button as input on pullup 
  pinMode(Switch_Button, INPUT_PULLUP);

  // Declare the sensor pins 
  pinMode(Echo_Pin, INPUT);
  pinMode(Trig_Pin, OUTPUT);

  // Initiate trip pin of the sensor to be LOW by default to avoid getting wrong result from the start
  digitalWrite(Trig_Pin, LOW);

  // Delay 0.1 s
  delay(100);
}

// Rotation function
void Rotate() { 
  
  // Motor A forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Motor B backward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Print in the serial monitor for debugging issues if needed
  Serial.println("Rotating...");
}

// Function to move both motors forward
void Forward() {

  // Motor A forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Motor B forward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  // Print in the serial monitor for debugging issues if needed
  Serial.println("Moving Forward...");
}

// Function to stop both motors
void StopMotors() {

  // Stop motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Stop motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  // Print in the serial monitor for debugging issues if needed
  Serial.println("Motors Stopped");
}

// Function to calculate distance between the car and an obstacle
int readPing() {
  int cm = sonar.ping_cm();
  if (cm == 0) {
    // Default to max range if no echo detected
    cm = 200;  
  }
  return cm;
}

void loop() {
  // Check switch state
  if (digitalRead(Switch_Button) == LOW) {
    distance = readPing();
    Serial.print("Distance: ");
    Serial.println(distance);

    // If an obstacle is detected, rotate
    if (distance >= 20) {
      if (!isRotating) {  // Start rotating
        isRotating = true;
        rotateStartTime = millis();
        actionDuration = 100000;  // Duration for 90-degree rotation (adjust as needed)
      }

      if (millis() - rotateStartTime < actionDuration) {
        Rotate();  // Continue rotating
      } else {
        isRotating = false;
        StopMotors();  // Stop rotating after the duration
      }

    } // If no obstacle, move forward
    else {
      if (isRotating) {
        isRotating = false;  // Stop rotation state
        StopMotors();        // Stop motors before switching
      }
      Forward();              // Move forward
    }
  } else {
    // If the switch is not pressed, stop all motors
    StopMotors();
  }

  // Small delay for stability
  delay(30);
}
