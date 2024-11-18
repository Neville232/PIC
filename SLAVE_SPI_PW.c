#include <SLAVE_SPI_PW.h>
#use spi (SLAVE, CLK=PIN_C3, DI=PIN_C4, DO=PIN_C5, ENABLE=PIN_A5, MODE=0, BITS=8, STREAM=SPI_1)

INT8 dato;
#define LED PIN_A0


#INT_SSP
void recibe() {
   dato = spi_read();

   switch(dato) {
      case  0x01: 
         output_high(LED);
         break;
      
      case  0x02: 
         output_low(LED);
         break;
      
      default:
         break;
   } 
}

void main()
{
   // Configura A0 como salida para el LED
   //set_tris_a(0b11111110); // A0 como salida, A1-A5 como entradas
   
   // Configura los pines del SPI
   //set_tris_c(0b11111000); // C3, C4 como entradas (CLK y DI), C5 como salida (DO)
   //set_tris_a(0b11111011); // A5 como salida (ENABLE)
   
   enable_interrupts(INT_SSP);
   enable_interrupts(global);
   output_high(LED);
   
   while(TRUE)
   {


      //TODO: User Code
   }

}
