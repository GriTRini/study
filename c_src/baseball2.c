#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
   int question[3];
   int answer[3];
   
   int strike;
   int ball;
   
   int count = 0;
   
// Question

   srand(time(NULL));
   for (int i = 0; i < 3; ++i) {
      int num = rand() % 9 + 1;
      question[i] = num;
   }
   
   while (question[0] == question[1] || 
         question[1] == question[2] || 
         question[0] == question[2]) {
      if (question[0] == question[1])
         question[0] = rand() % 9 + 1;
      else if (question[1] == question[2])
         question[1] = rand() % 9 + 1;
      else
         question[2] = rand() % 9 + 1;
   }
   
  // printf("question : %d %d %d\n", question[0], question[1], question[2]);
   
   while (strike != 3) {
      strike = 0;
      ball = 0;
      
      scanf("%d %d %d", &answer[0], &answer[1], &answer[2]);
      
      for (int j = 0; j < 3; ++j) {
         for (int k = 0; k < 3; ++k) {
            if (question[j] == answer[k])
               ++ball;
         }
      }
      
      for (int j = 0; j < 3; ++j) {
         if (question[j] == answer[j])
            ++strike;
      }
      
      if (strike != 3)
         printf("#strike : %d\t#ball : %d\n\n", strike, ball - strike);
      
      ++count;
   }
   
   printf("Congraturation! count : %d\n", count);
   return 0;
}
