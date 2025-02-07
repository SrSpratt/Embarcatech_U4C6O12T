#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include <General_U4C4.h>
#include <MainLED_U4C4.h>
#include <LEDMatrix_U4C4.h>
#include <Interrupt_U4C4.h>

#define PINS 5
#define BUTTONA 5
#define BUTTONB 6


int main(){

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


    interruptContext.pinToCompare[1] = BUTTONB;
    interruptContext.pinToCompare[0] = BUTTONA;

    int LEDPins[3] = {REDPIN, BLUEPIN, GREENPIN};

    SetRGBInterrupt(&TogglePinNoTime, BUTTONA, LEDPins);
    SetRGBInterrupt(&TogglePinNoTime, BUTTONB, LEDPins);

    
    printf("G DIR: %d\n",gpio_get_dir(11));
    printf("R DIR: %d\n",gpio_get_dir(12));
    printf("G DIR: %d\n",gpio_get_dir(13));

    printf("G VAL: %d\n",gpio_get(11));
    printf("R VAL: %d\n",gpio_get(12));
    printf("G VAL: %d\n",gpio_get(13));

    // for(int i = 0; i < PINS; i++)
    //     PrintPinOut(pins[i]);

    char a;
    while(1){

        a = getchar();
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


