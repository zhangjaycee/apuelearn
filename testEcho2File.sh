#!/bin/sh
TIME=$(date +%y-%m-%d-%H:%M)
touch $1
echo "/********************************************" 1>$1
echo "* Filename:$1*" 1>>$1
echo "* Time:$TIME By:Jaycee  *" 1>>$1
echo "* Email:zhjcyx@gmail.com                    *" 1>>$1
echo '********************************************/' 1>>$1
vim $1
