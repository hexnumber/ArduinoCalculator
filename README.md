# Taschenrechner mit Arduino

Ein einfacher Taschenrechner, der mit einem Arduino, einem 4x4 Keypad und einem 16x2 LCD-Display realisiert wurde. 
Der Taschenrechner unterstützt grundlegende mathematische Operationen wie Addition, Subtraktion, Multiplikation, Division und Dezimalstellen.

## Funktionsweise

- Der Taschenrechner wird auf einem Arduino betrieben.
- Die Benutzereingaben erfolgen über ein 4x4 Keypad.
- Die Berechnungen und Ergebnisse werden auf einem 16x2 LCD-Display angezeigt.
- Der Taschenrechner unterstützt fortlaufende Berechnungen, bei denen das Ergebnis einer Berechnung als Ausgangspunkt für die nächste verwendet werden kann.

## Hinweise

- Die Taste 'A' dient als Plus
- Die Taste 'B' dient als Minus
- Die Taste 'C' dient als Mal
- Die Taste 'D' dient als Geteilt
- Die Taste '#' dient als Gleich
- Die Taste '*' dient als Komma

## Voraussetzungen

- Ein Arduino (z.B. Arduino Uno).
- Ein 4x4 Keypad.
- Ein 16x2 LCD-Display mit I2C-Schnittstelle.
- Arduino IDE zum Hochladen des Codes.

## Verkabelung

Verbinde die Pins des Keypads und des LCD-Displays wie folgt mit dem Arduino:

![Alt text](https://github.com/hexnumber/ArduinoCalculator/blob/main/Image.png)

### Keypad
| Keypad Pin | Arduino Pin |
|------------|--------------|
| R1         | 9            |
| R2         | 8            |
| R3         | 7            |
| R4         | 6            |
| C1         | 5            |
| C2         | 4            |
| C3         | 3            |
| C4         | 2            |

### LCD-Display
| LCD Pin    | Arduino Pin |
|------------|--------------|
| VCC        | 5V           |
| GND        | GND          |
| SDA        | A4   / SDA        |
| SCL        | A5   / DCL        |
