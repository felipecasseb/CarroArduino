//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
char letra;
int led1 = 13;
int led2 = 12;
void setup() {
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 digitalWrite(led1, HIGH);
 digitalWrite(led2, HIGH);
 Serial.begin(9600);

}

void loop() {  
while (Serial.available()>0){
  letra = Serial.read();
  Serial.println(letra);


  if(letra == 'F'){
    frente();
  }
  if(letra == 'B'){
    tras();
  }
  if(letra == 'R'){
    direita();
  }
  if(letra == 'L'){
    esquerda();
  }
  if(letra == 'S'){
    parar();
  }
  if(letra == 'W'){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  if(letra == 'w'){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}
}







void frente(){
  //Gira o Motor A no sentido horario
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
 //Gira o Motor B no sentido horario
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
}

void tras(){
  //Gira o Motor A no sentido anti-horario
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
 //Gira o Motor B no sentido anti-horario
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
}
void direita(){
  //Gira o Motor A no sentido horario
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, LOW);
  //Gira o Motor B no sentido anti-horario
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, HIGH);
}
void esquerda(){
  //Gira o Motor B no sentido horario
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, LOW);
 //Gira o Motor A no sentido anti-horario
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, HIGH);
}
void parar(){
  //Para o motor A
 digitalWrite(IN1, HIGH);
 digitalWrite(IN2, HIGH);
 //Para o motor B
 digitalWrite(IN3, HIGH);
 digitalWrite(IN4, HIGH);
}

