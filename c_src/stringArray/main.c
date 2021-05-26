#include "stringArray.h"

int main(void)
{
	char cities[][20] = {
		"Seoul", "Los Angeles", "Paris", "Rio de Janeiro", "Daejun"
	};
	
	char *cities2[] = {
		"Seoul", "Los Angeles", "Paris", "Rio de Janeiro", "Daejun"
	};
	
	printStringArray(cities, 5);
	printStringArray2(cities2, 5);
	
	return 0;
}
