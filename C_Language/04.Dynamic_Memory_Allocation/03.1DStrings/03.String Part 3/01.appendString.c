// 1.Write a C program which accept two strings from user and append second string after first string.
#include<stdio.h>
#include<stdlib.h>

void main() 
{
    int i, size1 = 1, size2 = 1;
    char ch;
    char* string1 = NULL;
    char* string2 = NULL;

    string1 = (char*)malloc(sizeof(char));
    *(string1 + 0) = '\0';

    printf("Enter 1st String : \n");

    i = 0;
    do
    {
        scanf("%c", &ch);
        if(ch != '\n')
        {
            size1++;
            string1 = (char*)realloc(string1, size1);
            *(string1 + i) = ch;         
            *(string1 + i + 1) = '\0';         
            i++;
        }
    }while(ch != '\n');

    string2 = (char*)malloc(sizeof(char));
    *(string2 + 0) = '\0';

    printf("Enter 2st String : \n");

    i = 0;
    do
    {
        scanf("%c", &ch);
        if(ch != '\n')
        {
            size2++;
            string2 = (char*)realloc(string2, size2);
            *(string2 + i) = ch;         
            *(string2 + i + 1) = '\0';         
            i++;
        }
    }while(ch != '\n');
    
    printf("1st String Before Appending : %s\n", string1);

    size1 -= 1; // As string begins form zero idx

    i = 0;
    while(*(string2 + i) != '\0')
    {
        
        *(string1 + size1) = *(string2 + i);
        size1++;
        string1 = (char*)realloc(string1, size1);
        *(string1 + size1) = '\0';
        i++;
    }

    printf("%d", size1);
    printf("1st String After Appending : %s\n", string1);

    free(string1);
    free(string2);
}