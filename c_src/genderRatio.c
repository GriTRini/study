#include <stdio.h>

int main(void){

	int man, girl;
	
	printf("man number: ");
	scanf("%d" , &man);
	
	printf("girl munber: ");
	scanf("%d" , &girl);
	
	double mratio, gratio;
	
	mratio = (double)man / (man + girl) * 100 ;
	gratio = (double)girl / (man +girl) * 100 ;
	
	printf("man ratio = %.2f%% girl ratio = %.2f%%\n", mratio, gratio);
	return 0;
}
