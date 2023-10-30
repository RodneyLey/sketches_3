#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Define button constants
const int btnRIGHT = 0;
const int btnUP = 1;
const int btnDOWN = 2;
const int btnLEFT = 3;
const int btnNONE = 4;

// Define the button pin
const int buttonPin = A0;

byte smilingFace[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

byte frowningFace[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B01110,
  B10001,
  B00000,
  B00000
};

int characterXPosition = 7;
int characterYPosition = 1;
int lastCharacterXPosition = 7;
int lastCharacterYPosition = 1;

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(1, smilingFace);
  lcd.createChar(2, frowningFace);

  pinMode(buttonPin, INPUT);
}

void loop() {
  int adc_key_in = analogRead(buttonPin);

  // Determine the button based on the analog value
  int buttonPressed = btnNONE;

  if (adc_key_in < 50) {
    buttonPressed = btnRIGHT;
  } else if (adc_key_in < 250) {
    buttonPressed = btnUP;
  } else if (adc_key_in < 450) {
    buttonPressed = btnDOWN;
  } else if (adc_key_in < 650) {
    buttonPressed = btnLEFT;
  }

  if (buttonPressed == btnRIGHT && characterXPosition < 15) {
    updateCharacterPosition(characterXPosition + 1, characterYPosition);
  } else if (buttonPressed == btnLEFT && characterXPosition > 0) {
    updateCharacterPosition(characterXPosition - 1, characterYPosition);
  } else if (buttonPressed == btnUP && characterYPosition > 0) {
    updateCharacterPosition(characterXPosition, characterYPosition - 1);
  } else if (buttonPressed == btnDOWN && characterYPosition < 1) {
    updateCharacterPosition(characterXPosition, characterYPosition + 1);
  }

  animateCharacter();
}

void updateCharacterPosition(int x, int y) {
  lastCharacterXPosition = characterXPosition;
  lastCharacterYPosition = characterYPosition;
  characterXPosition = x;
  characterYPosition = y;
}

void animateCharacter() {
  lcd.setCursor(lastCharacterXPosition, lastCharacterYPosition);
  lcd.print(" ");
  lcd.setCursor(characterXPosition, characterYPosition);
  lcd.write(1);
  delay(500);
  lcd.setCursor(characterXPosition, characterYPosition);
  lcd.write(2);
  delay(500);
}
