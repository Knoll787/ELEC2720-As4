#include "Ass-3.h"

#if DO_QUESTION == 2

char src[] = "*Hello*";
volatile char dst[8] = {'0','0','0','0','0','0','0','\0'}; // Ensure

void Ass3_main(void)
{
    // Initial value
    printf("BEFORE: dst = ’%s’\n", dst);
    // Transfer printf("Initiate DMA Transfer...\n");
    HAL_DMA_Start(&hdma_memtomem_dma2_stream0, (uint32_t)src,
                  (uint32_t)dst, 2);
    printf("DMA Transfer initiated.\n");
    // Poll for DMA completion
    printf("Poll for DMA completion.\n");
    HAL_DMA_PollForTransfer(&hdma_memtomem_dma2_stream0,
                            HAL_DMA_FULL_TRANSFER, HAL_MAX_DELAY);
    printf("DMA complete.\n");
    // Print result
    printf("AFTER: dst = ’%s’\n", dst);
}
#endif
