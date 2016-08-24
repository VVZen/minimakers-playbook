/** Sketch di arduino per modificare il plastico del Fablab Roma Makers
* Il codice qui sotto è stato riscritto da Leonardo Zaccone e modificato rispetto all'originale
* di Shae Erisson.
*/

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

‪#‎include‬ <Adafruit_NeoPixel.h>
‪#‎ifdef‬ __AVR__
#include <avr/power.h>
‪#‎endif‬
// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
‪#‎define‬ PIN 6
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 50; // delay for half a second
int sensorPin = A0; 
int LUCE = 0;
int R = 0;
int G = 0;
int B = 0;
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  ‪#‎if‬ defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
}
void loop() {
  LUCE = analogRead(sensorPin);
  Serial.println("LUCE");Serial.print(LUCE);
  if (LUCE < 111) {
  R = map (LUCE, 0, 110, 0, 127);
  G = 0;
  B = 255;
  }
  if (LUCE > 110 && LUCE < 400) {
    G = map (LUCE, 109, 399, 0, 255);
    B = map (LUCE, 109, 399, 255, 0);
    R = 127;
  }
  if (LUCE > 399 && LUCE < 700) {
    R = map (LUCE, 400, 700, 127, 255);
    G = map (LUCE, 400, 700, 255, 0);
    B = 0;
  }
  if (LUCE > 699) {
    R = 255;
    G = map (LUCE, 700, 1024, 0, 255);
    B = map (LUCE, 700, 1024, 0, 255);
  }
  Serial.println("VERDE"); Serial.print(G);
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(R,G,B)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
}
