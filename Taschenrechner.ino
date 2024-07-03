#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; // Anzahl der Reihen des Keypads
const byte COLS = 4; // Anzahl der Spalten des Keypads

char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'.', '0', '=', '/'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // Pins für die Reihen
byte colPins[COLS] = {5, 4, 3, 2}; // Pins für die Spalten

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String inputString = ""; // String zur Speicherung der Eingaben
float linkeZahl = 0;
float rechteZahl = 0;
char letzerOperator;
bool operatorPressed = false;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Taschenrechner");
  delay(2000);
  lcd.clear();
}

void loop() {
  char taste = keypad.getKey();

  if (taste) {
    if (taste >= '0' && taste <= '9' || taste == '.') {
      inputString += taste;
      lcd.setCursor(0, 0);
      lcd.print(inputString);
    } else if (taste == '+' || taste == '-' || taste == '*' || taste == '/') {
      if (!operatorPressed) {
        linkeZahl = inputString.toFloat();
        letzerOperator = taste;
        lcd.print(taste);
        inputString = "";
        operatorPressed = true;
      }
    } else if (taste == '=') {
      if (operatorPressed) {
        rechteZahl = inputString.toFloat();
        ergebnisBerechnen();
        inputString = String(linkeZahl); // Setze das Ergebnis als neue Eingabe
        operatorPressed = false; // Berechnung abgeschlossen
      }
    }
  }
}

void ergebnisBerechnen() {
  switch (letzerOperator) {
    case '+':
      linkeZahl += rechteZahl;
      break;
    case '-':
      linkeZahl -= rechteZahl;
      break;
    case '*':
      linkeZahl *= rechteZahl;
      break;
    case '/':
      if (rechteZahl != 0) {
        linkeZahl /= rechteZahl;
      } else {
        lcd.setCursor(0, 1);
        lcd.print("Fehler");
        delay(2000);
        lcd.clear();
        linkeZahl = 0; // Rücksetzen bei Fehler
      }
      break;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(linkeZahl);
}