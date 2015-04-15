//Projeto de Semaforos
//Sistema Brasileiro de Semaforos
int ledDelay = 5000; //espera entre as alteracoes

int redPin = 8;
int yellowPin = 9;
int greenPin = 10;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}
void loop() {
   digitalWrite(redPin, HIGH);
   delay(ledDelay);
   digitalWrite(redPin, LOW);
   digitalWrite(yellowPin, HIGH);
   delay(1000);
   digitalWrite(yellowPin, LOW);
   digitalWrite(greenPin, HIGH);
   delay(ledDelay);
   digitalWrite(greenPin, LOW);
   digitalWrite(yellowPin, HIGH);
   delay(1000);
   digitalWrite(yellowPin, LOW);
}
