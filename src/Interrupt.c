#include <Interrupt_U4C4.h>

InterruptContext interruptContext = {NULL, {0}, 0, {0}, 0, 0};
volatile uint32_t intervalButtonA = 0;
volatile uint32_t intervalButtonB = 0;

void SetRGBInterrupt(InterruptNewCallback callback, int inputPin, int pins[3]) {
    printf("RGB INTERRUPT\n");
    interruptContext.Callback = callback;
    interruptContext.inputPin = inputPin;
    interruptContext.RGBPin[2] = pins[2];
    //interruptContext.RGBPin[1] = pins[1];
    interruptContext.RGBPin[0] = pins[0];
    gpio_set_irq_enabled_with_callback(inputPin, GPIO_IRQ_EDGE_RISE, true, &HandleInterruptRGB);
}

void HandleInterruptRGB(uint gpio, uint32_t events) {
    uint32_t interval = gpio == 5 ? intervalButtonA : intervalButtonB; 
    uint32_t currentTime = to_us_since_boot(get_absolute_time());
    uint8_t pin = 0;
    if(currentTime - interval > 250000){
        if (interruptContext.Callback != NULL) {
            if (gpio == interruptContext.pinToCompare[0]){
                intervalButtonA = currentTime;
                pin = interruptContext.RGBPin[2];
                printf("PIN: %d\n",pin);
                interruptContext.Callback(12);
            } else {
                intervalButtonB = currentTime;
                pin = interruptContext.RGBPin[0];
                printf("PIN: %d\n",pin);
                interruptContext.Callback(13);
            }
                  
        }
    }
}