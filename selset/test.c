//*************************************************************************
//	> File Name: test.c
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月23日 星期日 21时37分52秒
//************************************************************************
#include <sys/types.h> 
#include <sys/time.h> 
#include <stdio.h> 
#include <fcntl.h> 
#include <sys/ioctl.h> 
#include <unistd.h> 

int main() 
{ 
    char buffer[128]; 
    int result, nread; 
    fd_set inputs, testfds; 
    struct timeval timeout; 
    
	FD_ZERO(&inputs);//用select函数之前先把集合清零
	FD_SET(0,&inputs);//把要检测的句柄——标准输入（0），加入到集合里。
     while(1) 
    { 
       testfds = inputs; 
       timeout.tv_sec = 2; 
       timeout.tv_usec = 500*1000;//500ms 
       result = select(FD_SETSIZE, &testfds, (fd_set *)0, (fd_set *)0, &timeout); 
       switch(result) 
       { 
       case 0: 
           printf("timeout\n"); 
	       break;
	   case -1: 
           perror("select\n"); 
           return 1; 
       default: 
           if(FD_ISSET(0,&testfds)) 
           { 
               ioctl(0,FIONREAD,&nread);//取得从键盘输入字符的个数，包括回车。 
               if(nread == 0) 
               { 
                  printf("keyboard done\n"); 
                  return 0; 
               } 
               nread = read(0,buffer,nread); 
               buffer[nread] = 0; 
               printf("read %d from keyboard: %s", nread, buffer); 
         } 
         break; 
      } 
   } 
   return 0;
}

