#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#include "lib.h"
#include "macros.h"

void setup() {
	void *gpioMap = NULL;
	int memoryHandle = 0;

//Open a device to map to a physical address
	if((memoryHandle = open("/dev/mem", O_RDWR | O_SYNC)) < 0) {
		perror("/dev/mem cannot be opened: %s", strerror(errno));
		exit(ERROR_OPENING_DEV_MEM);
	}

//Map to the GPIO device
	gpioMap = mmap(
		NULL,					// Any address in our space will do
		BLOCK_SIZE,				// Map length
		PROT_READ | PROT_WRITE,	// Enable reading and writing to the mapped memory
		MAP_SHARED,				// This memory is available to other processes
		memoryHandle,			// Device to map
		GPIO_BASE				// Memory offset to GPIO device
	);

	close(memoryHandle);

//Check for error conditions
	if(gpioMap == MAP_FAILED) {
		perror("mmap error: %d, %s", (int)gpioMap, strerror(errno));
		exit(ERROR_MAPPING_GPIO_MEM);
	}

//Set the GPIO handle
	GPIO = (volatile unsigned int*) gpioMap;
}