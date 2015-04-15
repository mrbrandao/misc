#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
   lcd.begin(16,2);
}

void loop(){
  sayhello();
  pisca();
}

void pisca(){
  for (int x=0; x<3; x++){
    lcd.print("hehehhehe");
    delay(500);
    lcd.clear();
    delay(250);
  }
}

void sayhello(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("<======(oo)");
  lcd.setCursor(0,1);  
  lcd.print("");
  delay(500);
  for (int x=0; x<16; x++){
     lcd.scrollDisplayRight();
     delay(200);
  }  
}
