/**********************************
** filename: chdir.c 
** time: 2015 02 06   byJaycee
** Email: zhjcyx@gmail.com
**********************************/
//将程序的工作目录更改至一个指定的目录(chdir)，然后打印该目录(getcwd)
//apue p136

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"jc_err.h"

int main()
{
	char *ptr;
	size_t size=50;
	if(chdir("/Users/jaycee/Desktop/")<0){
		err_sys("chdir failed");
	}
	ptr=(char *)malloc(size*sizeof(char));
	if(getcwd(ptr ,size)==NULL){
		err_sys("getcwd failed");
	}
	printf("cwd=%s\n",ptr);
	exit(0);
}
