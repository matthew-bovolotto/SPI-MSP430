#include <msp430.h>
#define SERIAL

void spi_Master_Setup();
void spiSend_u16(unsigned int data);

void spi_Slave_Setup();
unsigned int spiReceive_u16();

