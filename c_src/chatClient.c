#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <assert.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <string.h>

char nickname[20];

void *sendMsg(void *arg)
{
	int dataSocket = *(int *)arg;
	for (;;) {
		char buf[1024];
		strcpy(buf, nickname);
		fgets(buf + strlen(nickname), 1024, stdin);

		if (strcmp(buf, "q\n") == 0 || strcmp(buf, "Q\n") == 0) {
			break;
		}
		write(dataSocket, buf, strlen(buf));
	}
	close(dataSocket);
}

void *recvMsg(void *arg) 
{
	int dataSocket = *(int *)arg;
	
	char buf[1024];
	int nread;
	while((nread = read(dataSocket, buf, 1024)) != 0) {
		buf[nread] = '\0';
		printf("%s", buf);
	}
}
int main(int argc, char **argv) 
{	
	strcpy(nickname, argv[3]);
	strcat(nickname, " : ");

   int dataSocket;
   dataSocket =    socket(PF_INET, SOCK_STREAM, 0);
   assert(dataSocket != -1);
   
   struct sockaddr_in servAddr;
   servAddr.sin_family = AF_INET;
   servAddr.sin_addr.s_addr = inet_addr(argv[1]);
   servAddr.sin_port = htons(atoi(argv[2]));
   
   assert( connect(dataSocket, (struct sockaddr *)&servAddr, sizeof(servAddr)) != -1);

   pthread_t thread1, thread2;
   pthread_create(&thread1, NULL, sendMsg, &dataSocket);
   pthread_create(&thread2, NULL, recvMsg, &dataSocket);

   void *ret;
   pthread_join(thread1, &ret);
   pthread_join(thread2, &ret);
   
   //read()/write()
   
   //close(dataSocket);
   
   return 0;
}