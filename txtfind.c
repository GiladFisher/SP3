#include <stdio.h>
#include <string.h>
#define WORD 30

int getword(char w[]){
    int len = 0;
    char *cp = w;
    while(*cp){
        printf("%c\n", *cp);
        if((*cp == '\n') || (*cp == '\t') || (*cp == ' ')){
            break;
        }
        cp = (cp + 1);
        len++;
    }
    return len;
}

int main(){
    char st[WORD];
    scanf("%s",st);
    int w_len = 0;
    w_len = getword(st);
    printf("%d\n",w_len);
    return 0;
}