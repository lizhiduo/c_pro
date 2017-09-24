//*************************************************************************
//	> File Name: reverse.c
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月23日 星期日 19时14分51秒
//************************************************************************

#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char const *str, char **retStr){
    int strLen = strlen(str);
    char tmp;
    int i;

    *retStr = (char *)malloc(strLen+1);

    strcpy(*retStr, str);

    for(i=0; i<strLen/2; ++i){
        tmp = (*retStr)[i];
       (*retStr)[i] = (*retStr)[strLen-i-1];
        (*retStr)[strLen - i -1] = tmp;
    }

}

int main(int argc, char *argv[]) {
    
    char *ret=NULL;
    //char *data="123456";
    char data[]="123456789";


    reverse(data, &ret);

    printf("%s\n", ret);

    free(ret);


    return 0;
}
