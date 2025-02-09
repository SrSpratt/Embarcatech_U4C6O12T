#ifndef INTERRUPTU4C6_H
#define INTERRUPTU4C6_H

#include <General_U4C6.h>
#include "LEDMatrix_U4C6.h"


typedef void (*InterruptNewCallback)(uint8_t);

typedef void (*InterruptDisplayCallback)(ssd1306_t*, uint8_t);

typedef struct {
    InterruptNewCallback Callback;
    InterruptDisplayCallback DisplayCallback;
    int inputPin;               /** Pino de entrada que ativa a interrupção. */
    int pinToCompare[2];           /** Pino que será comparado para disparar a interrupção. */
    int RGBPin[3];
    ssd1306_t* SSD;
} InterruptContext;

extern InterruptContext interruptContext;


void SetRGBInterrupt(InterruptNewCallback callback, int inputPin, int pins[3], InterruptDisplayCallback displayCallback);

void HandleInterruptRGB(uint gpio, uint32_t events);

void HandleDisplayInterruptI2C(ssd1306_t* ssd, uint8_t pin);


#endif
