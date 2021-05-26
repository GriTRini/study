#include <stdio.h>

int main(void)
{
	int score;
	printf("input score :");
	scanf("%d", &score);
	
	if ( score >= 90 ) {
		printf("score is A\n");
	} else if ( score >= 80) {
		printf("score is B\n");
	} else if ( score >= 70) {
	 	printf("score is C\n");
	} else if ( score >= 60) {
		printf("score is D\n");
	} else if ( score >= 50) {
		printf("score is F\n");
	}
	return 0;
}
