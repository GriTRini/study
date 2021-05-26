#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <assert.h>
#include <pthread.h>
#include <arpa/inet.h>

pthread_mutex_t mutex;

int clntSockets[20];
int count;

void* thread_proc(void* arg) {

   int clntSocket = *(int*)arg;
   
   char buf[1024];
   int nread;
   while ( (nread = read(clntSocket, buf, 1024)) /* != 0 */) {   // 상대방의 소켓에서 종료시 
pthread_mutex_lock(&mutex);
      for (int i = 0 ; i < count ; ++i)                        // endof 파일이 넘어온다. 그때 빠져나간다.
         write(clntSockets[i], buf, nread);
pthread_mutex_unlock(&mutex);
   }
pthread_mutex_lock(&mutex);
   int i;
   for (i = 0 ; i < count ; ++i)
      if (clntSocket == clntSockets[i])
         break;
   
   for (int j = i ; j < count ; ++j)
      clntSockets[j] = clntSockets[j+1];
   
   --count;
pthread_mutex_unlock(&mutex);   
   close(clntSocket);
}

// int main(int argc, char *argv[])
int main(int argc, char **argv) {
   pthread_mutex_init(&mutex, NULL);

   int servSocket;      // 파일 기술자
   servSocket = socket(AF_INET, SOCK_STREAM, 0);
   assert(servSocket != -1);
/*
   char buf[1024];
   read(0, buf, 1024);                        //   0 : 표준 입력 
   
   write(1, "hello\n", 6);                     //   1 : 표준 출력 
   write(2, "cann't open file\n", 문자길이);      //   2 : 표준 에러
*/   
   struct sockaddr_in addr;
   addr.sin_family = AF_INET;
   addr.sin_addr.s_addr = htonl(INADDR_ANY);
   addr.sin_port = htons(atoi(argv[1]));
   
   assert( bind(servSocket, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) != -1 );
   
   assert( listen(servSocket, 5) != -1 );
   
   for(;;) {
      int addrSize = sizeof(struct sockaddr_in);
      struct sockaddr_in clntAddr;
      int clntSocket = accept(servSocket, (struct sockaddr *)&clntAddr, &addrSize);
      
      printf("connected by ip : %s\n", inet_ntoa(clntAddr.sin_addr));
      
pthread_mutex_lock(&mutex);
      clntSockets[count++] = clntSocket;
pthread_mutex_unlock(&mutex);

      pthread_t thread;
      pthread_create(&thread, NULL, thread_proc, &clntSocket);
      // create thread ... pass dataSocket to thread func.
      pthread_detach(thread);
   }
   
   close(servSocket);
   pthread_mutex_destroy(&mutex);
   return 0;
}