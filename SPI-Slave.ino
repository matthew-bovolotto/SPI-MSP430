#include <msp430.h>
#include <spi_library.h>

void setup()
{
  #ifdef SERIAL
    Serial.begin(9600); // begin serial communication
    Serial.println("-Board Start Successful-");
  #endif

  volatile int long checkvalue = 0; //define variable for SPI to write into
}

void loop(){
    spi_Slave spi;

    if((P2IN & BIT0) == 1){ // check if SS bit has been set high
      checkvalue = spi.spiReceive_header();
    }

    #ifdef SERIAL
      Serial.println(checkvalue);
    #endif
}
