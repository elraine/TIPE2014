#include <PID_v1.h>

//Connexion moteur
int RotVit = 13;
int dir = 11 ;

//Connexion Gen Tachy
int Utach = 4;
int Kc = 0.0165; //Constante de couple

//Capteur rotation moteur
int vrot = 0;
int raw = 0;

//Timer
float _currentTime = -1;
//PID
double Setpoint, Input, Output;
//Spec les constantes PID
double Kp, Ki, Kd;

PID myPID(&Input, &Output, &Setpoint,1,3,0, DIRECT); //Réglages du PID Kp, Ki, Kd

void setup()
{
  Serial.begin(115200);          //  setup serial
  Serial.println("Demarrage en cours..");
  Setpoint=250;
  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp, Ki, Kd);  
  delay(3000);
  Serial.println("Standby ready");
  delay(100);
}

void loop()
{
  double oldTime = _currentTime;
  if(oldTime=-1)
  {
  oldTime=millis(); 
  }
  double currentTime = millis();
  double timeDiff = currentTime - oldTime;
  
  myPID.Compute();
  
  raw = analogRead(Utach);
  vrot = raw*0.0049*Kc; //en Volts
  Serial.println("Vrot : ");
  Serial.print(vrot);
  Serial.print(" ");
  Serial.print(timeDiff);
  delay(50);
  
} 