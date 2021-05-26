#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int lottonums[6];
	
	srand(time(NULL));
	/*lottonums[0] = rand() % 45 + 1;
	
	do	lottonums[1] = rand() % 45 + 1;
	while (lottonums[0] == lottonums[1]);
		
	do 	lottonums[2] = rand() % 45 + 1;
	while (lottonums[0] == lottonums[2] || lottonums[1] == lottonums[2]);
	
	do lottonums[3] = rand() % 45 + 1;
	while (lottonums[0] == lottonums[3] || lottonums[1] == lottonums[3] || lottonums[2] == lottonums[3]);
		
	do lottonums[4] = rand() % 45 + 1;
	while (lottonums[0] == lottonums[4] || lottonums[1] == lottonums[4] || lottonums[2] == lottonums[4] || lottonums[3] == lottonums[4]);
		
	do	lottonums[5] = rand() % 45 + 1;
	while (lottonums[0] == lottonums[5] || lottonums[1] == lottonums[5] || lottonums[2] == lottonums[5] || lottonums[3] == lottonums[5] || 				lottonums[4] == lottonums[5]);
		*/
		for (int i = 0; i < 6; ++i) {
			for(int j = 0; j < 6; ++j) {
				int num = rand() % 45 + 1;
			     lottonums[i] = num; 
			      lottonums[j] = num;
			      
				while(lottonums[i] == lottonums[j]) {
					if (i==j)
						break;
				    for (int i = 0; i < 6; ++i) {
						for(int j = 0; j < 6; ++j) {
							int num = rand() % 45 + 1;
			    			lottonums[i] = num; 
			      		//	lottonums[j] = num;
			      		}
			      	}
			      }
			}
		}
					
				
			
				
      
											
								
		printf("%d\t %d\t %d\t %d\t %d\t %d\n", lottonums[0], lottonums[1], lottonums[2], lottonums[3], lottonums[4], lottonums[5]);
		
	return 0;
}
			
			
			
