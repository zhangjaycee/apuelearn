/**********************************
** filename: code8_17_echoall.c
** time: 20150428    byJaycee
** Email: zhjcyx@gmail.com
**********************************/

#include<stdio.h>
#include<unistd.h>
#include"jc_err.h"

int main(int argc,char * argv[])
{
    int i;
    char **ptr;
    extern char **environ;

    for(i=0;i<argc;i++){
        printf("argv[%d]:%s\n",i,argv[i]);
    }
    for(ptr = environ;*ptr!=0;ptr++){
        printf("%s\n",*ptr);
    }
    exit(0);
}
