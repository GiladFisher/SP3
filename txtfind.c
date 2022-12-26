#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORD 30
#define LINE 256

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
    *(nstr + w_len) = 0;
}

void print_similar_words(char *word, char *txt){
    int word_len = getword(word);
    copyword(word, word, word_len);
    while (*txt)
    {
        int w_len = getword(txt);
        char *nstr = (char *)malloc((w_len + 1) * sizeof(char));
        copyword(nstr, txt, w_len);
        if (similar(word, nstr)){
            printf("similar: %s\n", nstr);
        }
        txt = (char*)(txt + w_len +1);
        if(nstr){
            free(nstr);
        }
    }
}

int readlines(){
    char temp = 'a';
    while(1){
        char *line = (char*)malloc(sizeof(char)*LINE);
        int i = 0;
        while(1){

            scanf("%c", line + i);
            temp = line[i];
            if(temp == '\n'){
                line[i] = '\0';
                break;
            }
            if(temp == '\0'){
                line[i] = '\0';
                printf("ended on a 0\n");
                break;
            }
            i++;
        }
        printf("%s\n", line);
        /*
            here, we will use a future function to determain if the line
            containes the first word or not        
        */
        if (temp == '\0'){
            break;
        }
        if(line){
            free(line);
        }
    }    
    return 0;
}

int main(){
// save the first word
// save the insctruction char 

//   for the rest of the input:

// case a, print_similar_words
// case b, readlines



// -------- tests
    char st[WORD];
    // char st2[WORD];
    // fgets(st, WORD, stdin);
    // fgets(st2, WORD, stdin);
    // print_similar_words(st, st2);
    readlines(st);
    return 0;
}