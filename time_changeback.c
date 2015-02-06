/********************************
filename: time_changeback.c
20150203   byJaycee
Email: zhjcyx@gmail.com
*********************************/

//目的是将文件长度截断为0，并将访问时间和修改时间改回阶段前，使其保持不变
//apue p127
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include"jc_err.h"

int main(int argc, char *argv[])
{
	int i,fd;
	struct stat statbuf;
	time_t times[2];
	if(argc<2){
		err_ret("Usage: %s filename",argv[0]);
		exit(1);
	}
	for(i=1;i<argc;i++){
		if(stat(argv[i],&statbuf)<0){
			err_ret("%s: stat error",argv[i]);
			continue;
		}
		if((fd=open(argv[i],O_RDWR|O_TRUNC))<0){
			err_ret("%s: open error",argv[i]);
			continue;
		}
		times[0]=statbuf.st_atime;
		times[1]=statbuf.st_atime;
//原型int futimens(int fd,const struct timespec times[2])
		if(futimens(fd,times)<0){
			err_ret("%s: futimens error",argv[i]);
		close(fd);
		}
	}
	exit(0);
}

