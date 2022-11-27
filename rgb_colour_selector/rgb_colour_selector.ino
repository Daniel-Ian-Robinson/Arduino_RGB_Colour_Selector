const int RED_POT_PIN = A0;
const int GREEN_POT_PIN = A1;
const int BLUE_POT_PIN = A2;

const int RED_OUT_PIN = 3;
const int GREEN_OUT_PIN = 5;
const int BLUE_OUT_PIN = 6;

/**
 * The minimum potentiometer value required to activate the LED. Use a sensible value in the range [0, 1023]. This
 * threshold exists because potentiometers rarely hit zero but we need to accept zero values so we can send zero values
 * to the LED.
 */
const int MIN_POT_VAL = 15;

/**
 * Sets up the potentiometer input pins and the LED output pins.
 */
void setup() {
    pinMode(RED_POT_PIN, INPUT);
    pinMode(GREEN_POT_PIN, INPUT);
    pinMode(BLUE_POT_PIN, INPUT);
  
    pinMode(RED_OUT_PIN, OUTPUT);
    pinMode(GREEN_OUT_PIN, OUTPUT);
    pinMode(BLUE_OUT_PIN, OUTPUT);
}

/**
 * Reads the potentiometer values and updates the LED's colour accordingly.
 */
void loop() {
    int redPotVal = analogRead(RED_POT_PIN);
    int greenPotVal = analogRead(GREEN_POT_PIN);
    int bluePotVal = analogRead(BLUE_POT_PIN);

    /*
     *  Floor the potentiometer values to zero if they are below the threshold. This stops the LED flickering when the
     *  potentiometer is at its minimum value (which may be above zero).
     */
    if (redPotVal < MIN_POT_VAL) {
        redPotVal = 0;
    }

    if (greenPotVal < MIN_POT_VAL) {
        greenPotVal = 0;
    }

    if (bluePotVal < MIN_POT_VAL) {
        bluePotVal = 0;
    }

    // Calculate the red, green, and blue values for the LED from the potentiometers' input.
    int redVal = map(redPotVal, 0, 1023, 0, 255);
    int greenVal = map(greenPotVal, 0, 1023, 0, 255);
    int blueVal = map(bluePotVal, 0, 1023, 0, 255);

    // Set the LED's colour.
    analogWrite(RED_OUT_PIN, redVal);
    analogWrite(GREEN_OUT_PIN, greenVal);
    analogWrite(BLUE_OUT_PIN, blueVal);
}
