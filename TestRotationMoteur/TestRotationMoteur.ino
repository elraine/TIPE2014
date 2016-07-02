int dirA = 12;
int dirB = 13;  // not used in this example
int speedA = 10;
int speedB = 11; // not used in this example
int raw = 0;


void setup()
{
  	pinMode(dirB, OUTPUT);
	Serial.begin(115200);
Serial.println("Standby ready");
delay(50);
}

void loop()
{

	digitalWrite(dirB, 0); // set direction
        analogWrite(speedB, 255); // set speed (PWM)
raw = analogRead(4);
Serial.println(raw);
delay(50);

}
