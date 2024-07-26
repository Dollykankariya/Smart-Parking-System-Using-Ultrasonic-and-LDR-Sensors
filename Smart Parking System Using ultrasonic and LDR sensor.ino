// C++ code
//
int ultrasonic = 0;

int LDR = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  ultrasonic = 0.01723 * readUltrasonicDistance(7, 4);
  LDR = analogRead(A0);
  Serial.println(ultrasonic);
  if (ultrasonic < 50) {
    digitalWrite(13, HIGH);
  } else {
    if (LDR < 500) {
      digitalWrite(13, LOW);
    }
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}