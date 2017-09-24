//*************************************************************************
//	> File Name: test.c
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月30日 星期日 21时30分50秒
//************************************************************************

#include<stdio.h>

int fun(int i, int j,  char p='*'){
    printf("%d %d %c\n", i, j, p);
}

int main(int argc, char *argv[]) {
    fun(10, 12, '%');
    return 0;
}
