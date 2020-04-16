void setup() {
	pinMode(12, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	digitalWrite( 12, HIGH );
	Serial.println("Test");
}
