#include <PID_v1.h>

//Connexion moteur
int speedpin = 11;
int dirpin = 13;
//Connexion GTachymétrique
int GTpin = 4;

//Vitesse moteur et direction
int vmot = 0;
int dir =0;
//Vitesse cabine
int vcab = 0;

//Consigne
int Vconsi =0;

//PID
double Setpoint, Input, Output;
double Kp=1500, Ki=0, Kd=0;

//Réglages du PID Kp, Ki, Kd
PID myPID(&Input, &Output, &Setpoint,Kp,Ki,Kd, DIRECT);

void setup()
{
  //GO serial
  Serial.begin(115200);
  Serial.println("Demarrage ..");
  Input = analogRead(GTpin);
  Setpoint=255;
  myPID.SetMode(AUTOMATIC);
  myPID.SetSampleTime(50);
  Serial.println("Standby ready");
  delay(50);
  Serial.println("Output :  ");  
  Serial.println("Vcab :  ");
}

void loop()
{
vcab = 0.1*0.5*0.0165*analogRead(GTpin);
Input = analogRead(GTpin);

myPID.Compute();

Vconsi = Output;
analogWrite(speedpin,Vconsi);
/*
Serial.println("Input : ");
Serial.println(analogRead(GTpin));
*/

Serial.println(Vconsi);
Serial.print("    ");
Serial.print(Input);
delay(50);
}
