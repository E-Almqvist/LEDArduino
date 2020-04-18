#include <FastLED.h>
//#include <Math>

// Hardware vars
#define CHIPSET WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS 300
#define DATA_PIN 2

// Vars
CRGB leds[NUM_LEDS];

	
// Config
#define BRIGHTNESS 20

void setup() {
	FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
	FastLED.setBrightness(BRIGHTNESS);

//	for( int i = 0; i < NUM_LEDS; i++ ) {
//		leds[i] = CRGB( 0, 0, 0 );
//	}
	leds[0] = CRGB( 0, 0, 255 );
	leds[1] = CRGB( 0, 0, 255 );

	leds[15] = CRGB( 0, 255, 0 );
	leds[16] = CRGB( 0, 255, 0 );
//	FastLED.show();
}


// Render frame

void loop() {
	
	for( int i = 0; i < NUM_LEDS; i++ ) {
		leds[i+1] = leds[i - 1];
		FastLED.show();
		delay(1);
		leds[i-1] = CRGB( 0, 0, 0 );
		FastLED.show();
		delay(1);
	}
	//FastLED.show(); // show it	
}
