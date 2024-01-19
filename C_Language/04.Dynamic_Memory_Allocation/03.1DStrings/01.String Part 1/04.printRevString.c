// 4.Write a C program to accept string and print it in the reverse order.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, size = 1;
    char* string = NULL, ch;
    string = (char*)malloc(sizeof(char));
    *(string) = '\0';

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

    i = size - 2;
    while(i >= 0)    
    {
        while(i>= 0 && *(string + i) != ' ')
        {
            printf("%c", *(string + i));
            if(i > 0 && *(string + i - 1) == ' ')
            {
                printf(" ");
            }
            i--;
        }
        while(*(string + i) == ' ')
        {
            i--;
        }
    }
    free(string);
}