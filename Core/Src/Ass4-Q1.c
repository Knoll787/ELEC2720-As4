#include "Ass-4.h"
#if DO_QUESTION == 5

void Ass4_main(void)
{
    HAL_StatusTypeDef status;
    uint16_t ai[2];
    uint32_t i, j;
    printf("ADC Polling mode\n");
    while (1)
    {
        // printf("-> Start conversion...\n");
        if ((status = HAL_ADC_Start(&hadc1)) != HAL_OK)
        {
            printf("-> ERROR: HAL_ADC_Start() call failed (status = %d)\n",
                   status);
        }
        // Loop through both channels to get result
        for (j = 0; j < 2; j++)
        {
            // printf("-> Wait for conversion to finish...\n");
            if ((status = HAL_ADC_PollForConversion(&hadc1, 150)) != HAL_OK)
            {
                printf("-> ADC conversion failed (status = %d)\n", status);
            }
            // printf("-> Get the value...\n");
            ai[j] = (uint16_t)HAL_ADC_GetValue(&hadc1);
        }
        // Loop through both channels to print result
        for (j = 0; j < 2; j++)
        {
            // Print the result as decimal and bar graph
            printf("Got %4d: |", ai[j]);
            for (i = 0; i < 25; i++)
            {
                if (i <= ai[j] * 25 / 4096)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("| ");
        }
        printf("\n");
        // Loop delay
        HAL_Delay(500);
    }
}

#endif
