#include <msp430.h>
#include <spi_library.h>

void setup()
{
  #ifdef SERIAL
    Serial.begin(9600); // begin serial communication
  #endif
}

int long checkvalue = 0; //define variable for SPI to write into

spi_Slave spi;

void loop(){
    if((P2IN & BIT0) == 1){ // check if SS bit has been set high
      checkvalue = spi.spiReceive_Header();
    }

  }

  // Print out array of variables taken in by SPI

    #ifdef SERIAL
      Serial.print(checkvalue);
    #else
      delayMicroseconds(10);
    #endif
    
  }
  #ifdef SERIAL
    Serial.println();
  #endif
}
