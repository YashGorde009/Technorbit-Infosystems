// 1.Write a C program to accept string with multiple spaces from user and print as it is.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, size = 1;
    char* string = NULL, ch;
    string = (char*)malloc(sizeof(char));
    *(string + 0) = '\0';
    printf("Enter string : \n");

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

    printf("%s", string);
    free(string);
}