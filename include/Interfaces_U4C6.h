#ifndef INTERFACES_U4C6_H
#define INTERFACES_U4C6_H

#include "hardware/i2c.h"
#include "ssd1306.h"

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C



void I2CInit(ssd1306_t*);
void I2CDraw(ssd1306_t*, bool, char*);

#endif