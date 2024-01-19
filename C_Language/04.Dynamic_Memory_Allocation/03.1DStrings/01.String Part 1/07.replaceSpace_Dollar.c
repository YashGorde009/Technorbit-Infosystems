// 7.Write a C program to replace space with ‘$’ in given string.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, size = 1;
    char* string, ch;
    string = (char*)malloc(sizeof(char));
    *(string + 0) = '\0';
    printf("Enter String :\n");

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
        if(*(string + i) == ' ')
        {
            *(string + i) = '$';
        }
        i++;
    }
    printf("%s", string);
    free(string);
}