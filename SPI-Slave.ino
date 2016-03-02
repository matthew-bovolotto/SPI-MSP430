#include <msp430.h>
#include <spi_library.h>

void setup()
{
  #ifdef SERIAL
    Serial.begin(9600); // begin serial communication
  #endif
}

void loop(){
    spi_Slave spi;
    int ran = 0;
    int long checkvalue = 0; //define variable for SPI to write into
    if((P2IN & BIT0) == 1){ // check if SS bit has been set high
      checkvalue = spi.spiReceive_header();
      ran = 1;
    }

  // Print out array of variables taken in by SPI

    #ifdef SERIAL
    if(ran > 0){
      Serial.println(checkvalue);
    }
    #endif
    delay(1);
}
