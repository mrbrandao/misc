int a = 7;
int b = 8;
int c = 9;
int d = 11;
int e = 12;
int f = 10;
int g = 13;

void setup(){
  
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop(){
  digitalWrite(a, HIGH);
  delay(300);
  digitalWrite(a, LOW);
}
  
  
