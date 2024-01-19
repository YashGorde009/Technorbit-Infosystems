// 9.Write a C program which accept string from user and check whether string is palindrome or not.
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i, j, size = 1, flag = 0;
    char ch;
    char* string = NULL;
    char* revString = NULL;

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
        if(ch >= 'A' && ch <= 'Z')
        {
            *(string + i) += 32; // to lowercase
        }
        i++;
    }

    revString = (char*)malloc(size * sizeof(char));
    i = 0;
    j = size - 2;
    while(j >= 0)
    {
        *(revString + i) = *(string + j);
        *(revString + i + 1) = '\0';
        i++;
        j--;
    }
    
    i = 0;
    while(*(string + i) != '\0' && *(revString + i) != '\0')
    {
        if(*(string + i) != *(revString + i))
        {
            printf("String '%s' is not palindrome\n", string);
            flag = 1;
            break;
        }
        i++;
    }
    if(flag != 1)
    {
        printf("String '%s' is palindrome\n", string);
    }
    free(string);
    free(revString);
}

