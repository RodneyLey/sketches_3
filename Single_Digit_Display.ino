const int ledPinA=3;
const int ledPinB=4;
const int ledPinC=5;
const int ledPinD=6;
const int ledPinE=7;
const int ledPinF=8;
const int ledPinG=9;

int num_array[10][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2
  {0, 0, 0, 0, 1, 1, 0}, // 3
  {1, 0, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 0, 1, 0, 0}, // 5
  {0, 1, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0}, // 8
  {0, 0, 0, 1, 1, 0, 0}  // 9
};

int segmentPins[] = {3, 4, 5, 6, 7, 8, 9};


void setup() {
  // put your setup code here, to run once:
  for (int i=3; i<=9; i++)
  {
    pinMode(i,OUTPUT);
  }
}
void displayNumber(int number) {
  if (number >= 0 && number <= 9) {
    for (int j = 0; j < 7; j++) {
      digitalWrite(segmentPins[j], num_array[number][j]);
    }
  }
}
void loop() {
  // put your main code here, to run repeatedly:

    for (int i=3; i<=9; i++)
  {
    digitalWrite(i,HIGH);
  }


 digitalWrite(ledPinA,LOW);// TURN ON THE LED
  delay(1000);
 digitalWrite(ledPinA,HIGH);

  digitalWrite(ledPinB,LOW);// TURN ON THE LED
  delay(1000);
 digitalWrite(ledPinB,HIGH);

   digitalWrite(ledPinC,LOW);// TURN ON THE LED
  delay(1000);
 digitalWrite(ledPinC,HIGH);

   digitalWrite(ledPinD,LOW);// TURN ON THE LED
  delay(1000);
 digitalWrite(ledPinD,HIGH);

   digitalWrite(ledPinE,LOW);// TURN ON THE LED
  delay(1000);
 digitalWrite(ledPinE,HIGH);

   digitalWrite(ledPinF,LOW);// TURN ON THE LED
  delay(1000);
 digitalWrite(ledPinF,HIGH);

   digitalWrite(ledPinG,LOW);// TURN ON THE LED
  delay(1000);
  digitalWrite(ledPinG,HIGH);
  //delay(1000); //Delay 1 second

  // Display numbers 0-9
  for (int j = 0; j <= 9; j++) {
    displayNumber(j);
    delay(1000);
  }
}







