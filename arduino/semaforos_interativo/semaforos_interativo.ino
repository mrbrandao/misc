/*--Semaforo Interativo--
Neste Projeto usamos um botao para alternar entre o sinal
dos carros e o sinal dos pedestres.
*/
int carRed = 10;
int carYellow = 11;
int carGreen = 12;
int pedRed = 9;
int pedGreen = 8;
int button = 2;
int crosstime = 5000;
unsigned long changeTime; //Tempo desde que o botao foi pressionado

void setup(){
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT); //botao no pino 2
  // aceder a luz verde
  digitalWrite(carGreen, HIGH);
  digitalWrite(pedGreen, HIGH);
}

void loop(){
  int state = digitalRead(button);
  /*Verifica se o botao foi pressionado e se trancorreram
  5 segundos desde a ultima vez que isso ocorreu*/
  /*if (state == HIGH && (millis() - changeTime) > 5000){
    //Chama a funcao para alterar as luzes
    digitalWrite(pedRed, HIGH); 
    delay(100);
    changeLights();*/
    /*Alterei pra ficar melhor, agora o sinal dos pedestres
    pisca 3 vezes antes de avisa que o dos carros vai abrir e
    tambem continua verlmelho emquanto os sinal dos carros ainda
    esta mudando para vermelho para evitar de ser atropelado
    no amarelo ;p
    O if abaixo executa o changeLight se o botao for pressionado
    ou se passarem 5segundos com o sinal dos carros aberto.*/
    if (state == HIGH || (millis() - changeTime > 5000)) {
      for (int x=0; x<3; x++){
        digitalWrite(pedRed, HIGH);
        delay(250);
        digitalWrite(pedRed, LOW);
        delay(100);
        digitalWrite(pedRed, HIGH);
      }
      delay(1000);
      changeLights();
  }
}
void changeLights(){
  digitalWrite(carGreen, LOW);
  digitalWrite(carYellow, HIGH);
  delay(2000);
  
  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, HIGH);
  delay(1000);
  
  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);
  delay(crosstime);
  
  //pisca o verde dos pedestres
  for (int x=0; x<10; x++) {
    digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
  }
  
  //acende o vermelho dos pedestres
  digitalWrite(pedRed, HIGH);
  delay(500);
  digitalWrite(carYellow, HIGH);
  digitalWrite(carRed,LOW);
  delay(1000);
  digitalWrite(carGreen, HIGH);
  digitalWrite(carYellow, LOW);
  
  //registra o tempo desde a ultima alteracao no semaforo
  changeTime = millis();
  //depois retorna para o loop principal do programa
}
