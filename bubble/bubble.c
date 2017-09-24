//*************************************************************************
//	> File Name: bubble.c
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月19日 星期三 21时21分55秒
//************************************************************************

#include<stdio.h>

#define SWAP(x, y) ( x=(x)+(y), y=(x)-(y), x=(x)-(y) )

void sort(char *dat, int len){
    char t;
    
    int i=0, j=0;
    if(dat==NULL){
        return;
    } 
    printf("len:%d\n", len);

    for(i=0; i<len; i++){
        for(j=len; j<i; j--){
            #if 1 
            if(dat[j] < dat[j-1]){
                printf("%d, %d", i, j);
                t=dat[j];
                dat[j] = dat[j-1];
                dat[j-1] = t;
            }
            #endif

            printf("for1==%d, %d\n", i, j);
        }
        printf("for==%d, %d\n", i, j);
    }

}

int main(int argc, char *argv[]) {
    
    //int a=12, b=13;

    //SWAP(a, b);

    //printf("%d, %d\n", a, b);

    int i;
    char data[]={1, 2, 4, 1, 3, 8};
    int len = sizeof(data);

    sort(data, len);

    for(i=0; i<len; i++){
        printf("%d\n", data[i]);
    }

    return 0;
}
