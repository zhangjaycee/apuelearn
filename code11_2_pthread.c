/**************************************************************
*******                                                 *******
***                                                         ***
**   Filename: code11_2_pthread.c     Time: 15-05-04-14:05   **
**   Email:    zhjcyx@gmail.com       By: Jaycee             **
***                                                         ***
*******                                                 *******
**************************************************************/
//打印主线程和新线程的id
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include"jc_err.h"

pthread_t ntid;

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n",s,(unsigned long)pid,(unsigned long)tid,(unsigned long)tid);
}
void * thr_fn(void *arg)
{
	printids("new thread: ");
	return ((void *)0);
}
int main(void)
{
	int err;
	err=pthread_create(&ntid,NULL,thr_fn,NULL);
	if(err!=0)
		err_sys("cant create thread");
	printids("main thread:");
	sleep(1);
	exit(0);
}
