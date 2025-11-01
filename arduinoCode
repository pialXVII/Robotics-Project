#include <Servo.h>

// --- Pin Configurations ---
Servo lampServo;       // Servo for lamp post control (Function 5)
Servo clothServo;      // Servo for cloth protection (Function 4)

int ledPin = 11;       // LED (outdoor light) pin (Function 5)
int ldrPin = A2;       // LDR pin (light detection for Function 5)
int irPin = 6;         // IR sensor pin for presence detection (Function 5)
int servoPinLamp = 10; // Servo control pin for lamp post (Function 5)
int servoPinCloth = 4; // Servo control pin for cloth protection (Function 4)
int pirPin = 7;        // PIR sensor pin for motion detection (Function 2)
int motorPin1 = 8;     // DC motor (fan) control pin (Function 2)
int motorPin2 = 9;     // DC motor (fan) control pin (Function 2)
int rainSensorPin = A1; // Rain sensor analog pin (Function 4)

// --- Constants ---
int ldrThreshold = 500;  // LDR threshold to decide day/night for Function 5
int rainThreshold = 400; // Threshold for rain detection (Function 4)
int pirThreshold = 500; // PIR sensor detection threshold (Function 2)

void setup() {
  Serial.begin(9600);

  // Initialize pins for Function 5
  pinMode(ledPin, OUTPUT);    // LED (outdoor light)
  pinMode(ldrPin, INPUT);     // LDR sensor
  pinMode(irPin, INPUT);      // IR sensor for presence detection
  pinMode(pirPin, INPUT);     // PIR sensor for motion detection
  pinMode(motorPin1, OUTPUT); // DC motor control
  pinMode(motorPin2, OUTPUT); // DC motor control
  pinMode(rainSensorPin, INPUT); // Rain sensor (analog)

  // Attach servos to their respective pins
  lampServo.attach(servoPinLamp);  // Lamp post control (Function 5)
  clothServo.attach(servoPinCloth); // Cloth protector control (Function 4)

  // Initial positions for servos
  lampServo.write(0);    // Lamp post down (Function 5)
  clothServo.write(0);    // Cloth protector down (Function 4)
}

void loop() {
  // --- Function 2: Human Detection and Fan Control ---
  int pirValue = digitalRead(pirPin); // Read PIR sensor for motion detection
  if (pirValue == HIGH) {
    // Turn on the fan if motion is detected
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  } else {
    // Turn off the fan if no motion is detected
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }

  // --- Function 4: Weather-Responsive Cloth Protector ---
  int rainValue = analogRead(rainSensorPin); // Read rain sensor value
  Serial.print("Rain Sensor: ");
  Serial.println(rainValue); // Print rain sensor value for debugging

  if (rainValue < rainThreshold) {
    // Protect the clothes if rain is detected
    clothServo.write(90);  // Move servo to protect clothes
  } else {
    // Move servo back if no rain is detected
    clothServo.write(0);  
  }

  // --- Function 5: Outdoor Light Control ---
  int ldrValue = analogRead(ldrPin);  // Read LDR value for light detection
  int irValue = digitalRead(irPin);   // Read IR sensor value for presence detection

  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" | IR Value: ");
  Serial.println(irValue);

  if (ldrValue > ldrThreshold) {  // If it's dark (nighttime)
    digitalWrite(ledPin, HIGH);  // Turn on the LED (outdoor light)
    lampServo.write(90);  // Raise the lamp post

    if (irValue == LOW) {  // If IR detects a person (presence)
      analogWrite(ledPin, 255);  // Set LED to full brightness
    } else {
      analogWrite(ledPin, 50);   // Dim the LED if no person is detected
    }
  } else {  // If it's bright (daytime)
    digitalWrite(ledPin, LOW);  // Turn off the LED (outdoor light)
    lampServo.write(0);  // Lower the lamp post
  }

  delay(100);  // Small delay to stabilize the loop
}




