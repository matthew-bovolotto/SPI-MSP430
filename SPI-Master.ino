#include <msp430.h>
#include <spi_library.h>
#define SERIAL
// #undef SERIAL

// the setup routine runs once when you press reset:

void setup() {
  #ifdef SERIAL
    Serial.begin(9600);
    Serial.println("-Board Start Successful-");
  #endif
}

void loop(){
  volatile int return_value = 0;
  unsigned int spi_data_out = 1;
  spi_Master spi; //create object spi -- setups all required pins for spi

  for(int i = 0; i < 14; i++){
    spi_data_out = spi_data_out << 1; // left shift through 2 -> 65536

    do{
      return_value = spi.spiSend_Header(2); // sends header with value 2 -- 16 bit unsigned integer
      delayMicroseconds(100);
    }while(return_value > 0); // check to make sure header didnt timeout

    delayMicroseconds(25);

    do{
      return_value = spi.spiSend_u16(spi_data_out); // sends 16 bit value
      delayMicroseconds(100);
    }while(return_value > 0); // check to make sure data didnt timeout

    delay(10);  
  }
  #ifdef SERIAL
    Serial.println("successful transfer");
  #endif
}
