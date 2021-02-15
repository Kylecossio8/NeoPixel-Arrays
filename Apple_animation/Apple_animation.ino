#include <Adafruit_NeoPixel.h>
#include "frames.h"

Adafruit_NeoPixel strip(64, 6);

int colors [4][3]{
  {0,0,0},
  {255,0,0},
  {0,255,0},
  {165,42,42}
};

int whichFrame = 0;

void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(25);
}

void loop() {
  for (int i = 0; i < strip.numPixels(); i++) {
    int whichcolor = animation[whichFrame][i];
    
    int red = colors[whichcolor][0];
    int green = colors[whichcolor][1];
    int brown = colors [whichcolor][2];
    strip.setPixelColor(i, red, green, brown);
  }
  strip.show();
  whichFrame = (whichFrame+1) % 5;
  delay(1000);

}
