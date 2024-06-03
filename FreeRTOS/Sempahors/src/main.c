#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include <stdio.h>
#include "pico/stdlib.h"

#include "task.h"
static bool led_state1 = 0;
static bool led_state2 = 0;

const uint8_t PIN1 = 22;
const uint8_t PIN2 = 21;
SemaphoreHandle_t xSemaphore = NULL;
void Task1(void* param)
{
    while(1)
    {
        //Taking sempahore 
        if(xSemaphoreTake(xSemaphore,1000/portTICK_RATE_MS)==pdTRUE)
        {
            gpio_put(PIN1,1);
            for(int i=0;i<10000;i++);
            gpio_put(PIN1,0);

        }
        else{
            ;
        }

    }
}

void Task2(void* param)
{
    while(1)
    {
 
        for(int i=0;i<8;i++)
        {
            led_state2 = !led_state2;
            gpio_put(PIN2,led_state2);
        }
        SemaphoreGive(xSemaphore); //Realesing so Task1 Can continiu if not Task1 Suspended; 
        
    }
}

void Error_Handler(void)
{
    while(1);
}




int main(void)
{
    stdio_init_all();

    if((xSemaphore = xSemaphoreCreateBinary())==NULL)
        Error_Handler();

    /*Setting GPIO_PIN*/
    gpio_init(PIN1);
    gpio_put(PIN1,led_state1);
    gpio_set_dir(PIN1,GPIO_OUT);
    gpio_init(PIN2);
    gpio_put(PIN2,led_state2);
    gpio_set_dir(PIN2,GPIO_OUT);
    /********************************************/
    xSemaphoreGive(xSemaphore);
    xTaskCreate(Task1,"Led_task",128,NULL,2,NULL);
    xTaskCreate(Task2,"Uart_Task",128,NULL,1,NULL);
    vTaskStartScheduler();

    while(1);

}