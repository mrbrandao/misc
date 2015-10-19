/* Must recevive r ou w from serial and write on eeprom.
  If read command is sucess blink a led one time
  If write sucess blink led two times
*/
#include <EEPROM.h>

char buffer[9];
int r, w;
int led = 13;

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
  }


}


