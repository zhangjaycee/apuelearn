/**********************************
** filenamei:code8_8_forktwice.c
** time: 20150428    byJaycee
** Email: zhjcyx@gmail.com
**********************************/
//为了防止僵尸进程，采取的小技巧
//基本思路是通过两次调用fork()函数并且随后马上终止第一次生成的子进程，让第二次生成的子进程马上被pid为1的init进程收养
#include<stdio.h>
#include"jc_err.h"
#include<unistd.h>
#include<sys/wait.h>
int main(void)
{
    pid_t pid;
    printf("父进程pid为%ld\n",(long)getpid());
    if((pid=fork())<0){
        err_sys("fork 1st error\n");
    }else if(pid==0){//第一个子进程执行
        printf("first child pid=%ld ppid=%ld\n",(long)getpid(),(long)getppid());
        if((pid=fork())<0){//创建第二个子进程
            err_sys("fork 2nd time error\n");
        }else if(pid>0){
            printf("exit the 1st child\n");
            exit(0);//第一子进程结束
        }
        printf("second child parent pid=%ld\n",(long)getppid());
        printf("我是第二子进程，现在等两秒，待父进程结束，我的父进程应该变为init（ppid为1）\n");
        sleep(2);
        printf("second child parent pid=%ld\n",(long)getppid());
        exit(0);//第二子进程结束
    }
    if(waitpid(pid,NULL,0)!=pid){
        err_sys("waitpid error\n");
    }
    printf("父进程结束\n");
    exit(0);//父进程结束
}
