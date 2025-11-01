#include <SPI.h>
#include <MFRC522.h>
#include <ESP32Servo.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>


// WiFi credentials
const char* ssid = "xx";         // Your WiFi SSID
const char* password = "xxxxx"; // Your WiFi password


// Telegram Bot Token (replace with your bot's token)
#define BOT_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"


// Chat ID (replace with your chat ID)
#define CHAT_ID "1234xxxx4"


// Pin Definitions
#define SS_PIN    5   // SDA (Slave Select) for RC522
#define RST_PIN   22  // Reset pin for RC522
#define SERVO_PIN 14  // Servo motor signal pin
#define BUZZER_PIN 15 // Buzzer pin
#define FLAME_SENSOR_PIN 34 // Flame sensor digital pin (DO)


// Create instances for MFRC522 and Servo
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
Servo myServo;                     // Create Servo instance


// Flag to check if the door is open
bool doorOpen = false;


// Authorized RFID card UID (replace with your actual UID or expand as needed)
byte authorizedUIDs[][4] = {
  {0x86, 0xEE, 0xB2, 0x1}  // Example authorized UID
  // Add more UIDs as needed
};


// Setup WiFi and Telegram
WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);


void setup() {
  Serial.begin(115200);    // Start serial communication
  SPI.begin();             // Start SPI communication
  mfrc522.PCD_Init();      // Initialize MFRC522
  myServo.attach(SERVO_PIN);  // Attach the servo to the pin
  pinMode(BUZZER_PIN, OUTPUT);  // Set the Buzzer pin as output
  pinMode(FLAME_SENSOR_PIN, INPUT);  // Set the Flame sensor pin as input


  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");


  // Connect to Telegram
  client.setInsecure();  // Disable SSL verification if necessary
  if (client.connect("api.telegram.org", 443)) {
    Serial.println("Connected to Telegram!");
  } else {
    Serial.println("Failed to connect to Telegram.");
  }


  Serial.println("Scan your RFID card...");
}


void loop() {
  // Check if an RFID card is detected
  if (mfrc522.PICC_IsNewCardPresent()) {
    if (mfrc522.PICC_ReadCardSerial()) {
      Serial.print("Card UID: ");
      for (byte i = 0; i < mfrc522.uid.size; i++) {
        Serial.print(mfrc522.uid.uidByte[i], DEC);
        Serial.print(" ");
      }
      Serial.println();


      // Check if the card is authorized
      if (isAuthorized(mfrc522.uid.uidByte)) {
        Serial.println("Access Granted! Opening door...");
        openDoor();  // Open the door
      } else {
        Serial.println("Unauthorized access attempt!");
        soundBuzzer();  // Trigger buzzer for unauthorized card
        sendTelegramMessage("Unauthorized access attempt detected!");
      }
    }
  }


  // Flame sensor logic (Trigger buzzer if flame is detected)
  int flameDetected = digitalRead(FLAME_SENSOR_PIN);  // Read flame sensor digital output
  if (flameDetected == LOW) {  // Flame detected
    Serial.println("Flame detected! Triggering buzzer...");
    soundBuzzer();  // Trigger buzzer for flame detection
    sendTelegramMessage("Flame detected! Immediate action required.");
  }


  // Telegram command listening (Check for "open door" command)
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1); // Get new messages
  while (numNewMessages) {
    for (int i = 0; i < numNewMessages; i++) {
      String message = bot.messages[i].text;
      if (message == "open door") {
        sendTelegramMessage("Opening the door remotely.");
        openDoor(); // Open the door remotely
      }
    }
    numNewMessages = bot.getUpdates(bot.last_message_received + 1); // Check for updates again
  }


  delay(1000);  // Delay to prevent continuous checking
}


// Function to open the door
void openDoor() {
  if (!doorOpen) {
    myServo.write(90);  // Open door (adjust the angle to 90 degrees)
    doorOpen = true;
    delay(5000);  // Keep the door open for 5 seconds
    myServo.write(0);  // Close door (adjust the angle back to 0 degrees)
    doorOpen = false;
  }
}


// Function to sound the buzzer for 1 second
void soundBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);  // Turn on buzzer
  delay(1000);                     // Keep buzzer on for 1 second
  digitalWrite(BUZZER_PIN, LOW);   // Turn off buzzer
}


// Check if the card is authorized (compare the UID)
bool isAuthorized(byte* uid) {
  for (int i = 0; i < sizeof(authorizedUIDs) / 4; i++) {
    bool match = true;
    for (byte j = 0; j < 4; j++) {
      if (uid[j] != authorizedUIDs[i][j]) {
        match = false;
        break;
      }
    }
    if (match) return true;
  }
  return false;
}


// Function to send a message via Telegram
void sendTelegramMessage(String message) {
  if (bot.sendMessage(CHAT_ID, message, "")) {
    Serial.println("Message sent to Telegram!");
  } else {
    Serial.println("Failed to send message.");
  }
}
