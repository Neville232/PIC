#include <MAESTRO_SPI_PW.h>

#use spi (MASTER, CLK=PIN_C3, DI=PIN_C4, DO=PIN_C5, BAUD=9600, MODE=0, BITS=8)

#define SPI_SS1   PIN_D0 
#define SPI_SS2   PIN_D1

// Modos de comunicación SPI 
#define SPI_MODE_0  (SPI_L_TO_H | SPI_XMIT_L_TO_H) 
#define SPI_MODE_1  (SPI_L_TO_H) 
#define SPI_MODE_2  (SPI_H_TO_L) 
#define SPI_MODE_3  (SPI_H_TO_L | SPI_XMIT_L_TO_H) 

// Comandos SPI que acepta el esclavo 
#define     ENCENDER_LED    0x01        
#define     APAGAR_LED      0x02   

void main() 
{ 
    char c; 

    // Configurar pines D0 y D1 como salidas
    //set_tris_d(0b11111100); // D0 y D1 como salidas, el resto como entradas

    // Configurar pines del puerto C para SPI
    //set_tris_c(0b11110010); // C0 (SS), C1 (MISO), C2 (MOSI), C3 (SCK) como salidas, el resto como entradas

    // Inicializa el Pin SS en alto para deshabilitar el esclavo
    output_high(SPI_SS1);  
    output_high(SPI_SS2);

    // Inicializa el hardware SSP para ser un SPI Maestro en Modo 0
    setup_spi(SPI_MASTER | SPI_MODE_0 | SPI_CLK_DIV_4); 

    printf("Comandos para el Esclavo:\n\r"); 
    printf("------------------------------------\n\r");
    printf("A --- para encender LED de Esclavo 1\n\r"); 
    printf("B --- para apagar LED de Esclavo 1\n\r"); 
    printf("C --- para encender LED de Esclavo 2\n\r"); 
    printf("D --- para apagar LED de Esclavo 2\n\r"); 
    printf("------------------------------------\n\r"); 
    printf("Escriba algun comando\n\r"); 

    // Si presiona la tecla correcta manda la orden al esclavo
    while(1) 
    { 
        c = getc(); // Captura el caracter del puerto serial RS232
        c = toupper(c); // Convierte el caracter en mayusculo

        switch(c) 
        { 
            case 'A':     
                output_low(SPI_SS1); 
                spi_write(0x01);  
                output_high(SPI_SS1); 
                delay_ms(10); // Pequeño retraso
                break; 

            case 'B':     
                output_low(SPI_SS1); 
                spi_write(0x02); 
                output_high(SPI_SS1); 
                delay_ms(10); // Pequeño retraso
                break; 

            case 'C':     
                output_low(SPI_SS2); 
                spi_write(ENCENDER_LED); 
                output_high(SPI_SS2); 
                delay_ms(10); // Pequeño retraso
                break; 

            case 'D':     
                output_low(SPI_SS2); 
                spi_write(APAGAR_LED); 
                output_high(SPI_SS2); 
                delay_ms(10); // Pequeño retraso
                break;
              
            default: 
                printf("%c es un caracter invalido.\n\r", c); 
                break; 
        } 
    } 
}
