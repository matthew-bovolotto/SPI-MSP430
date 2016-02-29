#include <msp430.h>
#include <spi_library.h>

void setup()
{
  #ifdef SERIAL
    Serial.begin(9600); // begin serial communication
  #endif
}

int checkvalue = 0; //define variable for SPI to write into
int array[9]; //array for SPI to write into

spi_Slave spi;

void loop(){
  for(int j=0; j < 9;){ // receive 9 integers

    if((P2IN & BIT0) == 1){ // check if SS bit has been set high
      checkvalue = spi.spiReceive_u16();
      array[j] = checkvalue;
      j++;
    }

  }

  // Print out array of variables taken in by SPI

  for(int i = 0; i < 9; i++){
    #ifdef SERIAL
      Serial.print(array[i]);
      Serial.print(", ");
    #else
      delayMicroseconds(10);
    #endif
    
  }
  #ifdef SERIAL
    Serial.println();
  #endif
}
