#include <msp430.h>
#include <spi_library.h>
// #undef SERIAL
#define SERIAL



// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  #ifdef SERIAL 
    Serial.begin(9600);
    Serial.println("X---------------------------------------------X");
    Serial.println("Board Start Successful");
    Serial.println("X---------------------------------------------X");
    Serial.println("Serial Opened Succesfully");
    Serial.println("X---------------------------------------------X");
  #endif

}



void loop(){
  spi_Master spi;
  unsigned int hello = 2;
  unsigned int hello2 = 15;
  spi.spiSend_Header(hello);
  delayMicroseconds(25);  
  spi.spiSend_u16(hello2);
  delay(10);
  
  #ifdef SERIAL 
    Serial.println("successful transfer");
  #endif  
  
}





