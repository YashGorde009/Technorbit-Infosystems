// 2.Write a C program to accept string with multiple spaces from user and print it with a single space as a delimiter
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, size = 1;
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
        // skips spaces
        while(*(string + i) == ' ')
        {
            i++;
        }
        
        while(*(string + i) != ' ' && *(string + i) != '\0')
        {
            printf("%c", *(string + i));
            // prints 1 space
            if(*(string + i + 1) == ' ')
            {
                printf(" ");
            }
            i++;
        }

    }
    free(string);
}