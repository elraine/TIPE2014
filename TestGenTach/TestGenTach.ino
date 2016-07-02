int RotVit = 0;
int dir = 0;

int vrot = 
int vitpin = 4;
int raw = 0;

void setup()
{
  Serial.begin(115200);          //  setup serial

}

void loop()
{
  raw = analogRead(4);

  vrot = raw*0.0049*
    Serial.println("Vrot");
  Serial.println(raw);
  delay(50);
}

