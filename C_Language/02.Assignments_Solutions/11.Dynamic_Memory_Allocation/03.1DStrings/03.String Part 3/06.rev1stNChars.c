// 6.Write a C program which accept string from user and then reverse the string till first N characters without taking another string.
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i, j, size = 1, nChar;
    char ch, temp;
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

    printf("Enter Characters To Be Reversed : \n");
    scanf("%d", &nChar);

    i = 0;
    j = nChar - 1;
    while(i <= j)
    {
        temp = *(string + i);
        *(string + i) = *(string + j);
        *(string + j) = temp;
        i++;
        j--;
    }

    printf("%s\n", string);

    free(string);
}