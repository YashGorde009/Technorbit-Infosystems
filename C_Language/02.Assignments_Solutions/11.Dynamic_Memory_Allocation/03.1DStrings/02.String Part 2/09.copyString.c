// 9.Write a C program which accept string from user and copy that string into some another string.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, stringSize = 1;
    char* sourceString, * destinationString, ch;
    sourceString = (char*)malloc(sizeof(char));
    *(sourceString + 0) =  '\0';
    printf("Enter String : \n");

    i = 0;
    do
    {   
        scanf("%c", &ch);
        if(ch != '\n')
        {
            stringSize++;
            sourceString = (char*)realloc(sourceString , stringSize);
            *(sourceString + i) = ch;
            *(sourceString + i + 1) = '\0';
            i++;
        }
    }while(ch != '\n');

    destinationString = (char*)malloc(stringSize);

    *(destinationString + stringSize - 1) = '\0';

    i = 0;
    while(*(sourceString + i) != '\0')
    {
        *(destinationString + i) = *(sourceString + i);
        i++;
    }
    
    printf("%s", destinationString);

    free(sourceString);
    free(destinationString);
}