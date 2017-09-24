//*************************************************************************
//	> File Name: linkNode.c
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月23日 星期日 19时01分42秒
//************************************************************************

#include<stdio.h>

typedef struct linkNode{
    int dat;
    struct linkNode *next;
}LinkNode;

int find(LinkNode *top){
    LinkNode *flag, *move;

    int count=1;

    flag=move=top;

    while(move->next != flag){
        count++;
        move = move->next;
    }

    return count;
}

int main(int argc, char *argv[]) {
    LinkNode d1;
    LinkNode d2;
    LinkNode d3;
    

    d1.dat=1;
    d2.dat=2;
    d3.dat=4;

    d1.next=&d2;
    d2.next=&d3;
    d3.next=&d1;
    
    printf("%d\n", find(&d1));


    return 0;
}
