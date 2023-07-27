// Pin connected to LED
const int ledPin = 9;

// Dot and dash duration in milliseconds
int dotDuration = 300; // Default duration
int dashDuration = dotDuration * 3; // Dash is 3 times longer than dot

// Morse code timing
const int dotDelay = dotDuration;
const int dashDelay = dashDuration;
const int letterDelay = dotDuration * 3;
const int wordDelay = 1000;

// Morse code lookup table
const char* morseCode[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
  ".---",  // 1
  "..--",  // 2
  "...--", // 3
  "....-", // 4
  ".....", // 5
  "-....", // 6
  "--...", // 7
  "---..", // 8
  "----.", // 9
  "-----" // 0
};

void setup() {

   // Wait for a while before starting
  delay(2000);

  pinMode(ledPin, OUTPUT);

  // Enter the message you want to convert to Morse code
  String message = "I 5 zebras";

  // Convert message to uppercase
  message.toUpperCase();

  // Flash the message in Morse code
  flashMorseCode(message);

 
}

  void flashMorseCode(String message) {
    for (int i = 0; i < message.length(); i++) {
      char c = message.charAt(i);

      if (c == ' ') {
        // Pause between words
        delay(wordDelay);
      } else {
        // Find the Morse code for the character
        int index = c - 'A';
        if (index >= 0 && index < 36) {
          const char* morse = morseCode[index];
          flashMorseCharacter(morse);
        }
      }

      // Pause between letters
      delay(letterDelay);
    }
  }

  void flashMorseCharacter(const char* morse) {
    for (int i = 0; morse[i] != '\0'; i++) {
      char symbol = morse[i];

      if (symbol == '.') {
        flashDot();
      } else if (symbol == '-') {
        flashDash();
      }

      // Pause between dots and dashes
      delay(dotDelay);
    }
  }

  void flashDot() {
    digitalWrite(ledPin, HIGH);
    delay(dotDuration);
    digitalWrite(ledPin, LOW);
  }

  void flashDash() {
    digitalWrite(ledPin, HIGH);
    delay(dashDuration);
    digitalWrite(ledPin, LOW);
  }


void loop() {
}