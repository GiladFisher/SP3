#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORD 30

int getword(char w[]){
    int len = 0;
    char *cp = w;
    while(*cp){
        if((*cp == '\n') || (*cp == '\t') || (*cp == ' ')){
            break;
        }
        cp = (cp + 1);
        len++;
    }
    return len;
}

// the next method will return 1 if it is possible to get str1 by removing at most one char from str2
int similar(char *str1, char *str2){
    int wrng_chrs = 0; // will contain the number of chars not consistant with str1
    char *p1 = str1;
    char *p2 = str2;
    while(1){
        if (!*p1){
            if(*p2){
                p2 = (p2 + 1);
                wrng_chrs++;
            }
            else{
                break;
            }
        }
        else if(!*p2){
            return 0;
        }
        else if (*p1 != *p2){
            wrng_chrs++;
            p2 = (p2 + 1);
        }
        else{
            p2 = (p2 + 1);
            p1 = (p1 + 1);
        }
    }
    if(wrng_chrs > 1){
        return 0;
    }
    return 1;
}

// the next method will get a string pointer nstr the size of w_len+1
// and will copy the first w_len chars in ogstr followed by '\0'
void copyword(char *nstr, char *ogstr, int w_len){
    for (int i = 0; i < w_len; i++){
        *(nstr + i) = *(ogstr + i);
    }
    *(nstr + w_len) = '\0';
}

void print_similaar_words(char *word, char *txt){
    char *txtp = txt;
    while (*txtp)
    {
        int w_len = getword(txtp);
        char curr_w[WORD];
        copyword(curr_w, txtp, w_len);
        printf("current word:  %s.\n", curr_w);
        if( similar(word, curr_w)){
            printf("%s\n",curr_w);
        }
        txtp = (txtp + w_len + 1);
        if ( (*txtp == '\n') || (*txtp == '\t') || (*txtp == ' ')){
            txtp = (txtp + 1);
        }
        printf("current txt:  %d \n", w_len);       
    }
    


}

int main(){
    char st[WORD];
    char st2[WORD];
    scanf("%s",st);
    scanf("%s",st2);

    // int w_len = 0;
    // w_len = getword(st);

    // int ans = -1;
    // ans = similar(st, st2);

    // int w_len = 3;

    print_similaar_words(st, st2);
    // printf("%s\n",st);

    return 0;
}