const int delayTime = 1500; // how long to wait between actions, 1500 (1.5 secs) is good

const bool debugOutput = true; // turn output messages to the serial monitor on/off

// true == HIGH
// false == LOW

// PINS
const int vacuumSensorPin = A0;
// vacuum level bar chart
const int led_1_pin = 12;
const int led_2_pin = 11;
const int led_3_pin = 10;
const int led_4_pin = 9;
const int led_5_pin = 8;
const int led_6_pin = 7;
const int led_7_pin = 6;
const int led_8_pin = 5;
const int led_9_pin = 4;
const int led_10_pin = 3;

bool led_1_on = LOW;
bool led_2_on = LOW;
bool led_3_on = LOW;
bool led_4_on = LOW;
bool led_5_on = LOW;
bool led_6_on = LOW;
bool led_7_on = LOW;
bool led_8_on = LOW;
bool led_9_on = LOW;
bool led_10_on = LOW;

int vacuumSensorValue; // create a blank variable to hold the value from the Vacuum Sensor Pin that can be assigned a value later

bool inRange(int minimum, int value, int maximum) {return ((value >= minimum) && (value < maximum));} // return a boolean if a value is within a range

void SetAllLEDs(bool state) {
  led_1_on = state;
  led_2_on = state;
  led_3_on = state;
  led_4_on = state;
  led_5_on = state;
  led_6_on = state;
  led_7_on = state;
  led_8_on = state;
  led_9_on = state;
  led_10_on = state;
  UpdateLEDs();
}

void UpdateLEDs() {
  digitalWrite(led_1_pin, led_1_on);
  digitalWrite(led_2_pin, led_2_on);
  digitalWrite(led_3_pin, led_3_on);
  digitalWrite(led_4_pin, led_4_on);
  digitalWrite(led_5_pin, led_5_on);
  digitalWrite(led_6_pin, led_6_on);
  digitalWrite(led_7_pin, led_7_on);
  digitalWrite(led_8_pin, led_8_on);
  digitalWrite(led_9_pin, led_9_on);
  digitalWrite(led_10_pin, led_10_on);
}

// run this first, once, when the arduino recieves power or the reset button is pressed
void setup() {
  Serial.begin(9600);
  delay(delayTime);
  print("Starting");
  delay(delayTime);
  Serial.println("Initialising Vacuum Level LEDs");
  pinMode(led_1_pin, OUTPUT);
  pinMode(led_2_pin, OUTPUT);
  pinMode(led_3_pin, OUTPUT);
  pinMode(led_4_pin, OUTPUT);
  pinMode(led_5_pin, OUTPUT);
  pinMode(led_6_pin, OUTPUT);
  pinMode(led_7_pin, OUTPUT);
  pinMode(led_8_pin, OUTPUT);
  pinMode(led_9_pin, OUTPUT);
  pinMode(led_10_pin, OUTPUT);
  delay(delayTime);
  SetAllLEDs(HIGH);
  delay(delayTime);
  SetAllLEDs(LOW);
  delay(delayTime);
  Serial.println("Initialising Vacuum Sensor Input");
  pinMode(vacuumSensorPin, INPUT);
  delay(delayTime);
}

void loop() {
  vacuumSensorValue = analogRead(vacuumSensorPin);
  if (debugOutput == true) {Serial.println(vacuumSensorValue);}
  if (inRange(0,   vacuumSensorValue, 100))  {led_1_on = true;}
  if (inRange(100, vacuumSensorValue, 200))  {led_2_on = true;}
  if (inRange(200, vacuumSensorValue, 300))  {led_3_on = true;}
  if (inRange(300, vacuumSensorValue, 400))  {led_4_on = true;}
  if (inRange(400, vacuumSensorValue, 500))  {led_5_on = true;}
  if (inRange(500, vacuumSensorValue, 600))  {led_6_on = true;}
  if (inRange(600, vacuumSensorValue, 700))  {led_7_on = true;}
  if (inRange(700, vacuumSensorValue, 800))  {led_8_on = true;}
  if (inRange(800, vacuumSensorValue, 900))  {led_9_on = true;}
  if (inRange(900, vacuumSensorValue, 1023)) {led_10_on = true;}
  UpdateLEDs();
  delay(100);
}