#ifndef GENERALU6C_H
#define GENERALU6C_H

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include <Interfaces_U4C6.h>


typedef struct PinSet {
    int Pin;   /// Número do pino GPIO.
    bool Input; /// Define se o pino será entrada ou saída.
} PinOut;


typedef struct PIO {
    PIO Address; //Ponteiro para PIO
    int StateMachine; // Endereço da máquina de estados
    int Offset; // Valor do offset
} PIORefs;


typedef struct RGB {
    double Red;
    double Green;
    double Blue;
} RGB;

void PrintPinOut(PinOut);

void PrintPIO(PIORefs);

void PrintRGB(RGB);

void Config(PinOut*, int, PIORefs*);

void InitPIO(PIORefs*, int);

void InitPin(int, bool);

void SetInput(int);

void SetOutput(int);

#endif
