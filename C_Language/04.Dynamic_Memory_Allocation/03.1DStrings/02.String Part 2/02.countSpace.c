// 2.Write a C program which accept sentence from user and print number of white spaces from that sentence.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, size = 1, spaceCount = 0;
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
            size++;
            string = (char*)realloc(string , size);
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
            spaceCount++;
        }
        i++;
    }
    printf("Space Count : %d\n", spaceCount);
    free(string);
}