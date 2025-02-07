#ifndef INTERRUPTU4C4_H
#define INTERRUPTU4C4_H

#include <General_U4C4.h>
#include "LEDMatrix_U4C4.h"


typedef void (*InterruptNewCallback)(uint8_t);

typedef struct {
    InterruptNewCallback Callback;
    Sketch sketch;              /** Estrutura contendo os dados do desenho. */
    uint32_t ledConf;           /** Configuração dos LEDs a ser utilizada. */
    PIORefs pio;                /** Referências para o PIO. */
    int inputPin;               /** Pino de entrada que ativa a interrupção. */
    int pinToCompare[2];           /** Pino que será comparado para disparar a interrupção. */
    int RGBPin[3];
} InterruptContext;

extern InterruptContext interruptContext;


void SetRGBInterrupt(InterruptNewCallback callback, int inputPin, int pins[3]);

void HandleInterruptRGB(uint gpio, uint32_t events);

#endif
