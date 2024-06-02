#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"

#include "task.h"
static bool led_state = 0;

void Task1(void* param)
{
    while(1)
    {
    led_state=!led_state;
    gpio_put(PICO_DEFAULT_LED_PIN,led_state);
    vTaskDelay(1000);
    }
}

void Task2(void* param)
{
    while(1)
    {
    printf("Hello from Task 2\n");
    vTaskDelay(1000);
    }
}


int main(void)
{
    stdio_init_all();

    /*Setting LED_PIN*/
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_put(PICO_DEFAULT_LED_PIN,led_state);
    gpio_set_dir(PICO_DEFAULT_LED_PIN,GPIO_OUT);
    /********************************************/

    xTaskCreate(Task1,"Led_task",128,NULL,tskIDLE_PRIORITY,NULL);
    xTaskCreate(Task2,"Uart_Task",256,NULL,1,NULL);
    vTaskStartScheduler();

    while(1);

}