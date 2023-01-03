#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LINE = 256;
int WORD = 30;

int getLine(char *line);
int getWord(char *word);
int similar(char *word, char *str);

int main()
{
    // Saving the word we want to test with in the text.

    char str[WORD];                         
    memset(str, 0, WORD);
    int strsize = getWord(str);          
    if(strsize == -1) { return -1; }

    int counter = strsize;         // Creating a counter that saves the current position in the file byte-wise.

    // Saving the chosen option ( a / b ).

    char ch[2] = {0};                       

    int chlen = getWord(ch);
    if (chlen == -1) { return -1; }

    counter += chlen;

    // OPTION A : prints all the lines that contain the string stored in str[]

    if ( strcmp(ch,"a") == 0 )
    {
        memset(ch,0,2);
        chlen = getWord(ch);
        if (chlen == -1) { return -1; }

        counter += chlen;

        char line[LINE];
        memset(line,0,LINE);

        int temp = 0;

        while (counter < size)
        {
            temp = getLine(line, fp);

            if( strstr(line,str) != NULL ) { printf("%s",line); } 
            
            memset(line,0,LINE);
            counter += temp;
        } 
    }


    // OPTION B : print all the words that have a difference of up to 1 char from the string stored in str[] 

    if ( strcmp(ch,"b") == 0)
    {      
        memset(ch,0,2);
        chlen = getWord(ch,fp);
        if (chlen == -1) { return -1; }

        counter += chlen;
        
        char word[WORD];
        memset(word,0,WORD);

        int temp = 0;

        while (counter < size)
        {
            
            temp = getWord(word, fp);

            if( similar(word,str) == 1 ) { printf("%s\n", word); } 
            
            memset(word,0,WORD);
            counter += temp;
        }
    }
}


// ## THE FUNCTIONS: ##

// getLine() - inserting into a buffer the word from the file that starts at the file pointer.

int getLine(char *line)
{
    int count = 0;

    while(1)
    {
        char c = getchar();

        if(count == LINE-2 && c != '\n')
        {
            printf("Invalid string given in txt file");
            return -1;
        }

        line[count] = c;

        if (line[count] == '\n') 
        { 
            line[++count] = '\0';
            break; 
        }
        count++;
    }

    return count;
}


// getWord() - inserting into a buffer the word from the file that starts at the file pointer.

int getWord(char *word)
{
    int count = 0;

    while(1)
    {
        char c = getchar();

        if(count == WORD-1 && (( c != '\t' || c != ' ')  || c != '\n'))
        {
            printf("Invalid word given in txt file");

            return -1;
        }
        
        if ((word[count] == ' ' || word[count] == '\t') || word[count] == '\n') 
        { 
            word[count] = '\0';
            count++;
            break; 
        }

        count++;
    }
    return count;
}


// Similar words mean that the only difference between them is up to 1 extra letter in word[]

int similar(char *word, char *str)
{
    int flag = 0;
    int wlen = strlen(word);
    int slen = strlen(str);
    
    int ind1 = 0;
    int ind2 = 0;

    if ( wlen - slen > 1 || wlen - slen < 0) { return 0; }

    while( (flag < 2 && ind1 < wlen) && ind2 < slen )
    {
        if( word[ind1] != str[ind2] ) 
        { 
            flag++; 
            ind1++;
        }
        
        else
        {
            ind1++;
            ind2++;
        }
    }

    if(flag == 2) { return 0; }
    else          { return 1; }
}