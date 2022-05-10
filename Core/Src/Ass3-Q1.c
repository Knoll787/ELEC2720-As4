#include "Ass-3.h"
#if DO_QUESTION == 1

volatile uint32_t IntCount = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if(GPIO_Pin == JOY_C_Pin)
        IntCount++;
}


void Ass3_main(void) {
    GPIO_PinState JoyState;
    uint32_t IntCountCopy = 0;
    uint32_t IntCountPrev = 0;
    while(1) {
        JoyState = HAL_GPIO_ReadPin(JOY_C_GPIO_Port, JOY_C_Pin);
        HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, JoyState);


        HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
        HAL_Delay(TOGGLE_DELAY);


        IntCountCopy = IntCount;


        if(IntCountPrev != IntCountCopy) {
            IntCountPrev = IntCountCopy;
            printf("-> INFO: IntCount = %ld\n", IntCountPrev);
        }
    }
}

#endif