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

}

spi_Master spi;
int spi_successful;

void loop() {
  spi.spiSend_Header(0b0010);
  spi_successful = spi.spiSend_u16(25);
  if(spi_successful > 0){spi_successful=1;}

  #ifdef SERIAL 
    Serial.println("successful transfer");
  #endif  
  delay(1000);
}





