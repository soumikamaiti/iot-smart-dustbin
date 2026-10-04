#include <WiFi.h>
#include <ESP32Servo.h>

// Wi-Fi Details
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

// Pin Connections
#define TRIG_PIN 5
#define ECHO_PIN 18
#define SERVO_PIN 19

Servo lidServo;

long duration;
float distance;

int openDistance = 20;
int fullDistance = 10;

// Function to measure distance
float getDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * 0.0343 / 2;

  return distance;
}

// Setup
void setup()
{
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lidServo.attach(SERVO_PIN);

  // Initially keep the lid closed
  lidServo.write(0);

  // Connect to Wi-Fi
  Serial.println("Connecting to Wi-Fi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi Connected!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

// Main program
void loop()
{
  float currentDistance = getDistance();

  Serial.print("Distance: ");
  Serial.print(currentDistance);
  Serial.println(" cm");

  // Check whether the dustbin is full
  if (currentDistance <= fullDistance)
  {
    Serial.println("Dustbin is FULL!");

    lidServo.write(0);
  }

  // Detect a person's hand
  else if (currentDistance <= openDistance)
  {
    Serial.println("Object detected - Opening lid");

    lidServo.write(90);

    delay(3000);

    lidServo.write(0);

    Serial.println("Lid Closed");
  }

  else
  {
    lidServo.write(0);
  }

  delay(500);
}
