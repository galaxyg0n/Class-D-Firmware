#include <includes/i2c.h>

volatile uint8_t* TWBR = (volatile uint8_t*) 0xB8;
volatile uint8_t* TWCR = (volatile uint8_t*) 0xBC;
volatile uint8_t* TWSR = (volatile uint8_t*) 0xB9;
volatile uint8_t* TWDR = (volatile uint8_t*) 0xBB;

// TWBR Register
int TWBR0   = 0;
int TWBR1   = 1;
int TWBR2   = 2;
int TWBR3   = 3;
int TWBR4   = 4;
int TWBR5   = 5;
int TWBR6   = 6;
int TWBR7   = 7;


// TWCR Register
int TWIE    = 0;
int TWEN    = 2;
int TWWC    = 3;
int TWSTO   = 4;
int TWSTA   = 5;
int TWEA    = 6;
int TWINT   = 7;


// TWSR Register
int TWPS0    = 0;
int TWPS1    = 1;
int TWS3     = 3;
int TWS4     = 4;
int TWS5     = 5;
int TWS6     = 6;
int TWS7     = 7;


// TWDR Register
int TWD0     = 0;
int TWD1     = 1;
int TWD2     = 2;
int TWD3     = 3;
int TWD4     = 4;
int TWD5     = 5;
int TWD6     = 6;
int TWD7     = 7;




void i2c_init(void)
{
    // Set prescaler bits to zero
    *TWSR = 0x00;

    // SCL frequency is 100k for XTAL = 16MHz
    *TWBR = 0x47;

    // Enable TWI module
    *TWCR = (1 << TWEN);

}

void i2c_start()
{
    *TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

    while((*TWCR & (1 << TWINT)) == 0);
}


void i2c_stop()
{
    *TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

    // No need to check TWINT bit for STOP condition
}


void i2c_write(unsigned char data)
{
    *TWDR = data;
    *TWCR = (1 << TWINT) | (1 << TWEN);

    while((*TWCR & (1 << TWINT)) == 0);
}
