#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

const int greenLED = 10;
const int redLED = 11;

const int ROW_NUM    = 4; // four rows
const int COLUMN_NUM = 4; // four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pin_rows[ROW_NUM] = {0, 1, 2, 3}; 
byte pin_column[COLUMN_NUM] = {4, 5, 6, 7}; 

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

const char* correctCode = "091A"; // Change this to your desired 4-digit code
char enteredCode[5] = ""; // Buffer for entered code

void setup() {
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();

  lcd.print("Enter code:");
  
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    handleKeypress(key);
  }
}

void handleKeypress(char key) {
  if (key == '#') {
    checkCode();
  } else {
    appendCode(key);
  }
}

void appendCode(char key) {
  if (strlen(enteredCode) < 4) {
    lcd.setCursor(strlen(enteredCode), 1);
    lcd.print('*');
    enteredCode[strlen(enteredCode)] = key;
    enteredCode[strlen(enteredCode) + 1] = '\0'; // Null-terminate the string
  }
}

void checkCode() {
  if (strcmp(enteredCode, correctCode) == 0) {
    lcd.clear();
    lcd.print("Correct Code");
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    delay(2000);
    resetSystem();
  } else {
    lcd.clear();
    lcd.print("Wrong Code");
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    delay(2000);
    resetSystem();
  }
}

void resetSystem() {
  lcd.clear();
  lcd.print("Enter code:");
  memset(enteredCode, 0, sizeof(enteredCode)); // Clear the entered code buffer
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
}