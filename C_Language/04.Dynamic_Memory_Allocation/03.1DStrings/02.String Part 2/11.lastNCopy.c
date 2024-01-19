// 11.Write a C program which accept string from user and accept number N then copy last N character into some another string.

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i, j, size = 1, nChar; 
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

    printf("How Many Characters Do You Want To Copy From Last Of The Above String : \n");
    scanf("%d", &nChar);

    dStr = (char*)malloc((nChar + 1) * sizeof(char));

    i = 0;
    while(i <= nChar)
    {
        size--;  // getting target index 
        i++;
    }

    i = 0;
    while(i < nChar)
    {
        *(dStr + i) = *(str + size);
        *(dStr + i + 1) = '\0';
        size++;
        i++;
    }

    printf("Destination String : %s\n", dStr);
}