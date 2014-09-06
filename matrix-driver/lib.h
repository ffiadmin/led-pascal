#ifndef LIB_H
#define LIB_H

// Global variable definitions
volatile unsigned int *GPIO;

// Architecture definitions
#define BCM2708_PERI_BASE 0x20000000
#define GPIO_BASE         (BCM2708_PERI_BASE + 0x200000)

#define BLOCK_SIZE        (4 * 1024)
#define PAGE_SIZE         (4 * 1024)

//Error definitions
#define ERROR_OPENING_DEV_MEM  1
#define ERROR_MAPPING_GPIO_MEM 2

// GPIO setup
#define GET_GPIO(g)        (*(GPIO + 13) & (1 << g))

#define GPIO_CLR           *(GPIO + 10)
#define GPIO_SET           *(GPIO + 7)

#define INP_GPIO(g)        *(GPIO + ((g) / 10)) &= ~(7 << (((g) % 10) * 3))
#define OUT_GPIO(g)        *(GPIO + ((g) / 10)) |= (1 << (((g) % 10) * 3))
#define SET_GPIO_ALT(g, a) *(GPIO + (((g) / 10))) |= (((a) <= 3 ? (a) + 4 : (a) == 4 ? 3 : 2) << (((g) % 10) * 3))

// Function definitions
void setup();

#endif