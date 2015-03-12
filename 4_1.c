/**********************************
** filename: 4_1.c 
** time: 2015 3 12    byJaycee
** Email: zhjcyx@gmail.com
**********************************/
//p140 图4-3 和第四章练习一的结合
#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include"jc_err.h"
void judgeType(const struct stat * buf)
{
	char * ptr;
	mode_t tmp=buf->st_mode;
	if(S_ISREG(tmp))
		ptr="regular";
	else if(S_ISDIR(tmp))
		ptr="dictionary";
	else if(S_ISCHR(tmp))
		ptr="character special";
	else if(S_ISBLK(tmp))
		ptr="block special";
	else if(S_ISFIFO(tmp))
		ptr="fifo";
	else if(S_ISLNK(tmp))
		ptr="symbolic link";
	else if(S_ISSOCK(tmp))
		ptr="socket";
	else
		ptr="**unknown mode**";
	printf("%s\n",ptr);
}

int main(int argc,char *argv[])
{
	int i;
	struct stat buf;
	int (*myStat)(const char *,struct stat *);
	if(strcmp(argv[1],"stat")==0){
		myStat=&stat;
	}else if(strcmp(argv[1],"lstat")==0){
		myStat=&lstat;
	}else{
		err_sys("usage:%s [lstat/stat] ...",argv[0]);
	}
	for(i=2;argv[i]!=NULL;i++){
		printf("%s: ",argv[i]);
		if(myStat(argv[i],&buf)<0){
			err_ret("lstat error");
			continue;
		}
		judgeType(&buf);
	}
}


