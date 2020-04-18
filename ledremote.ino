#include <FastLED.h>


// Hardware vars
#define CHIPSET WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS 300
#define DATA_PIN 2

// Vars
CRGB leds[NUM_LEDS];

// Config
#define BRIGHTNESS 40

int getRGBclr( int n ) {
	return n*255 / NUM_LEDS;	
}

void setup() {
	FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
	FastLED.setBrightness(BRIGHTNESS);
}


int rgbHandle;

void loop() {
	// leds[0] = CRGB(255, 0, 0);
	// leds[3] = CRGB( 255, 255, 0 );
	
	for( int i=0; i < NUM_LEDS; i++ ) {
		// rgbHandle = getRGBclr(i);
		// leds[i] = CRGB( 0, rgbHandle, 0 );
		if( i % 2 == 0 ) { // if even
			leds[i] = CRGB( 0, 0, 255 );
			delay(1000);
			leds[i] = CRGB( 100, 100, 100 );
			delay(100);
		} else {
			leds[i] = CRGB( 255, 0, 0 );
		}
	}	

	FastLED.show();
}

