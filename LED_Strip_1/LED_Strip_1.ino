#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


#define PIN        5 


#define NUMPIXELS 144 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRBW + NEO_KHZ800);

#define DELAYVAL 20 

void setup() {

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif

  Serial.begin(9600);

  pixels.begin(); 
}

bool isGreen = true;

int blue = 0;

int green = 255;

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    pixels.setPixelColor(i, pixels.Color(0, green, blue));

    pixels.show();  

    if (isGreen){
      green--;
      blue++;
    } else {
      green++;
      blue--;
    }

    Serial.println(green);

    if (green == 0){
      isGreen = false;
      Serial.println(isGreen);
      green = 0;
      blue = 255;
    } else if(green == 255){
      isGreen = true;
      Serial.println(isGreen);
      blue = 0;
  }

    delay(DELAYVAL); 
 }
}