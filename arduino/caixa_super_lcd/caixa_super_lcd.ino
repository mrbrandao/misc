//CAIXA DE SUPERMERCADO
//Apenas um caixa simples que requisita o proximo cliente
//quando o botao eh apertado

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int button = 6;
int led = 7;
int buz = 10;

void setup(){
   lcd.begin(16,2);
   pinMode(button, INPUT);
   pinMode(led,OUTPUT);
   pinMode(buz,OUTPUT);
}

void loop(){
  int state = digitalRead(button);
  if (state == HIGH){
    caixa();
        
  }
  else{
    promocao();
  }
}

void promocao(){
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Cachorro quente");
  lcd.setCursor(0,1);
  lcd.print("Apenas 1R$");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Absorvente Macho");
  lcd.setCursor(0,1);
  lcd.print("10 por 20R$");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Compre aqui");
  lcd.setCursor(0,1);
  lcd.print("e ganhe um abraco");
  delay(2000);
  lcd.clear();


}

void caixa(){
//Acende o CAIXA
     digitalWrite(led,HIGH);
     
     //Emite o Tone de Alerta
     tone(buz,1500);
     delay(200);
     noTone(buz);
     tone(buz,700);
     delay(200);
     noTone(buz);
     tone(buz,4000);
     delay(300);
     noTone(buz);
     
     //Manda a mensagem para o LCD
    lcd.print("CAIXA 1");
    delay(1000);
    lcd.clear();
    
    //Apaga o Led do CAIXA
    digitalWrite(led,LOW);
    
    //FadeOut no Tone
     tone(buz,2000);
     delay(300);
     noTone(buz);
     tone(buz,300);
     delay(200);
     noTone(buz);
    tone(buz,500);
     delay(200);
     noTone(buz);

}
