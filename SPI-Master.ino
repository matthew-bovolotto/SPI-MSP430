#include <msp430.h>

void spiSetup();
void spiSend_u16(int data);

//Master Library

int dataout;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  Serial.println("X---------------------------------------------X");
  Serial.println("Board Start Successful");
  Serial.println("X---------------------------------------------X");
  Serial.println("Serial Opened Succesfully");
  Serial.println("X---------------------------------------------X");
  spiSetup();  
}

// the loop routine runs over and over again forever:
void loop() {
  delay(1000);
  spiSend_u16(63);
  spiSend_u16(256);
  spiSend_u16(30000);
}

//----------------------------------------------------------------------------

void spiSetup(){
  /* Begin Setup of Pseudo SPI
   P1.2 - SS
   P1.3 - CLK
   P1.4 - MOSI
   P1.5 - MISO
   */
  P1DIR = BIT3 + BIT4; // enable pins 2-4 (SS, CLK, MOSI) as outputs
  P1DIR &= ~BIT5;
  P2DIR = BIT0;
  Serial.println("SPI Setup successful");
}

void spiSend_u16(int data){

/* Function writes a 16 bit character to the slave driver

1. Set SS high to signal beginning of write
2. Wait until acknowledged by the 
*/
  int timeout = 0;
  Serial.println("SPI Transmit Started");
  Serial.print("Value tranfer:");
  Serial.println(data);
  P2OUT |= BIT0;
  timeout=0;
  while(((P1IN & BIT5) >> 5) == 0){
    timeout+=1;
    if(timeout > 16){
      P2OUT &= ~BIT0;
      return;
    }
    delayMicroseconds(100);  // wait for acknowledgement from slave
    Serial.println("waiting for response");
  } 
  int output = 0; 
  for(int i = 0; i < 16; i++){
    P1OUT &= ~BIT3;  
    output = data & 1;
     if(output == 1){
      P1OUT |= BIT4;
    }else{
      P1OUT &= ~BIT4;
    }
    delay(1);
    P1OUT |= BIT3;
    delay(1);
    data = data >> 1;
  }
  Serial.println("Transfer Completed");
  P2OUT &= ~BIT0;
}
