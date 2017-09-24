//*************************************************************************
//	> File Name: continumax.c
//	> Author: lizhiduo 
//	> Mail: lizhiduo@aliyun.com 
//	> Created Time: 2017年07月16日 星期日 21时29分19秒
//************************************************************************

#include<stdio.h>
#include <string.h>

int Continumax(char* pOutputstr,  char* intputstr){
    
    int len = strlen(intputstr);
    char *tmp=NULL, *out;
    char flag=1;
    int tmplen=0, maxlen=0;


    if(intputstr==NULL && len == 0){
        pOutputstr=NULL;
        return 0;
    }
    
    while(*intputstr != '\0'){
        if(*intputstr>='0' && *intputstr<='9'){
            if(flag){
                tmp = intputstr;
                flag=0;
                //printf("0x%x\n", intputstr);
            }
            tmplen++;
        }else{
            if(maxlen<tmplen){
                maxlen=tmplen;
                printf("%d\n", tmplen);
                out = tmp;
            }
            tmplen=0;
            tmp=NULL;
            flag=1;
        }
        intputstr++;
    }
    
    strncpy(pOutputstr, out, maxlen);
    pOutputstr[maxlen]='\0';

    return maxlen;
}

int main(int argc, char *argv[]) {
    
    char outstr[1024];
    char instr[]="11111111111111111111234ddd12123435f";

    Continumax(outstr, instr);

    printf("%s\n", outstr);

    return 0;
}
