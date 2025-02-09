#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "hardware/i2c.h"
#include <ssd1306.h>
#include <font.h>
#include <General_U4C6.h>
#include <MainLED_U4C6.h>
#include <LEDMatrix_U4C6.h>
#include <Interrupt_U4C6.h>
#include <Interfaces_U4C6.H>

#define PINS 5
#define BUTTONA 5
#define BUTTONB 6



int main(){

    ssd1306_t ssd;
    bool cor = true;  

    PIORefs pio;

    PinOut pins[PINS] = {
        { 
            .Pin = REDPIN, 
            .Input = false
        },
        { 
            .Pin = BLUEPIN, 
            .Input = false
        },
        { 
            .Pin = GREENPIN, 
            .Input = false
        },
        { 
            .Pin = BUTTONA, 
            .Input = true
        },
        { 
            .Pin = BUTTONB, 
            .Input = true
        }
    };
    Sketch sketch = {
        .Figure = {
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0,
            0.0, 0.0, 0.0, 0.0, 0.0
        },
        .Index = -1,
        .MainColor = {
            .Red = 0.01,
            .Green = 0.0,
            .Blue = 0.0
        },
        .BackgroundColor = {
            .Red = 0.0,
            .Green = 0.0,
            .Blue = 0.01
        }
    };
    uint32_t ledConf = 0;

    Config(pins, PINS, &pio);

    InitPIO(&pio, MATRIXPIN);

    Draw(sketch, ledConf, pio);

    I2CInit(&ssd);


    interruptContext.pinToCompare[1] = BUTTONB;
    interruptContext.pinToCompare[0] = BUTTONA;
    interruptContext.SSD = &ssd;

    int LEDPins[3] = {REDPIN, BLUEPIN, GREENPIN};

    SetRGBInterrupt(&TogglePinNoTime, BUTTONA, LEDPins, &HandleDisplayInterruptI2C);
    SetRGBInterrupt(&TogglePinNoTime, BUTTONB, LEDPins, &HandleDisplayInterruptI2C);

    char a;
    while(1){

        a = getchar();
        if (a >= '0' && a <= 'z'){
            char string[12] = {'C', 'a', 'r', 'a', 'c', 't', 'e', 'r', ':', ' ', a, '\0'};
            I2CDraw(&ssd, cor, string);
        }
        
        switch(a){
            case '0':
                ArrayCopySameSize(sketch.Figure, SketchArray(0), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '1':
                ArrayCopySameSize(sketch.Figure, SketchArray(1), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '2':
                ArrayCopySameSize(sketch.Figure, SketchArray(2), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '3':
                ArrayCopySameSize(sketch.Figure, SketchArray(3), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '4':
                ArrayCopySameSize(sketch.Figure, SketchArray(4), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '5':
                ArrayCopySameSize(sketch.Figure, SketchArray(5), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '6':
                ArrayCopySameSize(sketch.Figure, SketchArray(6), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '7':
                ArrayCopySameSize(sketch.Figure, SketchArray(7), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '8':
                ArrayCopySameSize(sketch.Figure, SketchArray(8), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;
            case '9':
                ArrayCopySameSize(sketch.Figure, SketchArray(9), VECTORSIZE);
                Draw(sketch, ledConf, pio);
                break;

        }
        sleep_ms(1);
    }


}


