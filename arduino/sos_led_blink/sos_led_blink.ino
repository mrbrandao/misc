//Sinalizador de S.O.S em Codigo Morse
//Sao 3 piscadas rapidas seguidas de 3 piscadas lentas.
int pino = 10;//Led Conectado ao pino 10

//executa quando o sketch iniciar
void setup() { 
  //define o pino como saida
  pinMode(pino, OUTPUT);
}

//Inicia os 3 pontos rapidos de S.O.S
void loop(){
  for (int x=0; x<3; x++) {
    digitalWrite(pino, HIGH);
    delay(150);
    digitalWrite(pino, LOW);
    delay(100);
  }
  delay(100);

//Inicia os 3 pontos Lentos de S.O.S
  for (int x=0; x<3; x++) {
    digitalWrite(pino, HIGH);
    delay(500);
    digitalWrite(pino, LOW);
    delay(100);
  }
//Manda mais 3 piscadas rapidas
  for (int x=0; x<3; x++) {
    digitalWrite(pino, HIGH);
    delay(150);
    digitalWrite(pino, LOW);
    delay(100);
  }
  //Aguarda 2 segundos antes de recomecar.
  delay(2000);
}
  
