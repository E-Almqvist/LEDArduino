#include <FastLED.h>

// Hardware vars
#define CHIPSET WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS 300
#define DATA_PIN 2

// Vars
CRGB leds[NUM_LEDS] = { CRGB( 0, 0, 0 ) };

	
// Config
#define BRIGHTNESS 128
#define updateLEDS 6 // update speed
#define beamLength 8
#define DELAY 1500 // max delay

#define clrRandom random( 0, 255 )
CRGB genRandomClr() {
	return CRGB( clrRandom, clrRandom, clrRandom );
}

void addBeam( CRGB clr = CRGB( 0, 0, 255 ), int pos = 0 ) {
	for( int i = pos; i < beamLength; i++ ) {
		leds[i] = clr;
	}
}

unsigned long lastTime;
void setup() {
	FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
	FastLED.setBrightness(BRIGHTNESS);
	
	CRGB clr = genRandomClr();
	addBeam( clr );

	lastTime = millis();

	FastLED.show();
}

void loop() {
	FastLED.setBrightness(random(0, BRIGHTNESS));
	for( int i = NUM_LEDS - 1; i >= updateLEDS; i-- ) {
		leds[i] = leds[i - updateLEDS];
		leds[i - updateLEDS] = CRGB( 0, 0, 0 ); // remove the old led
	}
	
	if( millis() - lastTime >= random( 40, DELAY ) ) {
		addBeam(genRandomClr());
		lastTime = millis();
	}

	FastLED.show(); // show it	
	//delay(10);
}
