/* SerialPing
*/

const int pin_LED = 13;
volatile char inChar;

void setup() {
  pinMode(pin_LED, OUTPUT);
  digitalWrite(pin_LED, LOW);
  
  Serial.begin(9600);
}

void loop() {
}

void serialEvent() {
  while (Serial.available()) {
    inChar = (char)Serial.read();
    if (inChar == '1') {
      digitalWriteFast(pin_LED, HIGH);
    } else {
      digitalWriteFast(pin_LED, LOW);
    }
  }
}


