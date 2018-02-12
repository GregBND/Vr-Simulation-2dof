#include <SerialCommand.h>
#include <SoftwareSerial.h>

SerialCommand sCmd;
//Potentionmetre MOTEUR Gauche et droite
int PinPotG = 0; //sortie sur A0
long ValPotG = 0; //  variable
int PinPotD = 1; //sortie sur A1
long ValPotD = 0; //  variable

long PotG;
long PotD;


void setup() {
  Serial.begin(38400);//Vitesse de COM avec Unity
  while (!Serial);

 sCmd.addCommand("PotG",Pot_G);//création de CMD pour Unity
 sCmd.addCommand("PotD",Pot_D);//création de CMD pour Unity

}

void loop() {
  sCmd.readSerial();
}

void Pot_G(){
  ValPotG = analogRead(A0);
  PotG = (ValPotG*360/1023);
  Serial.println(PotG);
}

void Pot_D(){
  ValPotD = analogRead(A1);
  PotD = (ValPotD*360/1023);
  Serial.println(PotD);
}



