#include <msp430.h>
#define LED RED_LED

void spiSetup();
int spiStart_u16(int data);

//Master Library

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);

  pinMode(LED, OUTPUT);

  //spiSetup();
}

// the loop routine runs over and over again forever:
void loop() {
  delay(100);
  Serial.println("hello world");
}

void spiSetup(){
  /* Begin Setup of Pseudo SPI
   P1.2 - SS
   P1.3 - CLK
   P1.4 - MOSI
   P1.5 - MISO
   */
  Serial.println("SPI Setup");
  //P1DIR |= 0b011100; // enable pins 2-4 (SS, CLK, MOSI) as outputs 
}

int spiStart_u16(int data){
  Serial.println("SPI Started");
}

