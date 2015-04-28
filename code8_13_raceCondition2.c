/**********************************
** filename:code8_13_raceCondition2.c 
** time: 20150428    byJaycee
** Email: zhjcyx@gmail.com
**********************************/
//对上一段代码的改进，用于解决竞争条件的问题，大写的函数指示思路，没有实现，不能编译

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

/**/TELL_WAIT();

    if((pid=fork())<0){
        err_sys("fork error\n");
    }else if(pid==0){
/**/    WAIT_PARENT();//let parent go first
        charatatime("output from child\n");
    }else{
        charatatime("output from parent\n");
/**/    TELL_CHILD();
    }
    exit(0);
}

