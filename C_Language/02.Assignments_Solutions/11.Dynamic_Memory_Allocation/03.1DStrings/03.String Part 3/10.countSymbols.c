// 10.Write a C program to count number of alphabets, spaces and words in given string.
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i, size = 1, alphaCount = 0, spaceCount = 0, wordCount = 0;
    char ch;
    char* string = NULL; 

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
        ch = *(string + i);

        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            alphaCount++;
        }

        if(ch != ' ' && *(string + i + 1) == ' ' || *(string + i + 1) == '\0')
        {
            wordCount++;
        }
        
        if(ch == ' ')
        {
            spaceCount++;
        }
        i++;
    }
    printf("Alphabet : %d  Word : %d  Space : %d\n", alphaCount, wordCount, spaceCount);
    free(string);   
}