int sensorValue = 0;        // value read from the potmeter
int prevValue = 0;          // previous value from the potmeter

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(0);
  if (prevValue != sensorValue) {
    // map the value between 0 to 100 :
    int val = map(sensorValue, 0, 1023, 0, 360); // note the map function
    // print out the value :
    Serial.println(val);
    prevValue = sensorValue;
  }
  delay(100);
}

