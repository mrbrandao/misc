// PROJETO 23
#include <LiquidCrystal.h>
// Inicializa a biblioteca com os números dos pinos de interface
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);		 // Cria um objeto lcd e atribui os pinos
void setup() {
	 lcd.begin(16, 2);		 // Define o display com 16 colunas e 2 linhas
}
void loop() {
	 // Executa as sete rotinas de demonstração
	 basicPrintDemo();
	 displayOnOffDemo();
	 setCursorDemo();
	 scrollLeftDemo();
	 scrollRightDemo();
	 cursorDemo();
	 createGlyphDemo();
}
void basicPrintDemo() {
	 lcd.clear();					 // Limpa o display
lcd.print("Basic Print");		 // Imprime algum texto
	 delay(2000);
}
void displayOnOffDemo() {
	 lcd.clear();						 // Limpa o display
	 lcd.print("Display On/Off");		 // Imprime algum texto
	 for(int x=0; x < 3; x++) {			 // Itera 3 vezes
		 lcd.noDisplay();				 // Apaga o display
		 delay(1000);
		 lcd.display();					 // Acende-o novamente
		 delay(1000);
	 }
}
void setCursorDemo() {
	 lcd.clear();					 // Limpa o display
	 lcd.print("SetCursor Demo");	// Imprime algum texto
	 delay(1000);
	 lcd.clear();					 // Limpa o display
	 lcd.setCursor(5,0);				 // Cursor na coluna 5, linha 0
	 lcd.print("5,0");
	 delay(2000);
	 lcd.setCursor(10,1);			 // Cursor na coluna 10, linha 1
	 lcd.print("10,1");
	 delay(2000);
	 lcd.setCursor(3,1);				 // Cursor na coluna 3, linha 1
	 lcd.print("3,1");
	 delay(2000);
}
void scrollLeftDemo() {
	 lcd.clear();					 // Limpa o display
	 lcd.print("Scroll Left Demo");
	 delay(1000);
	 lcd.clear();					 // Limpa o display
	 lcd.setCursor(7,0);
	 lcd.print("Beginning");
	 lcd.setCursor(9,1);
	 lcd.print("Arduino");
	 delay(1000);
	 for(int x=0; x<16; x++) {
		 lcd.scrollDisplayLeft();		 // Rola o display 16 vezes para a esquerda
		 delay(250);
	 }
}
void scrollRightDemo() {
	 lcd.clear();					 // Limpa o display
	 lcd.print("Scroll Right");
	 lcd.setCursor(0,1);
	 lcd.print("Demo");
	 delay(1000);
	 lcd.clear();					 // Limpa o display
	 lcd.print("Beginning");
	 lcd.setCursor(0,1);
	 lcd.print("Arduino");
	 delay(1000);
	 for(int x=0; x<16; x++) {
		 lcd.scrollDisplayRight();	 // Rola o display 16 vezes para a direita
		 delay(250);
	 }
}
void cursorDemo() {
	 lcd.clear();		 // Limpa o display
	 lcd.cursor();		 // Cursor visível
	 lcd.print("Cursor On");
	 delay(3000);
	 lcd.clear();			 // Limpa o display
	 lcd.noCursor();		 // Cursor invisível
	 lcd.print("Cursor Off");
	 delay(3000);
	 lcd.clear();		 // Limpa o display
	 lcd.cursor();		 // Cursor visível
	 lcd.blink();		 // Cursor piscando
	 lcd.print("Cursor Blink On");
	 delay(3000);
	 lcd.noCursor();		 // Cursor invisível
	 lcd.noBlink();		 // Efeito blink desligado
}
void createGlyphDemo() {
	 lcd.clear();
	
	
	
	
	
	
byte happy[8] = {		 // Cria um array de bytes com uma cara feliz
B00000,
B00000,
B10001,
B00000,
B10001,
B01110,
	 B00000,
	 B00000};
	
	
	
	
	
	
	
	
	
byte sad[8] = {		 // Cria um array de bytes com uma cara triste
B00000,
B00000,
B10001,
B00000,
B01110,
B10001,
B00000,
B00000};
	 lcd.createChar(0, happy);		 // Cria o caractere personalizado 0
	 lcd.createChar(1, sad);		 // Cria o caractere personalizado 1
	 for(int x=0; x<5; x++) { 		 // Executa a animação 5 vezes
		 lcd.setCursor(8,0);
		// lcd.write(0);							 // Escreve o caractere personalizado 0
		 delay(1000);
		 lcd.setCursor(8,0);
		//lcd.write(1);							 // Escreve o caractere personalizado 1
		 delay(1000);
	 }
}
