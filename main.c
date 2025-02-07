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

    //InitPIO(&pio, MATRIXPIN);

    //Draw(sketch, ledConf, pio);


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

    while(1){

        //printf("RED: %d, BLUE: %d, GREEN: %d\n", gpio_get(13),gpio_get(12),gpio_get(11));
        sleep_ms(1);
    }


}


