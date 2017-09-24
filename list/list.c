//*************************************************************************
//	> File Name: list.c
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月23日 星期日 16时13分25秒
//************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct stu {
        char dat;
        struct list_head list;

};


int main(void)
{
    struct stu *list_node = NULL;
    struct list_head *pos = NULL,*n = NULL;
    struct stu *pnode = NULL;


    struct stu *head = (struct stu *)malloc(sizeof(struct stu));
    if (head == NULL) {
        printf("file,%s line,%d:malloc error!\n",__FILE__,__LINE__);
        exit(1);
    }

    INIT_LIST_HEAD(&head->list);

    list_node = (struct stu *)malloc(sizeof(struct stu));
    
    if (list_node == NULL) {
                printf("file,%s line,%d:malloc error!\n",__FILE__,__LINE__);
                exit(1);
            
    }

    list_node->dat = 'A';

    list_for_each(pos,&head->list) {
        
        pnode = list_entry(pos, struct stu,list);
        printf("dat:%c\n",pnode->dat);
    }

    list_for_each_safe(pos,n,&head->list) {
        list_del(pos);
        //pnode = list_entry(pos,struct stu,list);
        printf("dat %c has removed from the list!\n",pnode->dat);        
    }    
    
    free(pnode);

    free(head);
    return 0;

}

