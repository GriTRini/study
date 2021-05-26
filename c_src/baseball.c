#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
	int question[3];
	int answer[3];
	
	int strike, ball, count;
	
	srand(time(NULL));
/*	for (int i = 0; i < 1; ++i){
		int num = rand() % 10;
			question[0] = num;
			
			for(int i = 1; i < 2; ++i){
				int num = rand() % 10;
					question[1] = num;
						
						for(int i = 2; i < 3; ++i){
							int num = rand() % 10;
								question[2] = num;
		
									
									
			     		}
			}
		
	}
	
    	printf("%d %d %d\n", question[0], question[1], question[2]);
    	*/
    question[0] = rand() % 9 + 1;
	
	do{
	question[1] = rand() % 9 + 1;
	}
	while (question[0] == question[1]){
		question[1] = rand() % 9 + 1;
	}
	
	do{
	question[2] = rand() % 9 + 1;
	}
	while (question[0] == question[2] || question[1] == question[2]){
		question[2] = rand() % 9 + 1;
		
	printf("question: %d %d %d\n", question[0], question[1], question[2]);
	
	while(strike != 3){
		strike = 0;
		ball = 0;
		count = 0;
		printf("input num :");
		scanf("%d %d %d", &answer[0], &answer[1], &answer[2]);
		
	   
		
		for(int i = 0; i <= 2; ++i){
			for(int j = 0; j <= 2; ++j){
				if(question[i] == answer[j]){
					if(i == j){
						++strike;
					} else{
						++ball;
					}
					
					++count;
				}
			}
		}
		
		printf("strike: %d, ball : %d\n", strike, ball - strike);
				
				 
	}

	

	
	}
	return 0;
}
