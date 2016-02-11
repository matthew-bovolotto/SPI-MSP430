#include <msp430.h>
#include <spi_library.h>
// #undef SERIAL

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
  spi_Master_Setup();  
}

void loop() {
  spiSend_u16(0);
  spiSend_u16(1);
  spiSend_u16(2);
  spiSend_u16(3);
  spiSend_u16(4);
  spiSend_u16(5);
  spiSend_u16(6);
  spiSend_u16(7);
  spiSend_u16(8);
  #ifdef SERIAL 
    Serial.println("successful transfer");
  #endif  
  delay(1000);
}





