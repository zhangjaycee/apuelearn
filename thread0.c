/**********************************
** filename:thread0.c 
** time: 2015 04 02    byJaycee
** Email: zhjcyx@gmail.com
**********************************/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include"jc_err.h"

pthread_t ntid;

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;

	pid=getpid();
	tid=pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n",s,(unsigned long)pid,(unsigned long)tid,(unsigned long)tid);
}
void *thr_fn(void *arg)
{
	printids("new thread: ");
	return ((void *)0);
}

int main(void)
{
	int err;

	err = pthread_create(&ntid,NULL,thr_fn,NULL);
	if(err != 0){
		err_sys("cant create thread!\n");
	}
	printids("main thread:");
	sleep(1);
	exit(0);
}
