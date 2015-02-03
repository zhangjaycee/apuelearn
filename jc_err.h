/**********************************
** filename: jc_err.h
** time: 2015 02 03   byJaycee
** Email: zhjcyx@gmail.com
**********************************/

#include<stdio.h>
#include<stdarg.h>//可变参数的头文件
void error(const char *fmt,...)
{
	va_list ptr;//va_list 实际是
	va_start(ptr,fmt);//第二个参数是"..."前面的最后一个参数
	
	
}
