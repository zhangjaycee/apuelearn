/******************************
filename:ls.sh
2015 02 03    byJaycee
Email: zhjcyx@gmail.com
*******************************/

//用于实现ls的功能, Apue P4

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if(argc!=2){
		printf("Usage: %s dirname\n",argv[0]);
		exit(1);
	}
//DIR *opendir(const char *pathname)
	if((dp=opendir(argv[1]))==NULL){
		printf("can't open %s\n",argv[1]);
		exit(1);
	}
//struct dirent *readdir(DIR *dp)
	while((dirp=readdir(dp))!=NULL)
		printf("%s\n",dirp->d_name);
//int closedir(DIR *dp)
	closedir(dp);
	return 0;
}
