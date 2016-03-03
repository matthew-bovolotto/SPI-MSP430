#include <msp430.h>
#include <spi_library.h>
// #undef SERIAL

// the setup routine runs once when you press reset:
void setup() {
  volatile bool return_value = 0;
  #ifdef SERIAL
    Serial.begin(9600);
    Serial.println("-Board Start Successful-");
  #endif
}

void loop(){
  unsigned int spi_data_out = 1;

  for(int i = 0; i < 15; i++){
    spi_data_out = spi_data_out << 1; // left shift through 2 -> 65536

    spi_Master spi; //create object spi -- setups all required pins for spi

    do{
      return_value = spi.spiSend_Header(2); // sends header with value 2 -- 16 bit unsigned integer
      delayMicroseconds(100);
    }while(return_value > 0); // check to make sure header didnt timeout

    delayMicroseconds(25);

    do{
      return_value = spi.spiSend_u16(x); // sends 16 bit value
      delayMicroseconds(100);
    }while(return_value > 0); // check to make sure data didnt timeout

    delay(10);  
  }
  #ifdef SERIAL
    Serial.println("successful transfer");
  #endif
  }
}
