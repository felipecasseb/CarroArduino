#include <SoftwareSerial.h>
SoftwareSerial master (8,9); //TX RX

int x = A0;
int y = A1;
int vx, vy;
char letra;


void setup() {
  Serial.begin(9600);
  master.begin(9600);
}

void loop() {
  vx = analogRead(x);
  vy = analogRead(y);

  Serial.println(vy);

  //parado
  if(vx>400 && vx<600 && vy>400 && vy<600){
    letra = 'S';
  }
  //frente
  if(vx<400){
    letra = 'F';
  }
  //tras
  if(vx>600){
    letra = 'B';
  }
  //esquerda
  if(vy>600){
    letra = 'L';
  }
  //direita
  if(vy<400){
    letra = 'R';
  }

  Serial.println(letra);
  
  master.write(letra);
}



