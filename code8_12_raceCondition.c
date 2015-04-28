/**********************************
** filename:code8_12_raceCondition.c 
** time: 20150428    byJaycee
** Email: zhjcyx@gmail.com
**********************************/
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

