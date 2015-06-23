/* -- Teste de Botao --
Um teste bobo pra ver o funcionamento do botao.
Este este faz com que o Led apague por 2segundos quando
o botao for pressionado*/
int ledPin = 8;
int button = 2;

void setup(){
	Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT);
}

void loop(){
  digitalWrite(ledPin, HIGH);
  int state = digitalRead(button);
  if (state == HIGH){
    digitalWrite(ledPin, LOW);
    delay(2000);
    Serial.println(state);
  }
}
