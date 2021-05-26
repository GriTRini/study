#include <stdio.h>
#include "serial.h"

int main(void)
{
	for (int i = 1; i < 100; ++i) {
		int num;
		num = getSerialNumber();
		printf("HYUNDAI RAMDA %010d\n", num);
	
	}
	return 0;
}


