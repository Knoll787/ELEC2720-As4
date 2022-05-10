#ifndef SRC_ASS_3_H_
#define SRC_ASS_3_H_

#include "main.h"
#include <stdio.h>

#define DO_QUESTION 4
#define TOGGLE_DELAY 100 // Period before toggling heartbeat LED (ms)

extern DMA_HandleTypeDef hdma_memtomem_dma2_stream0;

void Ass3_main(void);

#endif /* SRC_ASS_3_H_ */
