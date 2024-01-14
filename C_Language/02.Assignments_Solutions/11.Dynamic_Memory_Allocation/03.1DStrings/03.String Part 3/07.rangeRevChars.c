// 7.Write a C program which accept string from user and then accept range and reverse the string in that range without taking another string.
#include<stdio.h>
#include<stdlib.h>
void main()     
{
    int i, j, size = 1, startRange, endRange;
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

    printf("Enter Start of Range : \n");
    scanf("%d", &startRange);

    printf("Enter End of Range : \n");
    scanf("%d", &endRange);

    i = startRange;
    j = endRange; // Indm si aicountry
    while(i <= j)
    {
        temp = *(string + i);
        *(string + i) = *(string + j);
        *(string + j) = temp;
        i++;
        j--;
    }

    printf("%s", string);

    free(string);
}