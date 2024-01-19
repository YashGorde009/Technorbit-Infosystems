// 10.Write a program which accept string from user and copy first N charaters into some destination string.

#include<stdio.h>
#include<stdlib.h>

void main() 
{
    int i, size = 1, nChar; // N_Character(nChar)
    char ch;
    char* str = NULL; // string(str)
    char* dStr = NULL; // destinationString(dStr)

    str = (char*)malloc(sizeof(char));
    *(str + 0) = '\0';

    printf("Enter String : \n");
    
    i = 0;
    do
    {
        scanf("%c", &ch);
        if(ch != '\n')

        {
            size++;
            str = (char*)realloc(str, size);
            *(str + i) = ch;
            *(str + i + 1) = '\0';
            i++;
        }

    }while(ch != '\n');

    printf("Enter How Characters Do You Want To Copy From Above String Into Destination String : \n");
    scanf("%d", &nChar);

    dStr = (char*)malloc((nChar + 1) * sizeof(char));
    *(dStr + 0) = '\0';
    i = 0;
    while(i < nChar)
    {
        *(dStr + i) = *(str + i);
        *(dStr + i + 1) = '\0';
        i++;
    }
    printf("Destination String : %s\n", dStr);
    
    free(str);
    free(dStr);
}