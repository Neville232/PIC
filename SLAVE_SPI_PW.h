#include <16F877A.h>
#device ADC=10
#use delay(crystal=4MHz)
#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7,stream=PC, parity=N, bits=8) 

