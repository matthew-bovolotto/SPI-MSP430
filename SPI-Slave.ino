#include <msp430.h>
#define LED RED_LED

void spiSetup();
int spiReceive_u16();

void setup()
{
  Serial.begin(9600);
  spiSetup();
  pinMode(LED, OUTPUT);
}

void loop(){
  int checkvalue = ((P1IN & BIT1) >> 1);
  if(checkvalue == 1){
    checkvalue = spiReceive_u16();  
    Serial.println(checkvalue);
  }
  delay(10000);
}


void spiSetup(){
   P1DIR &= ~BIT1 + ~BIT3 + ~BIT4;
   P1DIR |= BIT5;
   P1OUT &= ~BIT5;
}

int spiReceive_u16(){
  int value = 0;
  P1OUT |= BIT5;
  delayMicroseconds(300);
  P1OUT &= ~BIT5;
  for(int i = 0; i < 16; i++){
    while(((P1IN & BIT3) >> 3) == 0){
      delayMicroseconds(1);
    }
    value += ((P1IN & BIT4) >> 4);
    value = value << 1;
    while(((P1IN & BIT3) >> 3) == 1){
      delayMicroseconds(1);
    }
  }
  return value;
}
