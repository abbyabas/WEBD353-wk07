int buttonState = 0;  // value read from the button
int prevState = 0;    // previous value from the button
int pushButton = 2;   // push button connected to pin 2

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {
  buttonState = digitalRead(pushButton);
  // check previous value vs current value
  if (prevState != buttonState) {
    if (buttonState == HIGH) {
      Serial.println(1);
    } else {
      Serial.println(0);
    }
    prevState = buttonState;
  }
  delay(100);
}
