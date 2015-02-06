/********************************
filename: time_changeback.c
20150203   byJaycee
Email: zhjcyx@gmail.com
*********************************/

//目的是将文件长度截断为0，并将访问时间和修改时间改回阶段前，使其保持不变
//apue p127

//osx编译时不知为何，gcc需要用-std=c89
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include"jc_err.h"

int main(int argc, char *argv[])
{
	int i,fd;
	struct stat statbuf;
	struct timespec times[2];
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
	//	printf("atime=%d\n")
		times[0].tv_sec=statbuf.st_atime;
		times[1].tv_sec=statbuf.st_mtime;
//原型int futimens(int fd,const struct timespec times[2])
		if(futimes(fd,times)<0){//书上是futimens，osx不行,只能换成futimes
			err_ret("%s: futimens error",argv[i]);
		}
		close(fd);
	}
	exit(0);
}

