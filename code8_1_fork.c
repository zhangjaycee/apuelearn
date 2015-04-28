/**********************************
** filename:code8_1_fork.c 
** time: 2015-4-27    byJaycee
** Email: zhjcyx@gmail.com
**********************************/
#include<stdio.h>
#include<unistd.h>
#include"jc_err.h"
#include<stdlib.h>

int globvar=6;//external varible
char buf[]="a write to stdout\n";

int main(void)
{
	int var;//automatic varible on the stack
	pid_t pid;
    var =88;
    globvar++;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1){
	    err_sys("write error!\n");             	
	}
    printf("before fork\n");
    if((pid=fork())<0){
        err_sys("fork error\n");
    }else if(pid==0){
        globvar++;
        var++;
    }else{
        sleep(2);
    }
    printf("pid=%ld,glob=%d,var=%d\n",(long)getpid(),globvar,var);
    exit(0);
}
