// 3.Write a C program to print count number of characters in given string.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, size = 1, charCount = 0;
    char* string = NULL, ch;
    string = (char*)malloc(sizeof(char));
    *(string + 0) = '\0';
    printf("Enter String : \n");
    
    i = 0;
    do
    {
        scanf("%c", &ch);
        if(ch != '\n')
        {
            size++;
            string = (char*)realloc(string, size);
            *(string + i) = ch;
            *(string + i + 1) = '\0';
            i++;
        }
    }while(ch != '\n');
    
    i = 0;
    while(*(string + i) != '\0')
    {
        while(*(string + i) == ' ')
        {
            i++;
        }
        while(*(string + i) != ' ' && *(string + i) != '\0')
        {
            charCount++;
            i++;
        }
    }
    printf("Total Characters In Given String : %d", charCount);
    free(string);
}