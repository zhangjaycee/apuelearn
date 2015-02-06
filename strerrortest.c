#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main()
{
	int i;
	for(i=0;i<200;i++)
		printf("errno %d: %s\n",i,strerror(i));
	return 0;
}
