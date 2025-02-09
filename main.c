#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "hardware/i2c.h"
#include <ssd1306.h>
#include <font.h>
#include <General_U4C4.h>
#include <MainLED_U4C4.h>
#include <LEDMatrix_U4C4.h>
#include <Interrupt_U4C4.h>
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C

#define PINS 5
#define BUTTONA 5
#define BUTTONB 6


int main(){

    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    ssd1306_t ssd;
    ssd1306_init(&ssd, WIDTH, HEIGHT, false, endereco, I2C_PORT);
    ssd1306_config(&ssd); // Configura o display
    ssd1306_send_data(&ssd); // Envia os dados para o display

    // Limpa o display. O display inicia com todos os pixels apagados.
    ssd1306_fill(&ssd, false);
    ssd1306_send_data(&ssd);

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
            .Red = 0.00,
            .Green = 0.0,
            .Blue = 0.0
        },
        .BackgroundColor = {
            .Red = 0.0,
            .Green = 0.0,
            .Blue = 0.00
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

        cor = !cor;
        // Atualiza o conteúdo do display com animações
        ssd1306_fill(&ssd, !cor); // Limpa o display
        ssd1306_rect(&ssd, 3, 3, 122, 58, cor, !cor); // Desenha um retângulo
        //ssd1306_draw_string(&ssd, "CEPEDI   TIC37", 8, 10); // Desenha uma string
        ssd1306_draw_string(&ssd, "abcdefghijkl", 10, 30); // Desenha uma string
        ssd1306_draw_string(&ssd, "mnopqrstuvxwz", 10, 48); // Desenha uma string      
        ssd1306_send_data(&ssd); // Atualiza o display

        sleep_ms(1000);
        sleep_ms(1);
    }


}


