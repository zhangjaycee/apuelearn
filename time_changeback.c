/********************************
filename: time_changeback.c
20150203   byJaycee
Email: zhjcyx@gmail.com
*********************************/

//目的是将文件长度截断为0，并将访问时间和修改时间改回阶段前，使其保持不变

#include<stdio.h>
#include<sys/stat.h>
#include"jc_err.h"

int main(int argc, char *argv[])
{
	if(argc!=2){
		error("Usage: %s filename",argv[0])
	}
	
}



