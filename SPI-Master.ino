#include <msp430.h>
#include <spi_library.h>
#define SERIAL
#undef SERIAL

// the setup routine runs once when you press reset:

void setup() {
#ifdef SERIAL
  Serial.begin(9600);
  Serial.println("-Board Start Successful- M");
#endif
}

int return_value = 0;
unsigned int spi_data_out[4] = {0xAA55,0xAA55,0xAA55,0xAA55};
unsigned int spi_data_out2[4] = {0x55AA,0x55AA,0x55AA,0x55AA};

void loop(){
    
  //if(Serial.available()){
    //spi_data_out = Serial.read() - 48;
  
  for(int i = 0; i<4; i++){
    
    spi_Master spi; //create object spi -- setups all required pins for spi

    do{
      return_value = spi.spiSend_Header(2); // sends header with value 2 -- 16 bit unsigned integer
 
    }
    while(return_value > 0); // check to make sure header didnt timeout


    do{
      return_value = spi.spiSend_u16(spi_data_out[i]); // sends 16 bit val

    }
    while(return_value > 0); // check to make sure data didnt timeout
  } 
    
  for(int i = 0; i<4; i++){
    
    spi_Master spi; //create object spi -- setups all required pins for spi

    do{
      return_value = spi.spiSend_Header(2); // sends header with value 2 -- 16 bit unsigned integer
 
    }
    while(return_value > 0); // check to make sure header didnt timeout


    do{
      return_value = spi.spiSend_u16(spi_data_out2[i]); // sends 16 bit value

    }
    while(return_value > 0); // check to
    
    #ifdef SERIAL
    Serial.print("successful transfer  ");
    Serial.println(spi_data_out);
    #endif
  }
}

