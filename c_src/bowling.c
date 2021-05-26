#include <stdio.h>

int main(void)
{
	int frame[10][3] = {0, };
	int frame_10[4] = {0, };
	int frame_score[11] = {0, };
	int totalScore = 0;
	int strikeNum = 0;
	int spare = 0;
	
	int i = 0;
	
	for(i = 1; i <= 9; ++i) {
		printf("%d's first score : ", i);
		scanf("%d", &frame[i][1]);
		
		if(frame[i][1] < 10) {	//	not strike
			printf("%d's second score : ", i);
			scanf("%d", &frame[i][2]);
			
			if(frame[i][1] + frame[i][2] == 10) {
				spare = 1;
			}
			else{
				if(strikeNum == 0 && spare == 0) {
					totalScore = totalScore + frame[i][1] + frame[i][2];
					printf("%d's score : %d\n", i, totalScore);
				}
				
				else if(strikeNum == 1) {
					totalScore = totalScore + 10 + frame[i][1] + frame[i][2];
					printf("%d's score : %d\n", i-1, totalScore );
					totalScore = totalScore + frame[i][1] + frame[i][2];
					printf("%d's score : %d\n", i, totalScore );
				}
				
				else if(strikeNum == 2) {
					totalScore = totalScore + 20 + frame[i][1];
					printf("%d's score : %d\n", i-2, totalScore);
					totalScore = totalScore + 10 + frame[i][1] + frame[i][2];
					printf("%d's score : %d\n", i-1, totalScore);
					totalScore = totalScore + frame[i][1] + frame[i][2];
					printf("%d's score : %d\n", i, totalScore);
				}
				else if(spare == 1) {
					totalScore = totalScore + 10 + frame[i][1];
					printf("%d's score : %d\n", i-1, totalScore);
					totalScore = totalScore + frame[i][1] + frame[i][2];
					printf("%d's score : %d\n", i, totalScore);
				}	
					
			}
			strikeNum = 0;
		
		}	else { //strike
			++strikeNum;
		}
	}

	return 0;
}
