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
  int checkvalue = ((P2IN & BIT0));
  if(checkvalue == 1){
    checkvalue = spiReceive_u16();  
    Serial.println(checkvalue);
  }
}


void spiSetup(){
   P1DIR &= ~BIT3 + ~BIT4;
   P1DIR |= BIT5;
   P1OUT &= ~BIT5;
   P2DIR &= ~BIT0;
}

int spiReceive_u16(){
  int value = 0;
  int timeout = 0;
  P1OUT |= BIT5;
  for(int i = 0; i < 16; i++){
    timeout=0;
    while(((P1IN & BIT3) >> 3) == 0){
      timeout+=1;
      if(timeout > 40){
        P1OUT &= ~BIT5;
        return 0;
      }
      delayMicroseconds(100);  
    }
    value |= (((P1IN & BIT4) >> 4) << i-1);
    timeout=0;
    while(((P1IN & BIT3) >> 3) == 1){
      timeout+=1;
      if(timeout > 40){
        P1OUT &= ~BIT5;
        return 0;
      }
      delayMicroseconds(100);  
    }
  }
  P1OUT &= ~BIT5;
  return value;
}
