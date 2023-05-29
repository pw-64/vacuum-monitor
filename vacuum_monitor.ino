const int delayTime = 1500; // how long to wait between actions, 1500 (1.5 secs) is good

const bool debugOutput = true; // turn output messages to the serial monitor on/off

// PINS
const int vacuumSensorPin = A0; // potentiometer input to simulate vacuum reading
// vacuum level bar chart
const int redLED1 = 29;
const int redLED2 = 30;
const int redLED3 = 31;
const int redLED4 = 32;
const int redLED5 = 33;

int vacuumSensorValue; // create a blank variable to hold the value from the Vacuum Sensor Pin that can be assigned a value later

void initPinOutput(int pin, bool startState) {pinMode(pin, OUTPUT); digitalWrite(pin, startState);} // compact way to set a pin as an output and its starting state (ONLY FOR DIGITAL OUTPUT)
bool inRange(int minimum, int value, int maximum) {return ((value >= minimum) && (value < maximum));} // return a boolean if a value is within a range
void print(char message[]) {if (debugOutput == true) {Serial.println(message);}} // print a message to the serial monitor

// run this first, once, when the arduino recieves power or the reset button is pressed
void setup() {
  Serial.begin(9600); delay(delayTime); print("Starting ...");  
  
  delay(delayTime); print("  Initialising Vacuum Level LEDs");
  initPinOutput(redLED1, LOW);
  initPinOutput(redLED2, LOW);
  initPinOutput(redLED3, LOW);
  initPinOutput(redLED4, LOW);
  initPinOutput(redLED5, LOW);
  delay(delayTime);
  digitalWrite(redLED1, HIGH); digitalWrite(redLED2, HIGH); digitalWrite(redLED3, HIGH); digitalWrite(redLED4, HIGH); digitalWrite(redLED5, HIGH);
  delay(delayTime);
  digitalWrite(redLED1, LOW); digitalWrite(redLED2, LOW); digitalWrite(redLED3, LOW); digitalWrite(redLED4, LOW); digitalWrite(redLED5, LOW);
  
  delay(delayTime); print("  Initialising Vacuum Sensor Input");
  pinMode(vacuumSensorPin, INPUT);
  delay(delayTime);
}

void loop() {
  vacuumSensorValue = analogRead(vacuumSensorPin);
  if (inRange(0, vacuumSensorValue, 200)) {digitalWrite(redLED1, HIGH); digitalWrite(redLED2, LOW); digitalWrite(redLED3, LOW); digitalWrite(redLED4, LOW); digitalWrite(redLED5, LOW);}
  if (inRange(200, vacuumSensorValue, 400)) {digitalWrite(redLED1, HIGH); digitalWrite(redLED2, HIGH); digitalWrite(redLED3, LOW); digitalWrite(redLED4, LOW); digitalWrite(redLED5, LOW);}
  if (inRange(400, vacuumSensorValue, 600)) {digitalWrite(redLED1, HIGH); digitalWrite(redLED2, HIGH); digitalWrite(redLED3, HIGH); digitalWrite(redLED4, LOW); digitalWrite(redLED5, LOW);}
  if (inRange(600, vacuumSensorValue, 800)) {digitalWrite(redLED1, HIGH); digitalWrite(redLED2, HIGH); digitalWrite(redLED3, HIGH); digitalWrite(redLED4, HIGH); digitalWrite(redLED5, LOW);}
  if (inRange(800, vacuumSensorValue, 1023)) {digitalWrite(redLED1, HIGH); digitalWrite(redLED2, HIGH); digitalWrite(redLED3, HIGH); digitalWrite(redLED4, HIGH); digitalWrite(redLED5, HIGH);}
  delay(100);
}