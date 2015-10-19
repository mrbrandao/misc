/* Must recevive r ou w from serial and write on eeprom.
  If read command is sucess blink a led one time
  If write sucess blink led two times
*/
#include <EEPROM.h>

char buffer[9];
int r, w;
int led = 13;
int addr = 0;
byte value;

void blinker(int pisca){
  while (pisca != 0){
    digitalWrite(led, 1);
    delay(200);
    digitalWrite(led, 0);
    delay(200);
    pisca--;
  }
}

void eeread(char* data){
  if (data[0] == 'r') {
    addr = strtol(data+1, NULL,10);
    addr = constrain(addr,0,1023);
    value = EEPROM.read(addr);
    blinker(1);
    Serial.print("The address ");
    Serial.print(addr);
    Serial.print(" has this value: ");
    Serial.println(value);
  }
}
    

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.flush();
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
        int index=0;
        delay(100); //espaco pro buffer
        int numChar = Serial.available();
        if (numChar>9) {
              numChar=9;
        }
        while (numChar--) {
                buffer[index++] = Serial.read();
        }
        eeread(buffer);
        for (int  x=0; x<9;x++){
          buffer[x]='\0';
        }
  }


}


