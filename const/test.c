//*************************************************************************
//	> File Name: test.c
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月23日 星期日 10时37分51秒
//************************************************************************

#include<stdio.h>



int main(int argc, char *argv[]) {
    
    const char *str="lzd";
    char const *str1="lizhiduo";
    
    
    char dat[10]="hello";
    
    char * const str2=dat;//指针常量
    
    //const (char *) p;
    //str2 = dat;

    //str=dat;
    //*(str+1)='d';
    //*(str1+1)='d';

    printf("%s\n", str2);


    return 0;
}
