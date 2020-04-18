#include <FastLED.h>


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

	for( int i=0; i < NUM_LEDS; i++ ) {
		leds[i] = CRGB( 0, 255, 0 );
	}	
	
}

void loop() {
	//leds[0] = CRGB(255, 0, 0);
	//leds[3] = CRGB( 255, 255, 0 );

	FastLED.setBrightness(BRIGHTNESS);
	FastLED.show();
}
