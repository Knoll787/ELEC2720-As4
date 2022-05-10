#include "Ass-4.h"
#if DO_QUESTION == 7

// Analogue Inputs
volatile uint16_t pots[2]; // pots[1] = Right Pot
                           // pots[0] = Left Pot


void Ass4_main(void) {
    HAL_StatusTypeDef status;

    while (1) {
        if ((status = HAL_ADC_Start_DMA(&hadc1, &pots, 2)) != HAL_OK) {
            printf("-> ERROR: HAL_ADC_Start() call failed (status = %d)\n", status);
        }
        HAL_Delay(500);
    }
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){
    if (hadc != &hadc1) {
        printf("HAL_ADC_ConvCpltCallback input !=  &hadc1")
        return;
    }

    printf("Left Pot: %d\t", pots[1]);
    printf("Right Pot: %d\t \n\0", pots[0]);
}

#endif