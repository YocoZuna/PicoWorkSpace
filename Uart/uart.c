#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>
#include <iso646.h>
#include "gpio_init.h"

#define PICO_LED 25
int STATE =1;


char cmd[20];
int main(void)
{
    stdio_init_all();
    
    init_gpio(GPIO_OUT,PICO_LED);

    while(1)
    {


            gpio_put(PICO_LED,1);

            sleep_ms(1000);
            gpio_put(PICO_LED,0);
        

    }


}
