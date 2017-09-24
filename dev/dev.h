//*************************************************************************
//	> File Name: dev.h
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月13日 星期四 21时33分57秒
//************************************************************************

#ifndef _DEV_H
#define _DEV_H

struct db_ops{

    int (*db_init) (void);
    int (*db_release) (void);

    int (*db_insert) (char *, char *, char *);
    int (*db_delete) (char *, char *, char *);
    int (*db_find) (char *, char *, char *);
    int (*db_edit) (char *, char *, char *);
};


typedef void (*DB_FIND_CB)(void*, char*, int, int);


#endif
