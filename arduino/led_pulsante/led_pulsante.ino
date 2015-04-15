// Projeto 7 - Lampada pulsante
int ledPin = 9;
float sinVal;
int ledVal;

void setup(){
  pinMode(ledPin, OUTPUT);
}

void loop(){
  for (int x=0; x<180; x++){
    //converte graus para radianos e, entao, obtem o valor do seno
    sinVal = (sin(x*(3.1416/180)));
    ledVal = int(sinVal*255);
    analogWrite(ledPin, ledVal);
    delay(25);
  }
}
