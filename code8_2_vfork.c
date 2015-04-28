/**********************************
** filename:code8_2_vfork.c 
** time: 2015-4-27    byJaycee
** Email: zhjcyx@gmail.com
**********************************/
//可移植平台应尽量避免使用。
//和fork()区别：
//1 子进程在父进程空间运行（共享数据）
//2 子进程调用exec或者exit时父进程才继续运行。
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
    printf("before vfork\n");
    if((pid=vfork())<0){
        err_sys("vfork error\n");
    }else if(pid==0){
        globvar++;
        var++;
    }
    printf("pid=%ld,glob=%d,var=%d\n",(long)getpid(),globvar,var);
    exit(0);
}
