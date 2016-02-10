#include <msp430.h>
#define LED RED_LED

void spiSetup();
unsigned int spiReceive_u16();

void setup()
{
  Serial.begin(9600);
  spiSetup();
  pinMode(LED, OUTPUT);
}

int checkvalue = 0;
int array[9];

void loop(){
  for(int j=0; j < 9; j = j){
    if((P2IN & BIT0) == 1){
      checkvalue = spiReceive_u16(); 
      array[j] = checkvalue;
      j++; 
    }
  } 
  for(int i = 0; i < 9; i++){
    Serial.print(array[i]);
    Serial.print(", ");
  }
  Serial.println();
}


void spiSetup(){
   P1DIR &= ~BIT3 + ~BIT4;
   P1DIR |= BIT5;
   P1OUT &= ~BIT5;
   P2DIR &= ~BIT0;
}

unsigned int spiReceive_u16(){
  unsigned int value = 0;
  int timeout = 0;
  P1OUT |= BIT5;
  for(int i = 0; i < 16; i++){
    timeout=0;
    while(((P1IN & BIT3) >> 3) == 0){
      timeout+=1;
      if(timeout > 1000){
        P1OUT &= ~BIT5;
        Serial.println("failure");
        return 0;
      }
    }
    value += (((P1IN & BIT4) >> 4) << i-1);
    timeout=0;
    while(((P1IN & BIT3) >> 3) == 1){
      timeout+=1;
      if(timeout > 1000){
        P1OUT &= ~BIT5;
        Serial.println("failure");
        return 0;
      }
    }
  }
  P1OUT &= ~BIT5;
  return value;
}
