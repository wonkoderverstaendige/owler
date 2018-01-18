/* SerialPing
*/

const int pin_LED = 13;
volatile char inChar;
unsigned long ts_start = micros();
unsigned long ts_end = micros();

void setup() {
  pinMode(pin_LED, OUTPUT);
  digitalWrite(pin_LED, LOW);
  
  Serial.begin(115200);
}

void loop() {
}

void serialEvent() {
  while (Serial.available()) {
    inChar = (char)Serial.read();
    switch (inChar) {
      case '1':
        digitalWriteFast(pin_LED, HIGH);
        break;
        
      case '0':
        digitalWriteFast(pin_LED, LOW);
        break;
        
      case 'R':
        ts_end = micros();
        Serial.println(ts_end - ts_start);
        break;
        
      case 'S':
        // start loop
        Serial.println('!');
        Serial.send_now();
        ts_start = micros();
        break;
        
      default:
        break;     
    }
  }
}


