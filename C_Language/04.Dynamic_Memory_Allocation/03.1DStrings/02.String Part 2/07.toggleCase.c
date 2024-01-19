// 7.Write a C program which toggles the case of a string.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, stringSize = 1;
    char* string, ch, currentChar;
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

    i = 0;
    while(*(string + i) != '\0')
    {   
        currentChar = *(string + i);

        if(currentChar >= 'A' && currentChar <= 'Z')
        {
            *(string + i) = currentChar + 32;
        }
        else if(currentChar >= 'a' && currentChar <= 'z')
        {
            *(string + i) = currentChar - 32;
        }
        
        i++;
    }
    printf("%s", string);
    free(string);
}