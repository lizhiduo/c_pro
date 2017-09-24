//*************************************************************************
//	> File Name: testchar.c
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月23日 星期日 20时47分18秒
//************************************************************************

#include<stdio.h>

int main(int argc, char *argv[]) {
    
    char * p1 = "hello";
    char * p2 = "hello";
    char * p3 = "hello";
    
    printf("%x, %x, %x", p1, p2, p3);
    
    //*(p1+1) = 1;  //p1是指向字符串常量，其值不能改变。

    return 0;
}
