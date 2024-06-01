#include "pico/stdlib.h"

#define PICO_LED 25
int main(void)
{

    gpio_init(PICO_LED);
    gpio_set_dir(PICO_LED,GPIO_OUT);
    while(1)
    {
        gpio_put(PICO_LED,1);
        sleep_ms(250);
        gpio_put(PICO_LED,0);
        sleep_ms(250);
    }

}