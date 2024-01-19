// 6.Write a C program to reverse a given string.
#include<stdio.h>
#include<stdlib.h>
void main() 
{
    int i, j, size = 1;
    char* string, ch, temp;
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
    j = size - 2;
    while(i <= j)
    {
        temp = *(string + i);
        *(string + i) = *(string + j);
        *(string + j) = temp;
        i++;
        j--;
    }
    printf("Reverse String : %s\n", string);
    free(string);
}