#include <stdio.h>
#include "stringArray.h"

void printStringArray(const char (*stringArray)[20], int size) 
{
	for (int i = 0; i < size; ++i) {
		printf("%s\n", stringArray[i]);
	}
	
}

void printStringArray2(char **stringArray, int size) 
{
	for (int i = 0; i < size; ++i) {
		printf("%s\n", stringArray[i]);
	}
	
}
