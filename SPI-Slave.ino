#include <msp430.h>
#include <spi_library.h>
#define SERIAL

void setup()
{
  #ifdef SERIAL
    Serial.begin(9600); // begin serial communication
    Serial.println("-Board Start Successful-");
  #endif
}

void loop(){
    volatile unsigned int checkvalue = 0; //define variable for SPI to write into
    spi_Slave spi;

    if((P2IN & BIT0) == 1){ // check if SS bit has been set high
      do{
        checkvalue = spi.spiReceive_header();
      }while(checkvalue == 0);
    #ifdef SERIAL
      Serial.print("Checkvalue = ");
      Serial.println(checkvalue);
    #endif
    }
    delay(100);
}
