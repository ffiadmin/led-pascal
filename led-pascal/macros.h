#ifndef MACROS_H
#define MACROS_H

//Error definitions
#define ERROR_OPENING_DEV_MEM  1
#define ERROR_MAPPING_GPIO_MEM 2

// GPIO setup
volatile unsigned int *gpio;

#define GET_GPIO(g)        (*(gpio + 13) & (1 << g))

#define GPIO_CLR           *(gpio + 10)
#define GPIO_SET           *(gpio + 7)

#define INP_GPIO(g)        *(gpio + ((g) / 10)) &= ~(7 << (((g) % 10) * 3))
#define OUT_GPIO(g)        *(gpio + ((g) / 10)) |= (1 << (((g) % 10) * 3))
#define SET_GPIO_ALT(g, a) *(gpio + (((g) / 10))) |= (((a) <= 3 ? (a) + 4 : (a) == 4 ? 3 : 2) << (((g) % 10) * 3))

#endif