#ifndef LEDMATRIXU4C4_H
#define LEDMATRIXU4C4_H

#include "General_U4C4.h"

#define MATRIXPIN 7 // Número do pino para a matriz de LEDs.
#define VECTORSIZE 25 // Tamanho do vetor que representa a matriz de LEDs (5x5).

typedef struct Drawing {
    double Figure[25]; // Vetor de 25 valores representando a figura a ser exibida na matriz.
    int Index; // Guarda o valor do desenho
    RGB MainColor;     // Cor principal a ser exibida na matriz de LEDs.
    RGB BackgroundColor; // Cor de fundo da matriz de LEDs.
} Sketch;

void PrintArraySketch(double* array, int size);


void PrintSketch(Sketch sketch);

double* SketchArray(int index);

void ArrayCopySameSize(double* src, double* dest, int size);

uint32_t RGBMatrix(RGB color);


void Draw(Sketch sketch, uint32_t ledConf, PIORefs pio);


void Count(Sketch sketch, uint32_t ledConf, PIORefs pio, int delay);

#endif
