//*************************************************************************
//	> File Name: list.h
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月23日 星期日 18时14分53秒
//************************************************************************

#ifndef _LIST_H
#define _LIST_H

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)


#ifndef container_of

#define container_of(ptr, type, member) ({          \
    consttypeof(((type *)0)->member)*__mptr = (ptr);    \
             (type *)((char *)__mptr - offsetof(type, member)); })
#endif


#undef offsetof
#ifdef __compiler_offsetof
#define offsetof(TYPE,MEMBER) __compiler_offsetof(TYPE,MEMBER)
#else
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

struct list_head {
	struct list_head *next, *prev;
};


#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
    struct list_head name = LIST_HEAD_INIT(name)


static inline void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}

static inline void __list_add(struct list_head *new,
                   struct list_head *prev,
                    struct list_head *next)
{
      next->prev = new;
      new->next = next;
      new->prev = prev;
      prev->next = new;
}

 static inline void list_add_tail(struct list_head *new, struct list_head *head)
 {
      __list_add(new, head->prev, head);
 }


#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); \
        pos = n, n = pos->next)

#define list_for_each(pos, head) \
        for (pos = (head)->next; pos->next, pos != (head); \
             pos = pos->next)

 # define POISON_POINTER_DELTA 0

#define LIST_POISON1  ((void *) 0x00100100 + POISON_POINTER_DELTA)
#define LIST_POISON2  ((void *) 0x00200200 + POISON_POINTER_DELTA)

static inline void __list_del(struct list_head * prev, struct list_head * next)
{
     next->prev = prev;
     prev->next = next;
}


static inline void list_del(struct list_head *entry)
{
     __list_del(entry->prev, entry->next);
     entry->next = LIST_POISON1;
     entry->prev = LIST_POISON2;
}


#endif
