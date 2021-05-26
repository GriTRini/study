#include <stdio.h>

int main(void)
{
	int score;
	printf("input your score : ");
	scanf("%d", &score);
/*	
	if (score >= 60){
		printf("%d/60 = Pass\n" , score);
	} else {
		printf("%d/60 = Fail\n" , score);
	}
	*/
	
	printf("score: %d ---> %s\n", score, (score >= 60) ? "pass" : "fail");
	return 0;
}
