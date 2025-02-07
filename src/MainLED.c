#include <General_U4C4.h>
#include <MainLED_U4C4.h>


void TogglePinNoTime(uint8_t pin){
    int pinLevel = gpio_get(pin);
    printf("PIN: %d\n", pin);
    printf("R pinLEVEL before: %d\n", gpio_get(13));
    printf("G pinLEVEL before: %d\n", gpio_get(11));
    printf("B pinLEVEL before: %d\n", gpio_get(12));
    gpio_put(pin, !pinLevel);
    pinLevel = gpio_get(pin);
    printf("R pinLEVEL after: %d\n", gpio_get(13));
    printf("G pinLEVEL after: %d\n", gpio_get(11));
    printf("B pinLEVEL after: %d\n", gpio_get(12));
}