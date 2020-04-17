#define STATUS_PIN 13

#define dw digitalWrite


void setup() {
	pinMode( STATUS_PIN, HIGH );
	Serial.begin( 9600 );
}

void loop() {
	dw( STATUS_PIN, HIGH );
	delay(1000);
	dw( STATUS_PIN, LOW );
	delay(1000);
}
