/* Must recevive r ou w from serial and write on eeprom.
  If read command is sucess blink a led one time
  If write sucess blink led two times
*/
#include <EEPROM.h>

int r,w;
int addr = 0;
byte value;
int serialData = 0;

void setup()
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(13, OUTPUT);  
}


void ok()
{
    if (Serial.available() > 0) { 
        
      serialData = Serial.read();
    
      if (serialData == 49) { //just test to get 49 ASCII from serial and print
          Serial.println("Ok, vc achou 1");
          digitalWrite(13,1);
          delay(500);
          digitalWrite(13,0);
          delay(500);  
       }
 
      Serial.println(serialData);
  }
} //close ok function


void read_ee()
{
  value = EEPROM.read(addr);
  Serial.println("Adrress........DEC value");
  Serial.print(addr);
  Serial.print("\t");
  Serial.println(value, DEC);
  addr = addr +1;
  if (addr == EEPROM.length()) {
    addr = 0;
  }
  delay(250);
}
  

void loop() {
          if (Serial.available() > 0){
            
  
  // read a byte from the current address of the EEPROM
  ok();
  read_ee();
}
