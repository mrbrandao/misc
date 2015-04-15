//Proheto 6 - Efetito de iluminacao sequecial com LEDs
// Com regulacao pelo potenciometro


byte ledPin[] = {4,5,6,7,8,9,10,11,12,13};
int ledDelay; //intervalo entre as alteracoes
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 2; // Seleciona o pino de entra do Potenciometro

void setup() {
  for (int x=0; x<10; x++){
    pinMode(ledPin[x], OUTPUT);
  }
  
  changeTime = millis();
}

void loop() {
  ledDelay = analogRead(potPin); //le o valor do potenciometro
  //verifica se ja transcorreram ledDelays em ms
  //desde a ultima alteracao 
  if ((millis() - changeTime) > ledDelay) {
    
    changeLED();
    changeTime = millis();
  }
}

void changeLED(){
  for (int x=0; x<10; x++){
    digitalWrite(ledPin[x], LOW);
  }
  digitalWrite(ledPin[currentLED], HIGH);
  //currentLED = currentLED + direction;
  currentLED += direction; //incrementa de acordo com o valor da direction
  //mesma coisa que currentLED = currentLED + direction
  if (currentLED == 9) {direction = -1;}
  if (currentLED == 0) {direction = 1;}
}
