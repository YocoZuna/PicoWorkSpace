
#include "gpio_init.h"

void init_gpio(int dir,int pin)
{
    gpio_init(pin);
    gpio_set_dir(pin,dir);
}