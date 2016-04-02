#include <msp430.h>
#include <spi_library.h>
#include <disp_frame.h>
//#define SERIAL

void spiReceive_u16x4(unsigned int[]);

void setup()
{
  #ifdef SERIAL
    Serial.begin(9600); // begin serial communication
    Serial.println("-Board Start Successful- S");
  #endif
}

unsigned int checkvalue[4] = {0,0,0,0}; //define variable for SPI to write into
unsigned long frame[8];
unsigned long frame2[8] = {0x00FF,0,0,0,0x00FF,0,0,0};
spi_Slave spi;
frame_display dispfram;

void loop(){
    spi.spiReceive_u16x4(checkvalue);
      #ifdef SERIAL
      Serial.print("Checkvalue = ");
      Serial.println(checkvalue[0]);
      Serial.println(checkvalue[1]);
      Serial.println(checkvalue[2]);
      Serial.println(checkvalue[3]);
      #endif
   
     for(int i=0; i<8; i+=2){
       frame[i] = checkvalue[i/2] & 0xFF;
       frame[i+1] = (checkvalue[i/2] & 0xFF00) >> 8;
    }
    
      #ifdef SERIAL
      Serial.print("Checkvalue = ");
      for(int i=0; i<8; i++){
      Serial.pr intln(frame[i], HEX);
      }
      #endif
    
    for(int i=0; i <50; i++){
      dispfram.disp_frame(frame);
    }
}


