// RGB Coaster - STL files by Bernardo Giovanni (@cyb3rn0id - www.settorezero.com)
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN_RING            1

// number of leds per ring
#define LEDS_RING 24

// number of rings
#define N_RINGS 2      

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel((LEDS_RING*N_RINGS)-1, PIN_RING, NEO_RGB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() 
  {
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.setBrightness(50); // percent, 100=highest value but too much current needed
  }

void loop() 
  {
  /*
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
  */
 rainbowCycle(2);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) 
  {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) 
    {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
  if(WheelPos < 170) 
    {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }

void rainbowCycle(uint8_t wait) 
  {
  uint16_t i, j;
  for(j=0; j<256*5; j++) 
    { // 5 cycles of all colors on wheel
    for(i=0; i< pixels.numPixels(); i++) 
      {
      pixels.setPixelColor(i, Wheel(((i * 256 / pixels.numPixels()) + j) & 255));
      }
    pixels.show();
    delay(wait);
    }
  }
