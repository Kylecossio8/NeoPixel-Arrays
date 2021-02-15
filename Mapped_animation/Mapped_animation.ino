#include <Adafruit_NeoPixel.h>
#include "frames.h"

Adafruit_NeoPixel strip(64, 6);

int colors [4][3]{
  {0,0,0},
  {0,0,255},
  {255,255,0},
  {255,165,0}
};

int whichFrame = 0;

void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(25);
}

void loop() {

  for (int i = 0; i < strip.numPixels(); i++) {
    int pixAddress = pixelMap[i];
    int whichColor = animation[whichFrame][i];
    int blue = colors[whichColor][0];
    int yellow = colors[whichColor][1];
    int orange = colors[whichColor][2];
    
    if(pixAddress != -1){
      strip.setPixelColor(pixAddress, blue,yellow,orange);
    }



    
    
  }
  strip.show();
  delay(500);
  whichFrame = (whichFrame + 1) % 4;

}
