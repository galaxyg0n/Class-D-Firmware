// Define MCU 
#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif


#ifndef F_CPU
   #define F_CPU 16000000UL     
#endif

// SPI interface
#define MISO PC0
#define MOSI PE3
#define SS   PB2

// UART interface
#define TXD PD1
#define RXD PD0

// Display interface
#define OLED_SDA PD0
#define OLED_SCL PD1
