#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lib.h"

typedef int bool;
#define true 1
#define false 0

#define NICE_VAL -20

int main(int argc, char **argv) {
	nice(NICE_VAL);
	setup();
	
	INP_GPIO(11);
	OUT_GPIO(11);
	
	while(true) {
		GPIO_SET = 1 << 11;
		GPIO_CLR = 1 << 11;
	}

	return 0;
}