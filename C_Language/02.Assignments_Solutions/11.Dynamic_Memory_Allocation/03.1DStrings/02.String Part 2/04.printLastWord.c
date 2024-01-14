// 4.Write a C program which accept sentence from user and print last word from that sentence.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, stringSize = 1;
    char* string, ch;
    string = (char*)malloc(sizeof(char));
    *(string + 0) =  '\0';
    printf("Enter String : \n");

    i = 0;
    do
    {   
        scanf("%c", &ch);
        if(ch != '\n')
        {
            stringSize++;
            string = (char*)realloc(string , stringSize);
            *(string + i) = ch;
            *(string + i + 1) = '\0';
            i++;
        }
    }while(ch != '\n');

    i = stringSize - 2;
    while(i > 0 && *(string + i - 1) != ' ')  
    {
        i--;
    }
    while(*(string + i) != '\0')
    {
        printf("%c", *(string + i));
        i++;
    }
    free(string);
}