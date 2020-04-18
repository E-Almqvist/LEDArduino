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

	for( int i = 0; i < NUM_LEDS; i++ ) {
		leds[i] = CRGB( 0, 0, 0 );
	}
	FastLED.show();
}


// Render frame
#define LENGTH 4
#define SPEED 2

void inline rmFromRange( int srtpos, int endpos ) {
	for( int ri = srtpos; ri <= endpos; ri++ ) {
		leds[ri] = CRGB( 0, 0, 0 );
	}	
}

int frame = 0;
bool invert = false;
void renderFrame() {
	rmFromRange( 0, NUM_LEDS - 1 );

	for( int i=0; i < LENGTH; i++ ) {
		leds[frame + i - 1] = CRGB( 0, 255, 0 );
	}

	if( frame > NUM_LEDS ) {
		frame = 0;
	}
}

void loop() {
	renderFrame(); // create the frame
	FastLED.show(); // show it
	
	frame+=SPEED;
}
