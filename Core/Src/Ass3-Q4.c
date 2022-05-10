#include "Ass-3.h"
#if DO_QUESTION == 4

static volatile uint16_t TransferComplete = 0;
// DMA call back function (interrupt service routine)
static void DMACallback(DMA_HandleTypeDef *hdma)
{
    // Check it is the correct DMA Channel
    if (hdma == &hdma_memtomem_dma2_stream0)
    {
        TransferComplete = 1;
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    
    //uint16_t data = GPIOD->ODR;
    uint16_t data = 0x0000;

    HAL_DMA_RegisterCallback(&hdma_memtomem_dma2_stream0,
                             HAL_DMA_XFER_CPLT_CB_ID, &DMACallback);

    if(GPIO_Pin == JOY_A_Pin) {
        data |= (1 << 12); // Green LED => Set
        data &= ~(1 << 14); // Red LED => Clear 
        data &= ~(1 << 15); // Blue LED => Clear 
        printf("JOY_A: %x\n\0", data);
    }
    else if(GPIO_Pin == JOY_D_Pin) {
        data &= ~(1 << 12); // Green LED => Clear 
        data |= (1 << 14); // Red LED => Set 
        data &= ~(1 << 15); // Blue LED => Clear 
        printf("JOY_D: %x\n\0", data);
    }
    else if(GPIO_Pin == JOY_C_Pin) {
        data &= ~(1 << 12); // Green LED => Clear 
        data &= ~(1 << 14); // Red LED => Clear 
        data |= (1 << 15); // Blue LED => Set 
        printf("JOY_C: %x\n\0", data);
    }
    else if(GPIO_Pin == JOY_CTR_Pin) {
        data &= ~(1 << 12); // Green LED => Clear 
        data &= ~(1 << 14); // Red LED => Clear 
        data &= ~(1 << 15); // Blue LED => Clear 
        printf("JOY_CTR: %x\n\0", data);
    }

    // Begin DMA
     HAL_DMA_RegisterCallback(&hdma_memtomem_dma2_stream0,
                             HAL_DMA_XFER_CPLT_CB_ID, &DMACallback);

    // Send DMA
    HAL_DMA_Start_IT(&hdma_memtomem_dma2_stream0, 
                        &data, &(GPIOD->ODR), 2);

    // End DMA
    HAL_DMA_UnRegisterCallback(&hdma_memtomem_dma2_stream0, HAL_DMA_XFER_CPLT_CB_ID);
}


void Ass3_main(void) {
    printf("GPIOD Size: %d\n\0", sizeof(GPIOD->ODR));
    printf("Data Size: %d\n\0", sizeof(uint32_t));
    while(1) {
        HAL_Delay(10);
    }
}

#endif
