/**********************************
** filename: chdir.c 
** time: 2015 02 06   byJaycee
** Email: zhjcyx@gmail.com
**********************************/
//������Ĺ���Ŀ¼������һ��ָ����Ŀ¼(chdir)��Ȼ���ӡ��Ŀ¼(getcwd)
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
