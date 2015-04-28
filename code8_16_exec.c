/**********************************
** filename:code8_16_exec.c 
** time: 20150428    byJaycee
** Email: zhjcyx@gmail.com
**********************************/

#include<stdio.h>
#include<unistd.h>
#include"jc_err.h"

char *env_init[]={"USER=unknown","PATH=/tmp",NULL};

int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
        err_sys("fork error\n");
    else if(pid==0){
        //first execle()
        if(execle("/home/jaycee/Desktop/apuelearn/code8_17_echoall","code8_17_echoall","myarg1","MY ARG2",(char *)0,env_init)<0)
            err_sys("execle error\n");
    }
    if(waitpid(pid,NULL,0)<0)
        err_sys("wait error\n");
    if((pid=fork())<0)
        err_sys("fork error\n");
    else if(pid==0){
        //second execlp
        if(execlp("/home/jaycee/Desktop/apuelearn/code8_17_echoall","code8_17_echoall","only 1 arg",(char *)0)<0)
            err_sys("execlp error\n");
    }        
    exit(0);
}
