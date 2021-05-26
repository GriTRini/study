#include "date.h"
#include <stdio.h>
/*
void printDate(struct date d)
{
	printf("(%d %d %d)\n", d.year, d.month, d.day);
}
*/

void printDate(const struct date *pd)
{
	printf("(%d %d %d)\n", (*pd).year, (*pd).month, (*pd).day);
}
