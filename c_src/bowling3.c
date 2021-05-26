#include <stdio.h>

int main(void)
{
   int frame[11][3] = {0,};
   int frame_score[11] = {0,};
   int bonus;
   int i;
   
   for(i = 1 ; i <= 10 ; ++i) {
      while(1) {
         printf("%d frame's first score : ", i);
         scanf("%d", &frame[i][1]);
         // 음수 또는 10보다 큰수가 입력되면 종료 된다.
         if (frame[i][1] < 0 || frame[i][1] > 10) {
            printf("Error!!\n");
         } else {
            break;
         }
      }
      
      // 직전 프레임에서 스페어 처리를 한 경우 --> 이전 프레임에 대한 스코어 
      if (i > 1 && frame[i-1][1] + frame[i-1][2] == 10 && frame[i-1][1] != 10) {
         frame_score[i-1] = frame_score[i-2] + 10 + frame[i][1];
         printf("%d frame score is %d\n", i-1, frame_score[i-1]);
      }
      // 직전 프레임, 전전 프레임에서 스트라이크가 나온 경우 --> 전전 프레임에 대한 스코어 
      if (i > 2 && frame[i-1][1] == 10 && frame[i-2][1] == 10) {
         frame_score[i-2] = frame_score[i-3] + 20 + frame[i][1];
         printf("%d frame score is %d\n", i-2, frame_score[i-2]);
      }
      
      // 두 번째 투구를 해야하는 경우 --> 첫번째 투구가 스트라이크가 아닌 경우 
      if (frame[i][1] != 10 || i = 10) {
         while(1) {
            printf("%d frame's second score : ", i);
            scanf("%d", &frame[i][2]);
            
            if (frame[i][2] < 0 || frame[i][2] > 10) {
               printf("Error!!\n");
            } else if (frame[i][1] + frame[i][2] > 10) {
               printf("Error!! sum of 1st cast and 2nd cast is smller than 10!\n");
            } else {
               break;
            }
         }
         
         // 전프레임이 스트라이크인 경우
         // 스페어 처리를 못한 경우 
         if (i > 1 && frame[i-1][1] == 10) {
            frame_score[i-1] = frame_score[i-2] + 10 + frame[i][1] + frame[i][2];
            printf("%d frame score is %d", i-1, frame_score[i-1]);
         }
         
         // 스페어 처리를 못한 경우 
         if (frame[i][1] + frame[i][2] < 10) {
            frame_score[i] = frame_score[i-1] + frame[i][1] + frame[i][2];
            printf("%d frame score is %d\n", i, frame_score[i]);
         }
      }
   } // i
   // 10프레임의 세번째 투구
   
   if (frame[i][1] + frame[i][2] >= 10) {
      while(1) {
         printf("%d frame's third cast : ", 10);
         scanf("%d", &bonus);
         
         if (bonus < 0 || bonus > 10) {
            printf("Error!!\n");
         } else {
            break; 
         }
      }
   frame_score[i] = frame_score[i-1] + frame[i][1] + frame[i][2] + bonus;
   printf("%d frame score is : %d\n", 10, frame_score[10]);
      // 10프레임의 첫번째 투구에서 스트라이크를 못쳤을 경우 
         // 2번째 투구를 한다.
         // 스페어를 했으면 세번째 투구
         // 아니면 종료 
   
   return 0;
   }
}
