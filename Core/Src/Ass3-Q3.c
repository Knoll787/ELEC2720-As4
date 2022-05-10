#include "Ass-3.h"
#if DO_QUESTION == 3
static char src[] = "*There*";
static volatile char dst[8] = {'1','1','1','1','1','1','1','\0'}; // Ensure NULL terminated

// Variable to indicate transfer complete
static volatile uint32_t TransferComplete = 0;
// DMA call back function (interrupt service routine)
static void DMACallback(DMA_HandleTypeDef *hdma)
{
    // Check it is the correct DMA Channel
    if (hdma == &hdma_memtomem_dma2_stream0)
    {
        TransferComplete = 1;
    }
}
void Ass3_main(void)
{
    uint32_t TransferCompleteCopy = 0;
    // Register the callback function
    HAL_DMA_RegisterCallback(&hdma_memtomem_dma2_stream0,
                             HAL_DMA_XFER_CPLT_CB_ID, &DMACallback);
    // Initial value
    printf("BEFORE: dst = '%s'\n", dst);
    // Transfer
    printf("Initiate DMA Transfer...\n");
    HAL_DMA_Start_IT(&hdma_memtomem_dma2_stream0, (uint32_t)src,
                     (uint32_t)dst, 2);
    printf("DMA Transfer initiated.\n");
    // Wait to hear from callback function
    printf("Wait to hear from DMA callback.\n");
    while (TransferCompleteCopy == 0)
    {
        TransferCompleteCopy = TransferComplete;
    }
    printf("DMA Complete\n");
    // Print result
    printf("AFTER: dst = '%s'\n", dst);
    // Unregister the callback function
    HAL_DMA_UnRegisterCallback(&hdma_memtomem_dma2_stream0, HAL_DMA_XFER_CPLT_CB_ID);
}
#endif
