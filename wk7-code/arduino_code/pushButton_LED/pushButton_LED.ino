// Variables for the pushButton
int buttonState = 0;        // value read from the button
int prevState = 0;          // previous value from the button
int pushButton = 2;         // Pin for the pushbutton

// LED Values
int ledPin = 3;
int lightValue = 0;         // What is the value of the light

// LED read vars
String inData = "";         // a string to hold incoming data

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  // Will run code when data is being sent to the arduino
  while (Serial.available() > 0) {
    char received = Serial.read();
    inData += received;
    
    // Process message when new line character is received
    if (received == 'E')
    {
      lightValue = inData.toInt(); 
      inData = ""; // Clear buffer of received data
    }
  }

  buttonState = digitalRead(pushButton);
  // print out the state of the button into the serial port:
  if (prevState != buttonState) {
    if (buttonState == HIGH) {
      Serial.println(1);
    } else {
      Serial.println(0);
    }
    prevState = buttonState;
  }

  //Will write the light value to the LED
  digitalWrite(ledPin, lightValue);
  // delay in between reads for stability
  delay(100);
}
