/*
  ATtiny85SerialHello.ino: Repeatedly print "hello" and blink an LED.
  Copyright Jason Pepas (Pepas Labs, LLC)
  Released under the terms of the MIT License.  See http://opensource.org/licenses/MIT
*/

// ATiny85 pinout:
//
//                                      +--\/--+
//        (PCINT5/!RESET/ADC0/dW) PB5  -|1    8|-  VCC
// (PCINT3/XTAL1/CLKI/!OC1B/ADC3) PB3  -|2    7|-  PB2 (SCK/USCK/SCL/ADC1/T0/INT0/PCINT2)
//  (PCINT4/XTAL2/CLKO/OC1B/ADC2) PB4  -|3    6|-  PB1 (MISO/DO/AIN1/OC0B/OC1A/PCINT1)
//                                GND  -|4    5|-  PB0 (MOSI/DI/SDA/AIN0/OC0A/!OC1A/AREF/PCINT0)
//                                      +------+

#define ARDUINO_PIN_D0 0
#define ARDUINO_PIN_D1 1
#define ARDUINO_PIN_D2 2
#define ARDUINO_PIN_D3 3
#define ARDUINO_PIN_D4 4
#define ARDUINO_PIN_D5 5

#define ATTINY_PIN_1 ARDUINO_PIN_D5
#define ATTINY_PIN_2 ARDUINO_PIN_D3
#define ATTINY_PIN_3 ARDUINO_PIN_D4
#define ATTINY_PIN_5 ARDUINO_PIN_D0
#define ATTINY_PIN_6 ARDUINO_PIN_D1
#define ATTINY_PIN_7 ARDUINO_PIN_D2

// project pinout:
//
//        +--\/--+
//   D5  -|1    8|-  Vcc
//   D3  -|2    7|-  D2        LED_pin
//   D4  -|3    6|-  D1 (PWM)  TX_pin
//  GND  -|4    5|-  D0 (PWM)  RX_pin
//        +------+

#define RX_pin ARDUINO_PIN_D0
#define TX_pin ARDUINO_PIN_D1
#define LED_pin ARDUINO_PIN_D2


#include <SoftwareSerial.h>
SoftwareSerial ss(RX_pin, TX_pin);

void setup()
{
  pinMode(RX_pin, INPUT);
  pinMode(TX_pin, OUTPUT);
  pinMode(LED_pin, OUTPUT);
  
  ss.begin(9600);
}

void loop()
{
  ss.println("hello");
  delay(500);
  digitalWrite(LED_pin, HIGH);
  delay(500);
  digitalWrite(LED_pin, LOW);
}

