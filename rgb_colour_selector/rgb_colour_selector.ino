const int RED_POT_PIN = A0;
const int GREEN_POT_PIN = A1;
const int BLUE_POT_PIN = A2;

const int RED_OUT_PIN = 3;
const int GREEN_OUT_PIN = 5;
const int BLUE_OUT_PIN = 6;

const int MIN_POT_VAL = 15;

void setup() {
    pinMode(RED_POT_PIN, INPUT);
    pinMode(GREEN_POT_PIN, INPUT);
    pinMode(BLUE_POT_PIN, INPUT);
  
    pinMode(RED_OUT_PIN, OUTPUT);
    pinMode(GREEN_OUT_PIN, OUTPUT);
    pinMode(BLUE_OUT_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    int redPotVal = analogRead(RED_POT_PIN);
    int greenPotVal = analogRead(GREEN_POT_PIN);
    int bluePotVal = analogRead(BLUE_POT_PIN);

    // Since the potentiometers rarely hit zero, we will have a cap so the lkight doesnt flicker.
    if (redPotVal < MIN_POT_VAL) {
        redPotVal = 0;
    }

    if (greenPotVal < MIN_POT_VAL) {
        greenPotVal = 0;
    }

    if (bluePotVal < MIN_POT_VAL) {
        bluePotVal = 0;
    }

    int redVal = map(redPotVal, 0, 1023, 0, 255);
    int greenVal = map(greenPotVal, 0, 1023, 0, 255);
    int blueVal = map(bluePotVal, 0, 1023, 0, 255);

    analogWrite(RED_OUT_PIN, redVal);
    analogWrite(GREEN_OUT_PIN, greenVal);
    analogWrite(BLUE_OUT_PIN, blueVal);
}
