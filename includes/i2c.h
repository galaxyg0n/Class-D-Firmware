#ifndef i2c_H
    #define i2c_H
#endif

#include <stdio.h>

// I2C Registers
extern volatile uint8_t* TWBR;
extern volatile uint8_t* TWCR;
extern volatile uint8_t* TWSR;
extern volatile uint8_t* TWDR;


// TWBR Register
extern int TWBR0;
extern int TWBR1;
extern int TWBR2;
extern int TWBR3;
extern int TWBR4;
extern int TWBR5;
extern int TWBR6;
extern int TWBR7;

// TWCR Register
extern int TWIE;
extern int TWEN;
extern int TWWC;
extern int TWSTO;
extern int TWSTA;
extern int TWEA;
extern int TWINT;


// TWSR Register
extern int TWPS0;
extern int TWPS1;
extern int TWS3;
extern int TWS4;
extern int TWS5;
extern int TWS6;
extern int TWS7;


// TWDR Register
extern int TWD0;
extern int TWD1;
extern int TWD2;
extern int TWD3;
extern int TWD4;
extern int TWD5;
extern int TWD6;
extern int TWD7;


// Define functions
void i2c_init();
void i2c_start();
void i2c_stop();
void i2c_write(unsigned char data);