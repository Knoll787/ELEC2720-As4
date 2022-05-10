#include "Ass-4.h"
#if DO_QUESTION == 6

volatile static uint16_t ai;
volatile static uint8_t got_ai = 0;

void Ass4_main(void)
{
    HAL_StatusTypeDef status;
    uint32_t i;
    printf("ADC Interrupt mode\n");
    while (1)
    {
        got_ai = 0;
        if ((status = HAL_ADC_Start_IT(&hadc1)) != HAL_OK)
        {
            printf("-> ERROR: HAL_ADC_Start_IT() call failed (status = %d)\n",
                   status);
        }
        while (got_ai == 0)
        {
        }
        // Print the result as decimal and bar graph
        printf("Got %4d: |", ai);
        for (i = 0; i < 60; i++)
        {
            if (i <= ai * 60 / 4096)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("|\n");
        // Loop delay
        HAL_Delay(500);
    }
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if (hadc == &hadc1)
    {
        ai = (uint16_t)HAL_ADC_GetValue(&hadc1);
        got_ai = 1;
    }
}

#endif