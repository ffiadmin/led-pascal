#ifndef LIB_H
#define LIB_H

// Architecture definitions
#define BCM708_PERI_BASE   0x20000000
#define GPIO_BASE          (BCM708_PERI_BASE + 0x200000)

#define BLOCK_SIZE         (4*1024)
#define PAGE_SIZE          (4*1024)

// Global variable definitions
volatile unsigned int *GPIO;

// Function definitions
void setup();

#endif