/**********************************
** filename:code8_12_raceCondition.c 
** time: 20150428    byJaycee
** Email: zhjcyx@gmail.com
**********************************/
//出现竞争条件 因为fork()后子进程、父进程都调用了函数charatatime,可能出现文本的混合
#include<stdio.h>
#include"jc_err.h"
#include<unistd.h>

static void charatatime(char *str)
{
    char*ptr;
    int c;

    setbuf(stdout,NULL);//set unbuffered
    for(ptr=str;(c=*ptr++)!=0;  ){
        putc(c,stdout);
    }
}
int main(void)
{
    pid_t pid;

    if((pid=fork())<0){
        err_sys("fork error\n");
    }else if(pid==0){
        charatatime("output from child\n");
    }else{
        charatatime("output from parent\n");
    }
    exit(0);
}

