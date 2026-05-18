// Define o LED do 1o andar no pino 13
#define led1 13

// Define o LED DO 2o andar no pino 12
#define led2 12

// Defeine o LED do 3o andar no pino 11
#define led3 11

// Define o LED do 4° andar no pino 10
#define led4 10

// Define o LED DO 5° andar no pino 9
#define led5 9

// Defeine o LED do 6° andar no pino 8
#define led6 8

//Define o botão do 1o andar no pino 7
#define bot1 7

//Define o botão do 2o andar no pino 6
#define bot2 6

//Define o botão de 3o andar no pino 5
#define bot3 5

//Define o botão do 4° andar no pino 4
#define bot4 4

//Define o botão do 5° andar no pino 3
#define bot5 3

//Define o botão de 6° andar no pino 2
#define bot6 2

//Variável que guarda o andar solicitado pelo usuário
int andar;

//Variável que guarda o andar onde o elevador está atualmente
//O elevador começa no andar 1
int atual = 1;

//Variável criada para representar o tempo de espera
//Neste momento não será usada, mas poderia substituir os
//dalay(3000), por exemplo
int espera = 1500;

void setup() {

//Configura o LED do andar 1 como saída
pinMode(led1, OUTPUT);

//Configura o LED do andar 2 como saída
pinMode(led2, OUTPUT);

//Configura o LED do andar 3 como saída
pinMode(led3, OUTPUT);

//Configura o LED do andar 4 como saída
pinMode(led4, OUTPUT);

//Configura o LED do andar 5 como saída
pinMode(led5, OUTPUT);

//Configura o LED do andar 6 como saída
pinMode(led6, OUTPUT);

//Configura o botão do 1o andar Entrada
pinMode(bot1, INPUT);

//Configura o botão do 2o andar Entrada
pinMode(bot2, INPUT);

//Configura o botão do 3o andar Entrada
pinMode(bot3, INPUT);

//Configura o botão do 4o andar Entrada
pinMode(bot4, INPUT);

//Configura o botão do 5o andar Entrada
pinMode(bot5, INPUT);

//Configura o botão do 6o andar Entrada
pinMode(bot6, INPUT);

//Liga o LED do andar 1
//Isso indica que o elevador começa no 1o andar
digitalWrite(led1, HIGH);
}

void loop() {

//Verifica se o o botão do andar 1 foi pressionado
if (digitalRead(bot1) == HIGH) { andar = 1; }

//Verifica se o botão do andar 2 foi preassionado
if (digitalRead(bot2) == HIGH) { andar = 2; }

//Verifica se o botão do andar 3 foi preassionado
if (digitalRead(bot3) == HIGH) { andar = 3; }

//Verifica se o botão do andar 4 foi preassionado
if (digitalRead(bot4) == HIGH) { andar = 4; }

//Verifica se o botão do andar 5 foi preassionado
if (digitalRead(bot5) == HIGH) { andar = 5; }

//Verifica se o botão do andar 6 foi preassionado
if (digitalRead(bot6) == HIGH) { andar = 6; }

// A estrtutura Switch verifica qual andar foi solicitado
switch (andar) {

// Caso o usuário tenha solicitado o elevador no andar 1
case 1:
if (atual != 1) {
digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW);
digitalWrite(led4, LOW); digitalWrite(led5, LOW); digitalWrite(led6, LOW);

// Simula percurso descendo para o 1
for (int i = atual - 1; i > 1; i--) {
  int pinoLed;
  if(i==5) pinoLed=led5; if(i==4) pinoLed=led4; if(i==3) pinoLed=led3; if(i==2) pinoLed=led2;
  delay(2000); digitalWrite(pinoLed, HIGH); delay(2000); digitalWrite(pinoLed, LOW);
}
delay(2000); digitalWrite(led1, HIGH); atual = 1;
}
break;

case 2:
if (atual != 2) {
digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW);
digitalWrite(led4, LOW); digitalWrite(led5, LOW); digitalWrite(led6, LOW);

// Se estiver acima do 2, desce. Se abaixo, sobe.
if(atual > 2) {
  for(int i = atual-1; i > 2; i--) {
    int pinoLed;
    if(i==5) pinoLed=led5; if(i==4) pinoLed=led4; if(i==3) pinoLed=led3;
    delay(2000); digitalWrite(pinoLed, HIGH); delay(2000); digitalWrite(pinoLed, LOW);
  }
} else {
  // Sobe do 1 para o 2 (direto)
}
delay(2000); digitalWrite(led2, HIGH); atual = 2;
}
break;

case 3:
if (atual != 3) {
digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW);
digitalWrite(led4, LOW); digitalWrite(led5, LOW); digitalWrite(led6, LOW);
if(atual < 3) {
  for(int i = atual+1; i < 3; i++) {
    delay(2000); digitalWrite(led2, HIGH); delay(2000); digitalWrite(led2, LOW);
  }
} else {
  for(int i = atual-1; i > 3; i--) {
    int pinoLed;
    if(i==5) pinoLed=led5; if(i==4) pinoLed=led4;
    delay(2000); digitalWrite(pinoLed, HIGH); delay(2000); digitalWrite(pinoLed, LOW);
  }
}
delay(2000); digitalWrite(led3, HIGH); atual = 3;
}
break;

case 4:
if (atual != 4) {
digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW);
digitalWrite(led4, LOW); digitalWrite(led5, LOW); digitalWrite(led6, LOW);
if(atual < 4) {
  for(int i = atual+1; i < 4; i++) {
    int pinoLed; if(i==2) pinoLed=led2; if(i==3) pinoLed=led3;
    delay(2000); digitalWrite(pinoLed, HIGH); delay(2000); digitalWrite(pinoLed, LOW);
  }
} else {
  for(int i = atual-1; i > 4; i--) {
    delay(2000); digitalWrite(led5, HIGH); delay(2000); digitalWrite(led5, LOW);
  }
}
delay(2000); digitalWrite(led4, HIGH); atual = 4;
}
break;

case 5:
if (atual != 5) {
digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW);
digitalWrite(led4, LOW); digitalWrite(led5, LOW); digitalWrite(led6, LOW);
if(atual < 5) {
  for(int i = atual+1; i < 5; i++) {
    int pinoLed; if(i==2) pinoLed=led2; if(i==3) pinoLed=led3; if(i==4) pinoLed=led4;
    delay(2000); digitalWrite(pinoLed, HIGH); delay(2000); digitalWrite(pinoLed, LOW);
  }
} else {
  // Desce do 6 para o 5 (direto)
}
delay(2000); digitalWrite(led5, HIGH); atual = 5;
}
break;

case 6:
if (atual != 6) {
digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW);
digitalWrite(led4, LOW); digitalWrite(led5, LOW); digitalWrite(led6, LOW);
for(int i = atual+1; i < 6; i++) {
  int pinoLed;
  if(i==2) pinoLed=led2; if(i==3) pinoLed=led3; if(i==4) pinoLed=led4; if(i==5) pinoLed=led5;
  delay(2000); digitalWrite(pinoLed, HIGH); delay(2000); digitalWrite(pinoLed, LOW);
}
delay(2000); digitalWrite(led6, HIGH); atual = 6;
}
break;
}

andar=0;
}