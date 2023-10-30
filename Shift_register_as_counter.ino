int latchPin = 10;
int clockPin = 11;
int dataPin = 8;   

// Anode control pins for the 2 digits
int anodePins[] = {2, 3};

// Define the values for digits 0-9
int dataArray[10] = {0B00000011, 0B10011111, 0B00100101, 0B00001101, 0B10011001,
                     0B01001001, 0B01000001, 0B00011111, 0B00000001, 0B00001001};

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  for (int i = 0; i < 2; i++) {
    pinMode(anodePins[i], OUTPUT);
    digitalWrite(anodePins[i], LOW);  // Turn off all digits initially
  }
}


void loop() {
  for (int seconds = 0; seconds < 60; seconds++) {
    for (int updateCount = 0; updateCount < 500; updateCount++) {
      // Calculate the tens and ones place
      int tens = seconds / 10;
      int ones = seconds % 10;

      // Display the tens place
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, dataArray[tens]);
      digitalWrite(latchPin, HIGH);
      digitalWrite(anodePins[0], HIGH);
      delay(1);  // Delay for 1 milliseconds

      // Turn off the tens place
      digitalWrite(anodePins[0], LOW);

      // Display the ones place
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, dataArray[ones]);
      digitalWrite(latchPin, HIGH);
      digitalWrite(anodePins[1], HIGH);
      delay(1);  // Delay for 1 milliseconds

      // Turn off the ones place
      digitalWrite(anodePins[1], LOW);
    }
  }
}